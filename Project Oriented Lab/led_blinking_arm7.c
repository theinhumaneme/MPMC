// ARM7 CODE FOR BLINKING LED

#include<LPC214X.h>
#include <stdio.h>


void delay(int sec){
	int value = sec*1000;
	while(value--){
		// NO OPERATION
	}
}

int main(){
	// SET DIRECTION TO OUTPUT AT P0
	IODIR1 = 0x00100000;

	// SWITCHING LED AT P8 PIN1 ON/OFF
	while(1){
		IOSET1 = 0x00100000;
		delay(1000);
		IOCLR1 = 0x00100000;
		delay(1000);
	}
}
