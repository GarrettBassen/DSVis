@echo off

:: SETUP SFML
mkdir libraries\SFML

echo Downloading SFML
:downloadSFML
powershell -Command "Invoke-WebRequest https://www.sfml-dev.org/files/SFML-2.6.1-windows-vc17-64-bit.zip" -OutFile SFML.zip
if %errorlevel% neq 0 GOTO downloadSFML

echo Unzipping file
powershell -Command "Expand-Archive SFML.zip SFML"
del SFML.zip
echo Moving SFML files
move SFML\SFML-2.6.1\lib       libraries\SFML\ >nul
move SFML\SFML-2.6.1\include   libraries\SFML\ >nul
move SFML\SFML-2.6.1\bin\*.dll %cd% >nul
echo Success
echo Cleaning residual files
rmdir SFML /S /Q

:: SETUP IMGUI
mkdir libraries\imgui

echo downloading imgui
:downloadIMGUI
git clone https://github.com/ocornut/imgui.git
if %errorlevel% neq 0 GOTO downloadIMGUI

echo Moving imgui files
move imgui\*cpp libraries\imgui >nul
move imgui\*h   libraries\imgui >nul
echo Success
echo Cleaning residual files
rmdir imgui /S /Q

:: SETUP IMGUI-SFML
echo Downloading imgui-sfml
:downloadIMGUISFML
git clone https://github.com/SFML/imgui-sfml.git
if %errorlevel% neq 0 goto downloadIMGUISFML

echo Moving imgui-sfml files
move imgui-sfml\*.cpp libraries\imgui >nul
move imgui-sfml\*.h   libraries\imgui >nul
echo Success
echo Cleaning residual files
rmdir imgui-sfml /S /Q

echo Installed successfully! Please follow next instruction to finalize install.
pause