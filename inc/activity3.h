/**
 * @file activity3.h
 * @author Archana.N.N(archanaathreya2000@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _ACTIVITY_3_H_
#define _ACTIVITY_3_H_
/**
 * @brief Initialistion Function for Pulse Width Modulation 
 * 
 */
void initPWM(void);
/**
 * @brief Function to set output of adc using pwm
 * 
 * @param temp from ADC
 * @return char will be input for serial communication
 */
char pwmout(uint16_t temp);
#endif 
