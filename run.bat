@ECHO OFF

SETLOCAL

FOR /f "delims=" %%F IN ('dir /b /s "src\%1.cpp" 2^>NUL') DO SET filepath=%%F
FOR %%F IN (%filepath%) DO SET filename=%%~nF

SET COMPILE=g++ %filepath% -o bin\%filename%.exe

IF DEFINED filepath (
    ECHO Compiling:  %filepath%
    %COMPILE% ^
        && ECHO Compilation successful. ^
        && bin\%filename%.exe < io\in.txt > io\out.txt ^
        && ECHO Execution successful.
) ELSE (
    ECHO ERROR: File not found!
)

ENDLOCAL