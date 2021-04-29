/**
 * @file activity4.h
 * @author Archana.N.N(archanaathreya2000@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef _ACTIVITY_4_H_
#define _ACTIVITY_4_H_
/**
 * @brief For USART Initialisation
 * 
 * @param ubrreg_value 
 */
void initUSART(uint16_t ubrreg_value);

/**
 * @brief Function to send data using USART
 * 
 * @param temp_value 
 */

void UARTsend(char temp_value);
#endif