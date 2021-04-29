/**
 * @file activity1.h
 * @author Archana.N.N(archanaathreya2000@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _ACTIVITY_1_H_
#define _ACTIVITY_1_H_

#define F_CPU 16000000UL 
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
/**
 * @brief Macro definitions
 * 
 */

#define LED_ON 	(0x01)			/**< LED state HIGH */
#define LED_OFF	(0x00)			/**< LED state LOW */
#define LED_PORT (PORTB)    /**< LED Port Number */
#define LED_PIN  (PORTB0)   /**< LED Pin number  */
#define BUTTON_SENSOR_PORT  (PORTD) /**< Button sensor Port number  */
#define HEATER_SENSOR_PORT  (PORTD) /**< HEATER Port number  */
#define BUTTON_SENSOR_PIN  (PORTD0) /**< Button sensor Pin number  */
#define HEATER_SENSOR_PIN  (PORTD1) /**< HEATER Pin number  */
#define BUTTON_SENSOR_ON 	!(PIND & 1<<PD0)	/**< Button sensor state HIGH */
#define HEATER_SENSOR_ON	!(PIND & 1<<PD1)	/**< Heater state HIGH */
#define SET_PORTB0  DDRB |= (1<<PORTB0) /** PortB0 as output */
#define SET_PD0_AND_PD1  PORTD |= (1<<PORTD1)|(1<<PORTD0) /** PD0 and PD1 as pullup */
#define SET_PORTD  DDRD = 0x00 /** PortD as input  */

/**
 * @brief  Function is to initialize all peripherals
 * 
 */
void init(void);

/**
 * @brief  Function is to change the state of the LED ON and OFF
 * 
 * @param state which is either ON or OFF
 */

void Change_LED_State(uint8_t state);

/**
 * @brief  Function to check if person is seated or not through button sensor
 * 
 */

void buttonsensorinput(void);

/**
 * @brief  Function  to check if person is turned on heater or not
 * 
 */

void heatersensorinput(void);

/**
 * @brief Function is for LED Actuator status
 * 
 */

void LED_actuatorstatus(void);

#endif 
