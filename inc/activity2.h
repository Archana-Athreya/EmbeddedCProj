/**
 * @file activity2.h
 * @author Archana.N.N(archanaathreya2000@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _ACTIVITY_2_H_
#define _ACTIVITY_2_H_
/**
 * @brief Function  to initialise ADMUX and ADCSRA registers
 * 
 */

void initADC();
/**
 * @brief  Function to select particular MUX Channel
 * 
 * @param channel 
 * @return uint16_t 
 */

uint16_t ReadADC(uint8_t channel);

#endif 
