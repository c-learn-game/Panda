@echo off

call "%~dp0Third\Premake5\Windows\premake5.exe" --file=Panda.project vs2017 %*

if %ERRORLEVEL% NEQ 0 goto Error_BuildProject

exit /B %ERRORLEVEL%

:Error_BuildProject
echo Build Failed!
pause
exit /B 1