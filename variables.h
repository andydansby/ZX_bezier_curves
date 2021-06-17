const float DOUBLEPI = 6.283184;
const float PI = 3.14159;
const float HALFPI = 1.570795;
const float QUARTERPI = 0.785398;

signed int x, y;
float t;
float YY, yy;

float sinCalc = 0;

unsigned char yHeight = 172;//height of the display
unsigned char xWidth = 255;//width of the display
unsigned char X_start = 255;
unsigned char Y_start = 45;
unsigned float sineCycle = 0;

unsigned char waveHeight = 40;
int halfHeight = 20;//waveHeight / 2
unsigned char offSet = 46;
float freq = 2;



int amplitude;
int period;
int phase_shift;
int vertical_shift;

//start point
int P0_X_setting = 1;
int P0_Y_setting = 96;

int P1_X_setting = 50;
int P1_Y_setting = 5;

int P2_X_setting = 200;
int P2_Y_setting = 185;

//end point
int P3_X_setting = 254;
int P3_Y_setting = 96;




float delta = 3.14/2;
int x_offset = 128;
int y_offset = 90;


long microSec;
long seconds;
long minutes;
long timeStart;
long timeEnd;
long timeDiff;


