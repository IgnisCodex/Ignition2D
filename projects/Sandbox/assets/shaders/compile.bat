@echo off
setlocal

CALL %~dp0..\..\..\..\tools\windows\compile_all_shaders.bat %~dp0 %~dp0

endlocal
pause