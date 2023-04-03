@echo off

cd "%~dp0\Build"
call "cmake" -A 

if %ERRORLEVEL% NEQ 0 goto Error_BuildProject

exit /B %ERRORLEVEL%

:Error_BuildProject
echo Build Failed!
pause
exit /B 1