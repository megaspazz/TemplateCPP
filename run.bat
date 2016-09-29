@ECHO OFF

SETLOCAL

FOR /f "delims=" %%F IN ('dir /b /s "src\%1.cpp" 2^>nul') DO SET filepath=%%F
FOR %%F IN (%filepath%) DO SET filename=%%~nF

IF DEFINED filepath (
    ECHO Compiling:  %filepath%
    g++ %filepath% -o bin\%filename%.exe && ECHO Compile succeeded! && bin\%filename% < io/in.txt > io/out.txt
) ELSE (
    ECHO ERROR: File not found!
)

ENDLOCAL