@echo off
REM Batch file to compile and run Movie Database System on Windows

echo ========================================
echo Movie Database System - Build Script
echo ========================================
echo.

REM Check if g++ is available
where g++ >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo ERROR: g++ compiler not found!
    echo Please install MinGW or similar C++ compiler.
    echo.
    pause
    exit /b 1
)

echo Compiling Movie.cpp...
g++ -std=c++11 -c Movie.cpp -o Movie.o
if %ERRORLEVEL% NEQ 0 (
    echo ERROR: Failed to compile Movie.cpp
    pause
    exit /b 1
)

echo Compiling MovieDatabase.cpp...
g++ -std=c++11 -c MovieDatabase.cpp -o MovieDatabase.o
if %ERRORLEVEL% NEQ 0 (
    echo ERROR: Failed to compile MovieDatabase.cpp
    pause
    exit /b 1
)

echo Compiling main.cpp...
g++ -std=c++11 -c main.cpp -o main.o
if %ERRORLEVEL% NEQ 0 (
    echo ERROR: Failed to compile main.cpp
    pause
    exit /b 1
)

echo Linking object files...
g++ -std=c++11 Movie.o MovieDatabase.o main.o -o MovieDatabase.exe
if %ERRORLEVEL% NEQ 0 (
    echo ERROR: Failed to link
    pause
    exit /b 1
)

echo.
echo ========================================
echo BUILD SUCCESSFUL!
echo ========================================
echo.
echo Running the program...
echo.

MovieDatabase.exe

echo.
echo ========================================
echo Program execution completed
echo ========================================
pause
