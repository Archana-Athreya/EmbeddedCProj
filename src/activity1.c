#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"

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
    uint16_t temp=0;
	uint16_t tempdata=0,channel=0;
	/*Intialising PWM,ADC and USART*/
    initADC();
    initPWM();
	initUSART(103);

    Change_LED_State(LED_OFF);
    while(1){
        /*checks whether both button sensor and heater is ON or OFF */
        if((BUTTON_SENSOR_ON)&& (HEATER_SENSOR_ON))
		
		{
				/* if both button sensor and heater is ON then temperature is read and sent to PWM function */
                Change_LED_State(LED_ON);
				_delay_ms(20);
				temp = ReadADC(channel);
				_delay_ms(200);
                tempdata=pwmout(temp); 
				/*output will be sent to serial monitor through USART*/
				UARTsend(tempdata);
				_delay_ms(20);

        }
        else
		{
			
			Change_LED_State(LED_OFF);
			_delay_ms(200);
			OCR1A=0;
		}
    }
}
