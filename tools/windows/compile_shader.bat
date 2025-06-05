@echo off

REM Check for input argument
if "%~1"=="" (
    echo Usage: %0 shader_file build_dir
    exit /b 1
)

set "INPUT=%~1"
set "FILENAME=%~nx1"
set "EXT=%~x1"
set "OUTNAME=%FILENAME%.spv"

REM Compile shader
echo Compiling shader %INPUT% to %~2\%OUTNAME%...

glslc "%INPUT%" -o "%~2\%OUTNAME%"
echo Compile complete.