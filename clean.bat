@echo off 
setlocal enableDelayedExpansion 

rmdir "%CD%\build\debug" /s /q 

start /wait /B scons

set MYDIR=%CD%\build\debug
for /F %%x in ('dir /B/D %MYDIR%') do (
  for /f "delims=" %%a in ('dir /b /s "%MYDIR%\%%x\*.exe"') do (
      echo ------------------------------------------------------------------
      echo                           Running %%x
      echo %%a
      echo ------------------------------------------------------------------
      start /wait /B %%a
      pause>nul
  )
)
echo finished....