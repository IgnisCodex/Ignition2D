@echo off
setlocal

set "SHADER_DIR=%~1\assets\shaders"
set "BUILD_DIR=%~2\assets\shaders"

echo Copying to build directory...

if not exist "%BUILD_DIR%" (
    echo Build dir does not exist. Creating directory %BUILD_DIR%...
    mkdir "%BUILD_DIR%"
)

for %%f in ("%SHADER_DIR%\*.spv") do (
    copy /Y "%%f" "%BUILD_DIR%"
)

echo DONE: All shaders copied.

endlocal
PAUSE