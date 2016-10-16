@ECHO OFF

SETLOCAL EnableDelayedExpansion

FOR /f "delims=" %%F IN ('dir /b /s "src\%1.cpp" 2^>NUL') DO SET filepath=%%F
FOR %%F IN (%filepath%) DO SET filename=%%~nF

SET INPUT=io\in.txt
SET OUTPUT=io\out.txt
SET ERROR=io\err.txt

SET COMPILE=g++ -std=c++11 -Wall "%filepath%" -o "bin\%filename%.exe"

IF DEFINED filepath (
    ECHO Compiling:  %filepath%
    %COMPILE% 2> %ERROR%
    IF ERRORLEVEL 1 (
        TYPE "%ERROR%""
        ECHO.
        ECHO Compilation failed.  See "%ERROR%" for details.
    ) ELSE (
        ECHO Compilation successful.
        ECHO.
        "bin\%filename%.exe" < %INPUT% > %OUTPUT% 2> %ERROR%  ^
            && SET result=Execution successful. ^
            || SET result=The program crashed.
        TYPE "%OUTPUT%"
        ECHO.
        ECHO !result!
    )
) ELSE (
    ECHO ERROR: File not found!
)

ENDLOCAL
