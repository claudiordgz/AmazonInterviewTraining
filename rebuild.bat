@echo off 
setlocal enableDelayedExpansion 

rmdir "%CD%\build\debug" /s /q 

start /wait /B scons
