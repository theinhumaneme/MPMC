#include <reg51.h>
sbit g1=P1^0;
sbit r1=P1^1;
sbit y1=P1^2;
sbit g2=P1^3;
sbit r2=P1^4;
sbit y2=P1^5;
sbit g3=P1^6;
sbit r3=P1^7;
sbit y3=P3^0;
sbit g4=P3^1;
sbit r4=P3^2;
sbit y4=P3^3;

void delay(int c)
{
	int i,j;
	for(i=0;i<c;i++)
	{
		for(j=0;j<1000;j++);
	}
}
int main()
{

	while(1)
	{
		g1=1; r1=0; y1=0;
		g2=0; r2=1; y2=0;
		g3=0; r3=1; y3=0;
		g4=0; r4=1; y4=0;
		delay(500);
		g1=0;y1=1;y2=1;r2=0;
		delay(200);
		g1=0; r1=1; y1=0;
		g2=1; r2=0; y2=0;
		g3=0; r3=1; y3=0;
		g4=0; r4=1; y4=0;
		delay(500);
		g2=0;y2=1;y3=1;r3=0;
		delay(200);
		g1=0; r1=1; y1=0;
		g2=0; r2=1; y2=0;
		g3=1; r3=0; y3=0;
		g4=0; r4=1; y4=0;
		delay(500);
		g3=0;y3=1;y4=1;r4=0;
		delay(200);
		g1=0; r1=1; y1=0;
		g2=0; r2=1; y2=0;
		g3=0; r3=1; y3=0;
		g4=1; r4=0; y4=0;
		delay(500);
		g4=0;y4=1;y1=1;r4=0;
		delay(200);
	}
}