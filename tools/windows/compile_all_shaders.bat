@echo off
setlocal

set "SHADER_DIR=%~1"
set "BUILD_DIR=%~2"

echo Compiling all shaders in %SHADER_DIR%...
if not exist "%SHADER_DIR%" (
    echo ERROR: Shader directory "%SHADER_DIR%" does not exist!
    exit /b 1
)

set "FOUND=0"
for %%f in ("%SHADER_DIR%\*.vert" "%SHADER_DIR%\*.frag") do (
    if exist "%%f" (
        set "FOUND=1"
        echo Compiling %%f...
        call "%~dp0compile_shader.bat" "%%f" "%SHADER_DIR%"
    )
)

if "%FOUND%"=="0" (
    echo DONE: No shader files found in "%SHADER_DIR%".
    endlocal
    exit /b 0
)

echo All shaders compiled.


endlocal
exit /b 0
