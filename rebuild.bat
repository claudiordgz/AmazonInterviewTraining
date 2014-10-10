@echo off 
setlocal enableDelayedExpansion 

rmdir "%CD%\build\debug" /s /q 

set SCONS_MSCOMMON_DEBUG=-
start /wait /B scons
