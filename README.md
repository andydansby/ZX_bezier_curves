# ZX_bezier_curves
Cubic Bezier Curves of the ZX Spectrum.  Hell ya.

Set P0 and P3 as start and end points.
Set P1 and P2 as the Curve attractors.

Press Q for the official Calculation, this is really slow
calculated with
pow(1-u,3) * p0_x + 3 * u * pow(1-u,2) * p1_x + 3 * pow(u,2) * (1-u) * p2_x + pow(u,3) * p3_x
pow(1-u,3) * p0_y + 3 * u * pow(1-u,2) * p1_y + 3 * pow(u,2) * (1-u) * p2_y + pow(u,3) * p3_y

this can take quite a while and with your emulator, you will need to speed this up

W - T are a series of optimized versions that perform considerably faster, run your emulator at normal speed.

any programming suggestions and code are appreciated.

I use Code::Blocks as an IDE and compile with Z88dk.

To compile, you will have to adjust the compile.bat file.  run compile.bat to compile with Z88dk.

**note there is plenty of residual crud in the program, please be patient while I clean up my mess.
