
#include "Header.h"
int main()
{

    DDRB|=(1<<PB0);
    DDRD&=~(1<<PD0);
    DDRD&=~(2<<PD0);
    PORTD|=(1<<PD0);
    PORTD|=(2<<PD0);


    while(1)
    {
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
