
#include "activity1.h"
#include "activity2.h"

int main(void)
{
	init();/* Initialize Peripherals */
	/* Turns LED ON if and only if both switches ButtonSensor and Heater are closed */
	LED_actuatorstatus();/*Function inturn calls ADC,pwm and USART functions*/
	return 0;
}
