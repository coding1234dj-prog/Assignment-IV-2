@echo off
chcp 65001 >nul
title C/C++ Hash Function Builder

REM ============== 編譯器與旗標 ==============
set "CC=gcc.exe"
set "CXX=g++.exe"

set "CFLAGS=-std=c23 -Wall -Wextra -Wpedantic -O2 -g"
set "CXXFLAGS=-std=c++23 -Wall -Wextra -Wpedantic -O2 -g"

REM ============== 檔案路徑 ==============
set "C_SRCS=C\main.c C\hash_fn.c"
set "C_OBJS=C\main.o C\hash_fn.o"
set "C_BIN=C\hash_function.exe"

set "CXX_SRCS=CXX\main.cpp CXX\hash_fn.cpp"
set "CXX_OBJS=CXX\main.o CXX\hash_fn.o"
set "CXX_BIN=CXX\hash_function_cpp.exe"

REM ============== 參數處理 ==============
if "%~1"=="" goto all
if /i "%~1"=="all"   goto all
if /i "%~1"=="c"     goto c
if /i "%~1"=="cxx"   goto cxx
if /i "%~1"=="clean" goto clean
goto usage

:all
echo [ALL] 正在編譯 C 和 C++ 兩個版本...
call :c
echo.
call :cxx
goto success

:c
echo [C] 正在編譯 C 版本...
if not exist C mkdir C
%CC% %CFLAGS% -c C\main.c    -o C\main.o    || goto error
%CC% %CFLAGS% -c C\hash_fn.c  -o C\hash_fn.o  || goto error
%CC% %CFLAGS% %C_OBJS% -o "%C_BIN%"           || goto error
echo [C] 編譯成功 → %C_BIN%
if /i "%~1"=="c" start "" "%C_BIN%"
goto :eof

:cxx
echo [CXX] 正在編譯 C++ 版本...
if not exist CXX mkdir CXX
%CXX% %CXXFLAGS% -c CXX\main.cpp   -o CXX\main.o   || goto error
%CXX% %CXXFLAGS% -c CXX\hash_fn.cpp -o CXX\hash_fn.o || goto error
%CXX% %CXXFLAGS% %CXX_OBJS% -o "%CXX_BIN%"          || goto error
echo [CXX] 編譯成功 → %CXX_BIN%
if /i "%~1"=="cxx" start "" "%CXX_BIN%"
goto :eof

:clean
echo [CLEAN] 正在清除產生檔案...
del /Q C\*.o CXX\*.o 2>nul
del /Q "%C_BIN%" "%CXX_BIN%" 2>nul
echo 清除完成！
goto end

:usage
echo.
echo 使用方式: %~n0 [all ^| c ^| cxx ^| clean]
echo   all    - 編譯 C 和 C++ 版本（預設）
echo   c      - 只編譯並執行 C 版本
echo   cxx    - 只編譯並執行 C++ 版本
echo   clean  - 清除所有 .o 和 .exe
echo.
echo 範例：
echo   雙擊此檔案          → 編譯兩個版本
echo   拖曳到命令視窗輸入 cxx → 只編譯並立刻執行 C++ 版
goto end

:error
echo.
echo ╔══════════════════════════════════╗
echo ║        編譯失敗！請檢查錯誤訊息        ║
echo ╚══════════════════════════════════╝
echo.
pause
goto end

:success
echo.
echo ╔══════════════════════════════════╗
echo ║           全部編譯成功！           ║
echo ╚══════════════════════════════════╝
echo.
if "%~1"=="" pause
goto end

:end
title 命令提示字元