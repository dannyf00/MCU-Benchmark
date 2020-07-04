//#include "gpio.h"					//we use F_CPU + gpio functions
//#include "delay.h"					//we use software delays
//#include "systick.h"				//we use systick
#include "dhry.h"					//we use dhrystone benchmark
#include "whetstone.h"				//we use whetstone benchmark
#include "benchmark_ti.h"			//we use TI's benchmark routines

//hardware configuration
//end hardware configuration

//global defines

//global variables


int main(void) {
	uint32_t time0, time1, tmp;
	int32_t index;

	//mcu_init();									//reset the  mcu

	//IO_OUT(LED_PORT, LED);						//led3/4 as output
	//ei();
	while (1) {
		//IO_FLP(LED_PORT, LED);					//flip led

		//benchmark starts
		time1=benchmark(main_8);							//8-bit Math
		time1=benchmark(main_8m);							//8-bit Matrix
		time1=benchmark(main_8sw);							//8-bit Switch
		time1=benchmark(main_16);							//16-bit Math
		time1=benchmark(main_16m);							//16-bit Matrix
		time1=benchmark(main_16sw);							//16-bit Switch
		time1=benchmark(main_32);							//32-bit Math
		time1=benchmark(main_f);							//floating point Math
		time1=benchmark(main_mmlt);							//floating point Matrix
		time1=benchmark(main_fir);							//floating point FIR
		time1=benchmark(dhrystone);							//dyrstone benchmark
		time1=benchmark(whetstone);							//whetseone benchmark
	}
}

