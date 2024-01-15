@echo off

if not exist _build mkdir _build
cd _build
cmake -G "Visual Studio 16 2019" ..

pause