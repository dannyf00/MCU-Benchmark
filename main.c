#include "gpio.h"									//use gpio
#include "delay.h"									//use software delays
#include "coretick.h"
#include "benchmark_ti.h"
#include "dhry.h"									//we use dhrystone benchmark
#include "whetstone.h"								//we use whetstone benchmark

//hardware configuration
#define LED_PORT			GPIOF
#define LED					(LEDG)					//1=R, 2=B, 3=G
//end hardware configuration

//global defines

//global variables

int main(void) {
	int32_t i, time1, tmp;

	mcu_init();										//reset the  mcu
	coretick_init();									//initialize systick

	IO_OUT(LED_PORT, LED);							//led as output

	//ei();											//enable interrupts
	while(1) {
		//flip led
		IO_FLP(LED_PORT, LED);						//to be benchmarked

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


