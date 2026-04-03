#!/bin/sh
# check.sh — motor de validação do makefile-learn
# Invocado por `learn check` com variáveis LEARN_* exportadas

if [ -z "$LEARN_EX_DIR" ]; then
    printf "check.sh: LEARN_EX_DIR não definido. Use ./learn check.\n" >&2
    exit 1
fi

. "$LEARN_ROOT/lib/progress.sh"

PHASE="$LEARN_PHASE"
EX="$LEARN_EXERCISE"
EX_DIR="$LEARN_EX_DIR"

# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

_ok()   { printf "${GREEN}[✓]${RESET} %s\n" "$1"; }
_err()  { printf "${RED}[✗]${RESET} %s\n" "$1"; }
_info() { printf "${BLUE}[i]${RESET} %s\n" "$1"; }

_step_line() {
    # $1 = passo atual, $2 = total, $3 = descrição (com padding), $4 = status
    printf "  Passo %s/%s  %-24s%s\n" "$1" "$2" "$3" "$4"
}

# ---------------------------------------------------------------------------
# Advance to next exercise after success
# ---------------------------------------------------------------------------
_advance_if_needed() {
    printf "\n    Use ./learn explain para ver o gabarito comentado.\n"
    NEXT_EX=$((EX + 1))
    if [ "$NEXT_EX" -le 3 ]; then
        printf "${BOLD}  → Próximo: ./learn exercise %s %s${RESET}\n\n" "$PHASE" "$NEXT_EX"
    else
        NEXT_PHASE=$((PHASE + 1))
        if [ "$NEXT_PHASE" -le 5 ]; then
            printf "${BOLD}  → Fase %s completa! Próxima: ./learn phase %s${RESET}\n\n" "$PHASE" "$NEXT_PHASE"
        else
            printf "${BOLD}  → Parabéns! Todas as fases completas!${RESET}\n\n"
        fi
    fi
}

# ---------------------------------------------------------------------------
# Phase 1 — Quiz (file-based)
# ---------------------------------------------------------------------------
check_phase1() {
    SOL="$EX_DIR/.solution/answers.txt"
    STUDENT="$EX_DIR/.student_answers.txt"
    INSTR="$EX_DIR/instructions.md"

    if [ ! -f "$SOL" ]; then
        _err "Arquivo de gabarito não encontrado: $SOL"
        exit 1
    fi

    # If student file doesn't exist, show instructions
    if [ ! -f "$STUDENT" ]; then
        _info "Para responder o quiz, edite o arquivo:"
        printf "    phases/phase-%s/exercise-%s/.student_answers.txt\n\n" "$PHASE" "$EX"
        printf "    Formato:\n"
        printf "    q1:a\n"
        printf "    q2:b\n"
        printf "    ...\n\n"
        printf "    Depois rode ./learn check novamente.\n"
        exit 0
    fi

    TOTAL=0
    CORRECT=0
    FAILED_LIST=""

    # Read solution answers into variables
    while IFS=: read -r QID SOL_ANS; do
        [ -z "$QID" ] && continue
        TOTAL=$((TOTAL + 1))

        # Get student answer for this question
        STU_ANS=$(grep "^${QID}:" "$STUDENT" | head -1 | cut -d: -f2 | tr -d ' \r\n')

        if [ "$STU_ANS" = "$SOL_ANS" ]; then
            CORRECT=$((CORRECT + 1))
            QNUM=$(printf '%s' "$QID" | tr -d 'q')
            printf "${GREEN}[✓]${RESET} Questão %s: correta\n" "$QNUM"
        else
            QNUM=$(printf '%s' "$QID" | tr -d 'q')
            printf "${RED}[✗]${RESET} Questão %s: incorreta  (sua: %s | correta: %s)\n" "$QNUM" "$STU_ANS" "$SOL_ANS"
        fi
    done < "$SOL"

    printf '\n'

    if [ "$CORRECT" -eq "$TOTAL" ]; then
        printf "${GREEN}[✓]${RESET} Resultado: %s/%s corretas\n" "$CORRECT" "$TOTAL"
        _ok "PASSOU — Quiz concluído!"
        CONCEPTS=$(awk '/^## Conceitos$/{found=1; next} found && /^##/{exit} found{print}' "$INSTR" 2>/dev/null | sed '/^[[:space:]]*$/d')
        _info "Conceitos cobertos: $CONCEPTS"
        progress_mark_done "$PHASE" "$EX"
        progress_unlock_explain "$PHASE" "$EX"
        _advance_if_needed
    else
        printf "Resultado: %s/%s corretas\n" "$CORRECT" "$TOTAL"
        _err "FALHOU — corrija as questões erradas e rode ./learn check novamente."
        exit 1
    fi
}

# ---------------------------------------------------------------------------
# Phases 2-5 — Makefile validation (7 steps)
# ---------------------------------------------------------------------------
check_makefile() {
    MAKEFILE="$EX_DIR/Makefile"

    if [ ! -f "$MAKEFILE" ]; then
        _err "Makefile não encontrado em: $EX_DIR"
        exit 1
    fi

    # Ensure clean state before starting
    cd "$EX_DIR" || exit 1
    make fclean 2>/dev/null || true

    TOTAL_STEPS=7
    ALL_PASSED=1

    printf "Validando Makefile...\n\n"

    # ------------------------------------------------------------------
    # Step 1 — Initial compilation
    # ------------------------------------------------------------------
    OUTPUT=$(make 2>&1)
    EXIT=$?

    if [ "$EXIT" -ne 0 ]; then
        _step_line 1 "$TOTAL_STEPS" "Compilação..." "${RED}[✗]${RESET}"
        printf '\n'
        printf '%s\n' "$OUTPUT"
        printf '\n'
        # Diagnose error
        if printf '%s' "$OUTPUT" | grep -q 'missing separator'; then
            _err "Receita com espaço em vez de tab. Use TAB para indentar receitas."
        elif printf '%s' "$OUTPUT" | grep -q 'No rule to make target'; then
            _err "Regra ou dependência não encontrada. Verifique targets e dependências."
        elif printf '%s' "$OUTPUT" | grep -q 'undefined variable'; then
            _err "Variável não definida. Verifique se todas as variáveis foram declaradas."
        elif printf '%s' "$OUTPUT" | grep -q 'command not found'; then
            _err "Comando não encontrado. Verifique \$(CXX) e \$(CXXFLAGS)."
        elif printf '%s' "$OUTPUT" | grep -q 'error:'; then
            _err "Erro de compilação C++. Veja a saída acima."
        else
            _err "Erro no make. Veja a saída acima para detalhes."
        fi
        _err "FALHOU"
        cd "$EX_DIR" && make fclean 2>/dev/null || true
        exit 1
    fi

    _step_line 1 "$TOTAL_STEPS" "Compilação..." "${GREEN}[✓]${RESET}"

    # ------------------------------------------------------------------
    # Step 2 — Binary exists?
    # ------------------------------------------------------------------
    NAME=$(grep '^NAME' "$EX_DIR/Makefile" | head -1 | awk '{print $3}')

    if [ -f "$EX_DIR/$NAME" ]; then
        _step_line 2 "$TOTAL_STEPS" "Binário gerado..." "${GREEN}[✓]${RESET}"
    else
        _step_line 2 "$TOTAL_STEPS" "Binário gerado..." "${RED}[✗]${RESET}"
        _err "Binário '$NAME' não foi gerado. Verifique a regra de linkagem."
        _err "FALHOU"
        cd "$EX_DIR" && make fclean 2>/dev/null || true
        exit 1
    fi

    # ------------------------------------------------------------------
    # Step 3 — make clean removes .o?
    # ------------------------------------------------------------------
    make clean >/dev/null 2>&1

    if find "$EX_DIR" -maxdepth 1 -name "*.o" | grep -q .; then
        _step_line 3 "$TOTAL_STEPS" "make clean (.o)..." "${RED}[✗]${RESET}"
        _err "'make clean' não removeu os arquivos .o."
        _err "FALHOU"
        cd "$EX_DIR" && make fclean 2>/dev/null || true
        exit 1
    fi

    _step_line 3 "$TOTAL_STEPS" "make clean (.o)..." "${GREEN}[✓]${RESET}"

    # ------------------------------------------------------------------
    # Step 4 — make clean does NOT remove the binary?
    # ------------------------------------------------------------------
    if [ -f "$EX_DIR/$NAME" ]; then
        _step_line 4 "$TOTAL_STEPS" "Binário sobrevive..." "${GREEN}[✓]${RESET}"
    else
        _step_line 4 "$TOTAL_STEPS" "Binário sobrevive..." "${RED}[✗]${RESET}"
        _err "'make clean' removeu o binário '$NAME'. clean deve remover só .o; fclean remove o binário."
        _err "FALHOU"
        cd "$EX_DIR" && make fclean 2>/dev/null || true
        exit 1
    fi

    # ------------------------------------------------------------------
    # Step 5 — make fclean removes the binary?
    # ------------------------------------------------------------------
    make fclean >/dev/null 2>&1

    if [ ! -f "$EX_DIR/$NAME" ]; then
        _step_line 5 "$TOTAL_STEPS" "make fclean (bin)..." "${GREEN}[✓]${RESET}"
    else
        _step_line 5 "$TOTAL_STEPS" "make fclean (bin)..." "${RED}[✗]${RESET}"
        _err "'make fclean' não removeu o binário '$NAME'."
        _err "FALHOU"
        cd "$EX_DIR" && make fclean 2>/dev/null || true
        exit 1
    fi

    # ------------------------------------------------------------------
    # Step 6 — make fclean also removes .o?
    # ------------------------------------------------------------------
    if find "$EX_DIR" -maxdepth 1 -name "*.o" | grep -q .; then
        _step_line 6 "$TOTAL_STEPS" "fclean remove .o..." "${RED}[✗]${RESET}"
        _err "'make fclean' não removeu os arquivos .o. fclean deve chamar clean."
        _err "FALHOU"
        cd "$EX_DIR" && make fclean 2>/dev/null || true
        exit 1
    fi

    _step_line 6 "$TOTAL_STEPS" "fclean remove .o..." "${GREEN}[✓]${RESET}"

    # ------------------------------------------------------------------
    # Step 7 — make re rebuilds everything?
    # ------------------------------------------------------------------
    make re >/dev/null 2>&1

    BIN_OK=1
    OBJ_OK=1

    if [ ! -f "$EX_DIR/$NAME" ]; then
        BIN_OK=0
    fi

    if ! find "$EX_DIR" -maxdepth 1 -name "*.o" | grep -q .; then
        OBJ_OK=0
    fi

    if [ "$BIN_OK" -eq 1 ] && [ "$OBJ_OK" -eq 1 ]; then
        _step_line 7 "$TOTAL_STEPS" "make re..." "${GREEN}[✓]${RESET}"
    else
        _step_line 7 "$TOTAL_STEPS" "make re..." "${RED}[✗]${RESET}"
        if [ "$BIN_OK" -eq 0 ]; then
            _err "'make re' não gerou o binário."
        fi
        if [ "$OBJ_OK" -eq 0 ]; then
            _err "'make re' não compilou os objetos."
        fi
        _err "FALHOU"
        cd "$EX_DIR" && make fclean 2>/dev/null || true
        exit 1
    fi

    # ------------------------------------------------------------------
    # All steps passed
    # ------------------------------------------------------------------
    printf '\n'
    _ok "PASSOU — Makefile validado com sucesso!"

    CONCEPTS=$(awk '/^## Conceitos$/{found=1; next} found && /^##/{exit} found{print}' "$EX_DIR/instructions.md" 2>/dev/null | sed '/^[[:space:]]*$/d')
    _info "Conceitos cobertos: $CONCEPTS"

    progress_mark_done "$PHASE" "$EX"
    progress_unlock_explain "$PHASE" "$EX"
    _advance_if_needed

    # Cleanup
    cd "$EX_DIR" && make fclean 2>/dev/null || true
}

# ---------------------------------------------------------------------------
# Dispatch
# ---------------------------------------------------------------------------
case "$PHASE" in
    1) check_phase1 ;;
    2|3|4|5) check_makefile ;;
    *)
        _err "Fase $PHASE não reconhecida."
        exit 1
        ;;
esac
