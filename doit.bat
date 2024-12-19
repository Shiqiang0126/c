@echo off

:: Phase 1
ECHO begin phase 1: pipei.exe
.\pipei.exe < cal.txt
IF %ERRORLEVEL% NEQ 0 GOTO ERROR

::P1 OK, Phase 2
ECHO:
type cal.txt
ECHO:
ECHO phase 1 ok, begin phase 2: infix to suffix translat. 
type cal.txt | i2s.exe > rpn.txt
IF %ERRORLEVEL% NEQ 0 GOTO ERROR

::P2 OK, Phase 3
ECHO:
type rpn.txt
ECHO:
ECHO phase 2 ok, begin phase 3: calculat rpn expression.
type rpn.txt | rpn_cal.exe

:OK
ECHO:
ECHO phase 3 ok 
ECHO ALL work done.
GOTO END

:ERROR
ECHO:
ECHO Some error occur... working stopped.

:END