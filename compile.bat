SET PATH=c:\z88dk199c;c:\z88dk199c\bin;c:\z88dk199c\lib\;c:\z88dk199c\lib\clibs;c:\z88dk199c\lib\config

del "1bezier.tap"
cls

@rem zcc +zx -lp3 -lm -create-app -bn sin main.c

zcc +zx -vn -SO3 -m -lm -clib=new main.c -o 1bezier -startup=9 -create-app

rem  (generate sin.tap)

del "1bezier_CODE.bin"
del "1bezier_UNASSIGNED.bin"

rem rename main.tap sine.tap

call beep.bat