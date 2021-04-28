#include "Activity_1.h"
#include "Activity_2.h"
#include "Activity_3.h"
#include "Activity_3.h"

void delayms(uint32_t delay_time)
{
	uint32_t units = 0;
	for (units = 0; units <= delay_time; units++)
	{
		_delay_ms(1);
	}
}

void Change_LED_State(uint8_t state)
{
	LED_PORT = (state << LED_PIN);
}

void buttonsensorinput(void)
{
	BUTTON_SENSOR_PORT |= (1 << BUTTON_SENSOR_PIN);
}

void heatersensorinput(void)
{
	HEATER_SENSOR_PORT |= (1 << HEATER_SENSOR_PIN);
}

void init(void)
{
	/* Configure LED Pin */
	SET_PORTB0;
    SET_PORTD; 
	SET_PD0_AND_PD1; 
    buttonsensorinput();
    heatersensorinput();
}

void LED_actuatorstatus(void)
{   
    uint16_t temp=0, channel=0;
	initADC();
    initPWM();

    Change_LED_State(LED_OFF);
    while(1){
        /*checks whether button sensor and heater is ON or OFF */
        if((BUTTON_SENSOR_ON)&& (HEATER_SENSOR_ON))
		
		{

                Change_LED_State(LED_ON);
				//delayms(200);
                temp = ReadADC(channel);
                OCR1A = temp;
                delayms(200);

        }
        else
			Change_LED_State(LED_OFF);
    }
}
