@echo off
REM learn.bat — Roda o makefile-learn dentro do WSL
REM Uso: learn start | learn check | learn progress | etc.
REM
REM Requisitos WSL (rodar uma vez):
REM   wsl -- sudo apt update && sudo apt install -y build-essential

REM Converte caminho Windows -> WSL usando wslpath (mais robusto)
set "WIN_DIR=%~dp0"
REM Remove trailing backslash
if "%WIN_DIR:~-1%"=="\" set "WIN_DIR=%WIN_DIR:~0,-1%"

REM Monta os argumentos
set "ARGS="
:loop
if "%~1"=="" goto run
set "ARGS=%ARGS% %1"
shift
goto loop

:run
wsl -- bash -c "cd \"$(wslpath '%WIN_DIR%')\" && ./learn%ARGS%"
