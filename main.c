/**
 * @file main.c
 * @author Archana N N (archanaathreya2000@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Header.h"

/**
 * @brief This is the main function from where execution starts
 * 
 * @return int return 0 if the program is executed successfully
 */
int main()
{
/**
 * @brief PORTB is used for output and PORTD is used for two inputs
 * 
 */

 /* Configure LED Pin */
    DDRB|=(1<<PB0);
    DDRD&=~(1<<PD0);
    DDRD&=~(2<<PD0);
 /* set bit */
    PORTD|=(1<<PD0);
    PORTD|=(2<<PD0);


    while(1)
    {
        /* If both the input switches are pressed turn ON the LED else keep it OFF */
        if(!(PIND&(1<<PD0)) && !(PIND&(2<<PD0)))
            {

                PORTB|=(1<<PB0);
            }
            else
                {
                    PORTB&=~(1<<PB0);
                }

    }
return 0;
}
