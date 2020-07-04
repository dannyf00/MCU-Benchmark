#include "gpio.h"									//use gpio
#include "delay.h"									//use software delays
#include "coretick.h"
#include "benchmark_ti.h"
//#include "systick.h"								//use systick
//#include "uart0isr.h"								//use uart0/vcp
//#include "timer0.h"
//#include "timer1.h"
//#include "timer2.h"
//#include "timer3.h"
//#include "timer4.h"
//#include "timer5.h"
//#include "wtimer0.h"
//#include "wtimer1.h"
//#include "wtimer2.h"
//#include "wtimer3.h"
//#include "wtimer4.h"
//#include "wtimer5.h"
//#include "pwm.h"
//#include "uart.h"
#include "dhry.h"									//we use dhrystone benchmark
#include "whetstone.h"								//we use whetstone benchmark

//hardware configuration
#define LED_PORT			GPIOF
#define LED					(LEDG)					//1=R, 2=B, 3=G
//end hardware configuration

//global defines

//global variables

//return 1 to set led, 0 to clear led
int led_pwm(int pr) {
	static int i=0, j=0, tmp=0;

	if (i++ > pr + 0) {i-= (pr + 0); tmp ^= 1;}
	if (j++ > pr + 1) {j-= (pr + 1); tmp ^= 1;}
	return tmp;
}

//return 1 to flip led
int led_flp(int pr) {
	static int i=0, j=0, tmp=0;
	int tmp1;

	tmp1 = tmp;
	if (i++ > pr + 0) {i-= (pr + 0); tmp ^= 1;}
	if (j++ > pr + 1) {j-= (pr + 1); tmp ^= 1;}
	return tmp ^ tmp1;
}

//return 1 to flip led
int led_flp2(int pr) {
	static int i=0, j=0, tmp=0;
	int tmp1;

	tmp1 = tmp;
	if (i++ > pr + 0) {i-= (pr + 0); tmp ^= 1;}
	if (j++ > pr + 1) {j-= (pr + 1); tmp ^= 1;}
	return tmp ^ tmp1;
}

int main(void) {
	int32_t i, time1, tmp;

	mcu_init();										//reset the  mcu
	//coretick_init();								//initialize coretick
	coretick_init();									//initialize systick

	//tmr5a_init(100, 1000);
	//tmr5a_act(led_flp);
	//tmr5b_init(100, 1010);
	//tmr5b_act(led_flp);
	IO_OUT(LED_PORT, LED);							//led as output

	//pwm0b_init(1, 1000); pwm0b_setdc(1);			//pwm

	//uart0_init(9600);

	ei();											//enable interrupts
	while(1) {
		//flip led
		tmp = ticks();
		IO_FLP(LED_PORT, LED);						//to be benchmarked
		//tmp = TIMER5->TBR - tmp;
		//tmp = ticks();								//time stamp
		//uart0_puts("abcdef\n\r");
		//tmp = ticks();
		delay_ms(100);								//waste some time
		tmp = ticks() - tmp;						//calculate time elapsed

		//benchmark starts
		time1=benchmark(main_8);
		time1=benchmark(main_8m);
		time1=benchmark(main_8sw);
		time1=benchmark(main_16);
		time1=benchmark(main_16m);
		time1=benchmark(main_16sw);
		time1=benchmark(main_32);
		time1=benchmark(main_f);
		time1=benchmark(main_mmlt);
		time1=benchmark(main_fir);
		time1=benchmark(dhrystone);							//dyrstone benchmark
		time1=benchmark(whetstone);							//whetseone benchmark

	}

	return 0;
}


