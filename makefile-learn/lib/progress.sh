#!/bin/sh

_progress_file() {
    printf '%s/progress.json' "$LEARN_ROOT"
}

progress_init() {
    if [ ! -f "$(_progress_file)" ]; then
        cat > "$(_progress_file)" <<'EOF'
{
  "current_phase": 1,
  "current_exercise": 1,
  "completed": {
    "1": [],
    "2": [],
    "3": [],
    "4": [],
    "5": []
  },
  "hints_used": {},
  "explain_unlocked": {}
}
EOF
    fi
}

progress_get_phase() {
    grep '"current_phase"' "$(_progress_file)" | grep -o '[0-9]*'
}

progress_get_exercise() {
    grep '"current_exercise"' "$(_progress_file)" | grep -o '[0-9]*'
}

progress_set_current() {
    # $1 = phase, $2 = exercise
    N="$1"
    M="$2"
    FILE="$(_progress_file)"

    # Read current state
    COMP1=$(grep '"1":' "$FILE" | grep -v '"completed"' | sed 's/.*"1": *\[\([^]]*\)\].*/\1/')
    COMP2=$(grep '"2":' "$FILE" | grep -v '"completed"' | sed 's/.*"2": *\[\([^]]*\)\].*/\1/')
    COMP3=$(grep '"3":' "$FILE" | grep -v '"completed"' | sed 's/.*"3": *\[\([^]]*\)\].*/\1/')
    COMP4=$(grep '"4":' "$FILE" | grep -v '"completed"' | sed 's/.*"4": *\[\([^]]*\)\].*/\1/')
    COMP5=$(grep '"5":' "$FILE" | grep -v '"completed"' | sed 's/.*"5": *\[\([^]]*\)\].*/\1/')

    HINTS=$(_read_hints "$FILE")
    EXPLAINS=$(_read_explains "$FILE")

    _write_json "$N" "$M" "$COMP1" "$COMP2" "$COMP3" "$COMP4" "$COMP5" "$HINTS" "$EXPLAINS"
}

_read_completed_array() {
    # $1 = file, $2 = phase number
    # Extract array content for phase $2 from completed block
    grep "\"$2\":" "$1" | grep -v '"completed"' | sed 's/.*\[//; s/\].*//' | tr -d ' '
}

_read_hints() {
    # Print hints_used block content (between { and })
    # Handles both single-line {} and multi-line format
    awk '
        /"hints_used"/ {
            if (match($0, /\{[[:space:]]*\}/)) exit
            in_block=1; next
        }
        in_block && /\}/ { exit }
        in_block { print }
    ' "$1" | sed '/^[[:space:]]*$/d'
}

_read_explains() {
    awk '
        /"explain_unlocked"/ {
            if (match($0, /\{[[:space:]]*\}/)) exit
            in_block=1; next
        }
        in_block && /\}/ { exit }
        in_block { print }
    ' "$1" | sed '/^[[:space:]]*$/d'
}

_write_json() {
    # $1=phase $2=exercise $3..7=comp arrays 1-5 $8=hints_block $9=explains_block
    N="$1"; M="$2"
    C1="$3"; C2="$4"; C3="$5"; C4="$6"; C5="$7"
    HINTS="$8"; EXPLAINS="$9"
    FILE="$(_progress_file)"
    TMP="${FILE}.tmp.$$"

    printf '{\n' > "$TMP"
    printf '  "current_phase": %s,\n' "$N" >> "$TMP"
    printf '  "current_exercise": %s,\n' "$M" >> "$TMP"
    printf '  "completed": {\n' >> "$TMP"
    printf '    "1": [%s],\n' "$C1" >> "$TMP"
    printf '    "2": [%s],\n' "$C2" >> "$TMP"
    printf '    "3": [%s],\n' "$C3" >> "$TMP"
    printf '    "4": [%s],\n' "$C4" >> "$TMP"
    printf '    "5": [%s]\n'  "$C5" >> "$TMP"
    printf '  },\n' >> "$TMP"
    if [ -n "$HINTS" ]; then
        printf '  "hints_used": {\n' >> "$TMP"
        printf '%s\n' "$HINTS" >> "$TMP"
        printf '  },\n' >> "$TMP"
    else
        printf '  "hints_used": {},\n' >> "$TMP"
    fi
    if [ -n "$EXPLAINS" ]; then
        printf '  "explain_unlocked": {\n' >> "$TMP"
        printf '%s\n' "$EXPLAINS" >> "$TMP"
        printf '  }\n' >> "$TMP"
    else
        printf '  "explain_unlocked": {}\n' >> "$TMP"
    fi
    printf '}\n' >> "$TMP"

    mv "$TMP" "$FILE"
}

progress_mark_done() {
    # $1 = phase, $2 = exercise
    N="$1"; M="$2"
    FILE="$(_progress_file)"

    # Already done?
    if progress_is_done "$N" "$M"; then
        return
    fi

    CUR_PHASE=$(progress_get_phase)
    CUR_EX=$(progress_get_exercise)

    C1=$(_read_completed_array "$FILE" "1")
    C2=$(_read_completed_array "$FILE" "2")
    C3=$(_read_completed_array "$FILE" "3")
    C4=$(_read_completed_array "$FILE" "4")
    C5=$(_read_completed_array "$FILE" "5")

    # Append M to the array for phase N
    eval "OLD=\$C$N"
    if [ -z "$OLD" ]; then
        NEW="$M"
    else
        NEW="$OLD, $M"
    fi
    eval "C$N=\"\$NEW\""

    HINTS=$(_read_hints "$FILE")
    EXPLAINS=$(_read_explains "$FILE")

    _write_json "$CUR_PHASE" "$CUR_EX" "$C1" "$C2" "$C3" "$C4" "$C5" "$HINTS" "$EXPLAINS"
}

progress_is_done() {
    # $1 = phase, $2 = exercise; returns 0 if done
    N="$1"; M="$2"
    FILE="$(_progress_file)"
    ARR=$(_read_completed_array "$FILE" "$N")
    # Check if M is in the comma-separated list
    for val in $(printf '%s' "$ARR" | tr ',' ' '); do
        val=$(printf '%s' "$val" | tr -d ' ')
        if [ "$val" = "$M" ]; then
            return 0
        fi
    done
    return 1
}

progress_get_hints() {
    # $1 = phase, $2 = exercise; prints count
    N="$1"; M="$2"
    KEY="${N}-${M}"
    FILE="$(_progress_file)"
    VAL=$(awk -v key="\"$KEY\"" '
        /"hints_used"/{found=1; next}
        found && /\}/ {exit}
        found {
            if (index($0, key) > 0) {
                # Extract value after the colon (not from the key itself)
                sub(/.*:/, "")
                gsub(/[^0-9]/, "")
                print
                exit
            }
        }
    ' "$FILE")
    if [ -z "$VAL" ]; then
        printf '0'
    else
        printf '%s' "$VAL"
    fi
}

progress_inc_hint() {
    # $1 = phase, $2 = exercise
    N="$1"; M="$2"
    KEY="${N}-${M}"
    FILE="$(_progress_file)"

    CUR=$(progress_get_hints "$N" "$M")
    NEW=$((CUR + 1))

    CUR_PHASE=$(progress_get_phase)
    CUR_EX=$(progress_get_exercise)
    C1=$(_read_completed_array "$FILE" "1")
    C2=$(_read_completed_array "$FILE" "2")
    C3=$(_read_completed_array "$FILE" "3")
    C4=$(_read_completed_array "$FILE" "4")
    C5=$(_read_completed_array "$FILE" "5")
    EXPLAINS=$(_read_explains "$FILE")

    # Rebuild hints block with updated key
    OLD_HINTS=$(_read_hints "$FILE")
    if [ -z "$OLD_HINTS" ]; then
        NEW_HINTS="    \"$KEY\": $NEW"
    elif printf '%s' "$OLD_HINTS" | grep -q "\"$KEY\""; then
        NEW_HINTS=$(printf '%s' "$OLD_HINTS" | sed "s/\"$KEY\": *[0-9]*/\"$KEY\": $NEW/")
    else
        NEW_HINTS=$(printf '%s,\n    "%s": %s' "$OLD_HINTS" "$KEY" "$NEW")
    fi

    _write_json "$CUR_PHASE" "$CUR_EX" "$C1" "$C2" "$C3" "$C4" "$C5" "$NEW_HINTS" "$EXPLAINS"
}

progress_unlock_explain() {
    # $1 = phase, $2 = exercise
    N="$1"; M="$2"
    KEY="${N}-${M}"
    FILE="$(_progress_file)"

    if progress_can_explain "$N" "$M"; then
        return
    fi

    CUR_PHASE=$(progress_get_phase)
    CUR_EX=$(progress_get_exercise)
    C1=$(_read_completed_array "$FILE" "1")
    C2=$(_read_completed_array "$FILE" "2")
    C3=$(_read_completed_array "$FILE" "3")
    C4=$(_read_completed_array "$FILE" "4")
    C5=$(_read_completed_array "$FILE" "5")
    HINTS=$(_read_hints "$FILE")

    OLD_EXPLAINS=$(_read_explains "$FILE")
    if [ -z "$OLD_EXPLAINS" ]; then
        NEW_EXPLAINS="    \"$KEY\": true"
    else
        NEW_EXPLAINS=$(printf '%s,\n    "%s": true' "$OLD_EXPLAINS" "$KEY")
    fi

    _write_json "$CUR_PHASE" "$CUR_EX" "$C1" "$C2" "$C3" "$C4" "$C5" "$HINTS" "$NEW_EXPLAINS"
}

progress_can_explain() {
    # $1 = phase, $2 = exercise; returns 0 if unlocked
    N="$1"; M="$2"
    KEY="${N}-${M}"
    FILE="$(_progress_file)"
    grep -q "\"$KEY\"" "$FILE" 2>/dev/null && \
        sed -n '/"explain_unlocked"/,/}/p' "$FILE" | grep -q "\"$KEY\""
}

progress_count_done() {
    # $1 = phase; prints how many exercises are completed
    N="$1"
    FILE="$(_progress_file)"
    ARR=$(_read_completed_array "$FILE" "$N")
    if [ -z "$ARR" ]; then
        printf '0'
        return
    fi
    COUNT=$(printf '%s' "$ARR" | tr ',' '\n' | grep -c '[0-9]')
    printf '%s' "$COUNT"
}
