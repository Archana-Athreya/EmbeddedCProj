#include "Activity_1.h"
#include "Activity_3.h"

void initPWM(void)
{
    TCCR1A=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);//using timer1
    TCCR1B=(1<<WGM12)|(1<<CS11)|(1<<CS10);//64 prescale
    DDRB|=(1<<PB1);
}
