#ifndef PLOT_H
#define PLOT_H

void plot (unsigned char x, unsigned char y)
{
	//just in case you are testing a new algorithm

	if (x > 255)	return;
	if (x < 0)		return;
	if (y > 191)	return;
	if (y < 0)		return;

	*zx_pxy2saddr (x,y) |= zx_px2bitmask(x);
}


void unplot(int x, int y, unsigned char colour)
{
	unsigned char *address;

	if (x > 255)	x = 255;
	if (x < 0)		x = 0;
	if (y > 191)	y = 191;
	if (y < 0)		y = 0;

	address = zx_pxy2saddr(x,y);

	*address &= ~zx_px2bitmask(x);

	*zx_saddr2aaddr(address) = colour;
}


void plotControlPoints (void)
{
    plot(P0_X_setting, P0_Y_setting);   plot(P0_X_setting-1, P0_Y_setting);
    plot(P0_X_setting, P0_Y_setting-1);   plot(P0_X_setting-1, P0_Y_setting-1);

    plot(P1_X_setting, P1_Y_setting);   plot(P1_X_setting-1, P1_Y_setting);
    plot(P1_X_setting, P1_Y_setting-1);   plot(P1_X_setting-1, P1_Y_setting-1);

    plot(P2_X_setting, P2_Y_setting);   plot(P2_X_setting-1, P2_Y_setting);
    plot(P2_X_setting, P2_Y_setting-1);   plot(P2_X_setting-1, P2_Y_setting-1);

    plot(P3_X_setting, P3_Y_setting);   plot(P3_X_setting-1, P3_Y_setting);
    plot(P3_X_setting, P3_Y_setting-1);   plot(P3_X_setting-1, P3_Y_setting-1);

    return;
}


#endif
//leave blank line after
