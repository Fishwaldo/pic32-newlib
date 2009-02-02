/* Example "blinkenlights" program for the PIC32 Starter Kit and C32 compiler.
   Demonstrates software PWM, use of floating-point library functions, etc.

   10/17/2008 - Phillip Burgess - pburgess@dslextreme.com */

#include <p32xxxx.h>
#include <plib.h>
#include <math.h>

#pragma config \
	FPLLIDIV = DIV_2,  \
	FPLLMUL  = MUL_20, \
	FPLLODIV = DIV_1,  \
	FWDTEN   = OFF,    \
	POSCMOD  = XT,     \
	FNOSC    = PRIPLL, \
	FPBDIV   = DIV_2

#define DEG2RAD (M_PI / 180.0)

static void pwm(
  const short a,
  const short b,
  const short c)
{
	int   bits;
	short i;

	bits = a ? BIT_0 : 0;
	if(b > 0) bits |= BIT_1;
	if(c > 0) bits |= BIT_2;
	mPORTDSetBits(bits);

	for(i=0;i<=1000;i++)
	{
		bits = (i >= a) ? BIT_0 : 0;
		if(i >= b) bits |= BIT_1;
		if(i >= c) bits |= BIT_2;

		mPORTDClearBits(bits);
	}
}

int main(void)
{
	double d;

	PORTSetPinsDigitalOut(IOPORT_D, BIT_0 | BIT_1 | BIT_2);

#if 0
	for(d = 0.0;;d += 0.005)
	{
	  pwm((int)(pow(0.5 + cos(d                  ) * 0.5,3.0) * 1000.0),
	      (int)(pow(0.5 + cos(d + 120.0 * DEG2RAD) * 0.5,3.0) * 1000.0),
	      (int)(pow(0.5 + cos(d + 240.0 * DEG2RAD) * 0.5,3.0) * 1000.0));
	}
#endif
	return 0;
}
