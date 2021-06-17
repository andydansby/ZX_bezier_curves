//  zcc +zx -vn -SO3 -m -lm -clib=new main.c -o main -create-app

#define ABS(N) ((N<0)?(-N):(N))
#define abs(N) ((N<0)?(-N):(N))
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

#pragma printf "%f %ld %d"
#pragma scanf  "%f %ld %d"

#include <arch/zx.h>
#include <math.h>
#include <float.h>
#include <stdio.h>
#include <input.h>

#include "variables.h"
#include "plot.h"
#include "bezier.h"
#include "timer.h"


void printOptions (void);

void waitForKey (void)
{
    printf("\x16\x04\x04");
	printf("time MS =  %ld", timeDiff);
	printf ("\n");
    printf ("Press a Key");

    in_wait_key();
}

void beforeDrawing (void)
{
    in_wait_nokey();
    zx_cls(PAPER_WHITE | INK_BLUE);
    timerStart();
    return;
}

void afterDrawing (void)
{
    timerEnd();
    waitForKey();
    return;
}


void set_P0()
{
    printf("\x16\x01\x02");
	zx_cls(PAPER_WHITE | INK_BLUE);
	zx_border (2);
	printf("Input P0 X 1-254 Current = %d\n", P0_X_setting);
	printf("\n");
	printf("Try 1");
	printf("\n");
	scanf("%d", &P0_X_setting);

	printf("Input P0 Y 1-190 Current = %d\n", P0_Y_setting);
	printf("\n");
	printf("Try 96");
	printf("\n");
	scanf("%d", &P0_Y_setting);

	if (P0_X_setting > 254) P0_X_setting = 254;
	if (P0_X_setting < 1) P0_X_setting = 1;
	if (P0_Y_setting > 190) P0_Y_setting = 190;
	if (P0_Y_setting < 1) P0_Y_setting = 1;

}

void set_P1()
{
    printf("\x16\x01\x02");
	zx_cls(PAPER_WHITE | INK_BLUE);
	zx_border (2);
	printf("Input P1 X 0-255 Current = %d\n", P1_X_setting);
	printf("\n");
	printf("Try 1");
	printf("\n");
	scanf("%d", &P1_X_setting);

	printf("Input P1 Y 0-191 Current = %d\n", P1_Y_setting);
	printf("\n");
	printf("Try 5");
	printf("\n");
	scanf("%d", &P1_Y_setting);

	if (P1_X_setting > 254) P1_X_setting = 254;
	if (P1_X_setting < 1) P1_X_setting = 1;
	if (P1_Y_setting > 190) P1_Y_setting = 190;
	if (P1_Y_setting < 1) P1_Y_setting = 1;

}

void set_P2()
{
    printf("\x16\x01\x02");
	zx_cls(PAPER_WHITE | INK_BLUE);
	zx_border (2);
	printf("Input P2 X 0-255 Current = %d\n", P2_X_setting);
	printf("\n");
	printf("Try 254");
	printf("\n");
	scanf("%d", &P2_X_setting);

	printf("Input P2 Y 0-191 Current = %d\n", P2_Y_setting);
	printf("\n");
	printf("Try 5");
	printf("\n");
	scanf("%d", &P2_Y_setting);

	if (P2_X_setting > 254) P2_X_setting = 254;
	if (P2_X_setting < 1) P2_X_setting = 1;
	if (P2_Y_setting > 190) P2_Y_setting = 190;
	if (P2_Y_setting < 1) P2_Y_setting = 1;
}

void set_P3()
{
    printf("\x16\x01\x02");
	zx_cls(PAPER_WHITE | INK_BLUE);
	zx_border (2);
	printf("Input P3 X 0-255 Current = %d\n", P3_X_setting);
	printf("\n");
	printf("Try 254");
	printf("\n");
	scanf("%d", &P3_X_setting);

	printf("Input P3 Y 0-191 Current = %d\n", P3_Y_setting);
	printf("\n");
	printf("Try 96");
	printf("\n");
	scanf("%d", &P3_Y_setting);

	if (P3_Y_setting > 254) P3_Y_setting = 254;
	if (P3_Y_setting < 1) P3_Y_setting = 1;
	if (P3_Y_setting > 190) P3_Y_setting = 190;
	if (P3_Y_setting < 1) P3_Y_setting = 1;
}

void options1 (void)
{
    //key presses
    while (1)
    {
        if (in_key_pressed( IN_KEY_SCANCODE_1 ))
		{
			in_wait_nokey();
			set_P0();//routine
            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_2 ))
		{
			in_wait_nokey();
			set_P1();//routine
            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_3 ))
		{
			in_wait_nokey();
			set_P2();//routine
            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_4 ))
		{
			in_wait_nokey();
			set_P3();//routine
            in_wait_key();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_q ))
		{
		    zx_cls(PAPER_WHITE | INK_BLUE);
			beforeDrawing ();
			bezierCurve();
            afterDrawing ();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_w ))
		{
		    zx_cls(PAPER_WHITE | INK_BLUE);

			beforeDrawing ();
			bezierCurve2();
			afterDrawing ();

            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_e ))
		{
		    zx_cls(PAPER_WHITE | INK_BLUE);
			beforeDrawing ();
			bezierCurve3();
            afterDrawing ();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_r ))
		{
		    zx_cls(PAPER_WHITE | INK_BLUE);
			beforeDrawing ();
			bezierCurve4();
            afterDrawing ();
            break;
		}

		if (in_key_pressed( IN_KEY_SCANCODE_t ))
		{
		    zx_cls(PAPER_WHITE | INK_BLUE);
			beforeDrawing ();
			bezierCurve5();
            afterDrawing ();
            break;
		}


    }//end while
}//end options1



void printOptions (void)
{
    {
        zx_cls(PAPER_WHITE | INK_BLUE);
        zx_border (2);
        printf("\x16\x01\x02");

        printf ("Welcome to the Bezier Curve Demo V1.0");
        printf ("\n");
        printf ("press a key for test");
        printf ("\n");

		printf ("1 - Set P0\n");
        printf ("    P0_X_setting = %d\n", P0_X_setting);
        printf ("    P0_Y_setting = %d\n", P0_Y_setting);
        printf ("\n");

        printf ("2 - Set P1\n");
        printf ("    P1_X_setting = %d\n", P1_X_setting);
        printf ("    P1_Y_setting = %d\n", P1_Y_setting);
        printf ("\n");

        printf ("3 - Set P2\n");
        printf ("    P2_X_setting = %d\n", P2_X_setting);
        printf ("    P2_Y_setting = %d\n", P2_Y_setting);
        printf ("\n");

		printf ("4 - Set P3\n");
        printf ("    P3_X_setting = %d\n", P3_X_setting);
        printf ("    P3_Y_setting = %d\n", P3_Y_setting);
        printf ("\n\n");

        printf ("Q- Original Bezier formula");
        printf ("\n");
        printf ("W-T Optimzied Bezier formulas");

        printf ("Press SPACE to STOP drawing");
    }

    options1();
}


void main()
{
	__asm
	ei
	__endasm

	zx_cls(PAPER_WHITE | INK_BLUE);

	yHeight = 190;
	xWidth = 255;
	X_start = 255;
	Y_start = 45;
	sineCycle = 0;
	waveHeight = 40;
	halfHeight = waveHeight / 2;
	freq = 2.0;
    offSet = 46;


    amplitude = 10;
    phase_shift = 0;
    vertical_shift = 87;




    while (1)
    {
        printOptions();
    }

}

//leave blank line after


