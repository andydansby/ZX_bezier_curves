#ifndef BEZIER_H
#define BEZIER_H

float pow2 (float xx)
{
    return xx * xx;
}
float pow3 (float xx)
{
    return xx * xx * xx;
}


//standard Bezier plot
//this one is based on
//https://www.geeksforgeeks.org/cubic-bezier-curve-implementation-in-c/
void bezierCurve(void)
{
    //grab from the globals
    float p0_x = (float)P0_X_setting;
    float p1_x = (float)P1_X_setting;
    float p2_x = (float)P2_X_setting;
    float p3_x = (float)P3_X_setting;

    float p0_y = (float)P0_Y_setting;
    float p1_y = (float)P1_Y_setting;
    float p2_y = (float)P2_Y_setting;
    float p3_y = (float)P3_Y_setting;

    float xu = 0.0;
    float yu = 0.0;
    float t = 0.0;

    plotControlPoints ();

    while (1)
    {
        //note: the built in power function is expensive.  The best way to counter it is to roll your own
        //optimized for this particular task
        xu = pow(1-t,3) * p0_x + 3 * t * pow(1-t,2) * p1_x + 3 * pow(t,2) * (1-t) * p2_x + pow(t,3) * p3_x;

        yu = pow(1-t,3) * p0_y + 3 * t * pow(1-t,2) * p1_y + 3 * pow(t,2) * (1-t) * p2_y + pow(t,3) * p3_y;

        x = (int) xu;
        y = (int) yu;
		plot(x, y);
		t += 0.01;

		if (t > 1.0)
        {
            break;
            //bezier goes wacky if out of range
            //range is 0 to 1 for Bezier
        }
        if (in_key_pressed( IN_KEY_SCANCODE_SPACE ))
        {
            break;
        }
    }//end while
}//end function

//same as above, but use optimized power function
void bezierCurve2(void)
{
    //grab from the globals
    float p0_x = (float)P0_X_setting;
    float p1_x = (float)P1_X_setting;
    float p2_x = (float)P2_X_setting;
    float p3_x = (float)P3_X_setting;

    float p0_y = (float)P0_Y_setting;
    float p1_y = (float)P1_Y_setting;
    float p2_y = (float)P2_Y_setting;
    float p3_y = (float)P3_Y_setting;

    float xu = 0.0;
    float yu = 0.0;
    float t = 0.0;

    float xu0 = 0.0;
    float xu1 = 0.0;
    float xu2 = 0.0;
    float xu3 = 0.0;

    float yu0 = 0.0;
    float yu1 = 0.0;
    float yu2 = 0.0;
    float yu3 = 0.0;

    plotControlPoints ();

    while (1)
    {
        //xu = pow(1-u,3) * p0_x + 3 * u * pow(1-u,2) * p1_x + 3 * pow(u,2) * (1-u) * p2_x + pow(u,3) * p3_x;

        xu0 = pow3(1-t) * p0_x;
        xu1 = 3 * t * pow2(1-t) * p1_x;
        xu2 = 3 * pow2(t) * (1-t) * p2_x;
        xu3 = pow3(t) * p3_x;
        xu = xu0 + xu1 + xu2 + xu3;


        //yu = pow(1-u,3) * p0_y + 3 * u * pow(1-u,2) * p1_y + 3 * pow(u,2) * (1-u) * p2_y + pow(u,3) * p3_y;
        yu0 = pow3(1-t) * p0_y;
        yu1 = 3 * t * pow2(1-t) * p1_y;
        yu2 = 3 * pow2(t) * (1-t) * p2_y;
        yu3 = pow3(t) * p3_y;
        yu = yu0 + yu1 + yu2 + yu3;

        x = (int) xu;
        y = (int) yu;
		plot(x, y);
		t += 0.01;

		if (t > 1.0)
        {
            break;
            //bezier goes wacky if out of range
            //range is 0 to 1 for Bezier
        }
        if (in_key_pressed( IN_KEY_SCANCODE_SPACE ))
        {
            break;
        }
    }//end while
}//end function

//based on
//https://robnapier.net/fast-bezier-intro
void bezierCurve3(void)
{
    //grab from the globals
    float p0_x = (float)P0_X_setting;
    float p1_x = (float)P1_X_setting;
    float p2_x = (float)P2_X_setting;
    float p3_x = (float)P3_X_setting;

    float p0_y = (float)P0_Y_setting;
    float p1_y = (float)P1_Y_setting;
    float p2_y = (float)P2_Y_setting;
    float p3_y = (float)P3_Y_setting;

    float xu = 0.0;
    float yu = 0.0;
    float t = 0.0;

    float xu0 = 0.0;
    float xu1 = 0.0;
    float xu2 = 0.0;
    float xu3 = 0.0;

    float yu0 = 0.0;
    float yu1 = 0.0;
    float yu2 = 0.0;
    float yu3 = 0.0;
    float tt2 = 0;
    float tt3 = 0;
    float tt2_inv = 0;
    float tt3_inv = 0;

    plotControlPoints ();

    while (1)
    {
        tt2 = t * t;
        tt3 = t * t * t;
        tt2_inv = (1-t) * (1-t);
        tt3_inv = (1-t) * (1-t) * (1-t);


        xu0 = tt3_inv * p0_x;
        xu1 = 3 * t * tt2_inv * p1_x;
        xu2 = 3 * tt2 * (1-t) * p2_x;
        xu3 = tt3 * p3_x;
        xu = xu0 + xu1 + xu2 + xu3;


        yu0 = tt3_inv * p0_y;
        yu1 = 3 * t * tt2_inv * p1_y;
        yu2 = 3 * tt2 * (1-t) * p2_y;
        yu3 = tt3 * p3_y;
        yu = yu0 + yu1 + yu2 + yu3;

        x = (int) xu;
        y = (int) yu;
		plot(x, y);
		t += 0.01;

		if (t > 1.0)
        {
            break;
            //bezier goes wacky if out of range
            //range is 0 to 1 for Bezier
        }
        if (in_key_pressed( IN_KEY_SCANCODE_SPACE ))
        {
            break;
        }
    }//end while

}//end function


//based on
//https://robnapier.net/fast-bezier-intro
void bezierCurve4(void)
{
    //grab from the globals
    float p0_x = (float)P0_X_setting;
    float p1_x = (float)P1_X_setting;
    float p2_x = (float)P2_X_setting;
    float p3_x = (float)P3_X_setting;

    float p0_y = (float)P0_Y_setting;
    float p1_y = (float)P1_Y_setting;
    float p2_y = (float)P2_Y_setting;
    float p3_y = (float)P3_Y_setting;

    float xu = 0.0;
    float yu = 0.0;
    float t = 0.0;

    float cu0 = 0.0;
    float cu1 = 0.0;
    float cu2 = 0.0;
    float cu3 = 0.0;


    plotControlPoints ();

    while (1)
    {
        cu0 = (1-t) * (1-t) * (1-t);
        cu1 = 3 * (1-t) * (1-t) * t;
        cu2 = 3 * (1-t) * t * t;
        cu3 = t*t*t;

        //looks quite like matrix multiplication
        xu = cu0 * p0_x + cu1 * p1_x + cu2 * p2_x + cu3 * p3_x;
        yu = cu0 * p0_y + cu1 * p1_y + cu2 * p2_y + cu3 * p3_y;

        x = (int) xu;
        y = (int) yu;
		plot(x, y);
		t += 0.01;

		if (t > 1.0)
        {
            break;
            //bezier goes wacky if out of range
            //range is 0 to 1 for Bezier
        }
        if (in_key_pressed( IN_KEY_SCANCODE_SPACE ))
        {
            break;
        }
    }//end while

}//end function


//based on
//https://robnapier.net/faster-bezier
void bezierCurve5(void)
{
    //grab from the globals
    float p0_x = (float)P0_X_setting;
    float p1_x = (float)P1_X_setting;
    float p2_x = (float)P2_X_setting;
    float p3_x = (float)P3_X_setting;

    float p0_y = (float)P0_Y_setting;
    float p1_y = (float)P1_Y_setting;
    float p2_y = (float)P2_Y_setting;
    float p3_y = (float)P3_Y_setting;

    float xu = 0.0;
    float yu = 0.0;

    float t = 0.0;
    float t2 = 0;
    float t3 = 0;

    float mt = 0;
    float mt2 = 0;
    float mt3 = 0;

    float cu0 = 0.0;
    float cu1 = 0.0;
    float cu2 = 0.0;
    float cu3 = 0.0;

    plotControlPoints ();

    while (1)
    {
        t2 = t * t;
        t3 = t2 * t;

        mt = 1-t;
        mt2 = mt * mt;
        mt3 = mt2 * mt;

        cu0 = p0_x * mt3;
        cu1 = p1_x * 3 * mt2 * t;
        cu2 = p2_x * 3 * mt * t2;
        cu3 = p3_x * t3;
        xu = cu0 + cu1 + cu2 + cu3;


        cu0 = p0_y * mt3;
        cu1 = p1_y * 3 * mt2 * t;
        cu2 = p2_y * 3 * mt * t2;
        cu3 = p3_y * t3;
        yu = cu0 + cu1 + cu2 + cu3;

        x = (int) xu;
        y = (int) yu;
		plot(x, y);
		t += 0.01;

		if (t > 1.0)
        {
            break;
            //bezier goes wacky if out of range
            //range is 0 to 1 for Bezier
        }
        if (in_key_pressed( IN_KEY_SCANCODE_SPACE ))
        {
            break;
        }
    }//end while
}//end function


//see licensing.txt
void bezierCurve6(void)
{
    //grab from the globals
    float p0_x = (float)P0_X_setting;
    float p1_x = (float)P1_X_setting;
    float p2_x = (float)P2_X_setting;
    float p3_x = (float)P3_X_setting;

    float p0_y = (float)P0_Y_setting;
    float p1_y = (float)P1_Y_setting;
    float p2_y = (float)P2_Y_setting;
    float p3_y = (float)P3_Y_setting;

    float xu = 0.0;
    float yu = 0.0;

    float ax = 0;
    float ay = 0;
    float bx = 0;
    float by = 0;
    float cx = 0;
    float cy = 0;

    float t = 0;
    float t2 = 0;
    float t3 = 0;

    plotControlPoints ();

    while (1)
    {
        t2 = t * t;
        t3 = t2 * t;

        cx = 3 * (p1_x - p0_x);
        cy = 3 * (p1_y - p0_y);

        bx = 3 * (p2_x - p1_x) - cx;
        by = 3 * (p2_y - p1_y) - cy;

        ax = p3_x - p0_x - cx - bx;
        ay = p3_y - p0_y - cy - by;

        xu = (ax * t3) + (bx * t2) + (cx * t) + p0_x;
        yu = (ay * t3) + (by * t2) + (cy * t) + p0_y;

        x = (unsigned char) xu;
        y = (unsigned char) yu;
		plot(x, y);

		t += 0.01;

		if (t > 1.0)
        {
            break;
            //bezier goes wacky if out of range
            //range is 0 to 1 for Bezier
        }
        if (in_key_pressed( IN_KEY_SCANCODE_SPACE ))
        {
            break;
        }
    }//end while
}//end function


#endif
//leave blank line after
