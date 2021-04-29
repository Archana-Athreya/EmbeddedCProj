#include "activity1.h"
#include "activity2.h"
#define CONVERSION_INCOMPLETE  (ADCSRA & (1<<ADIF))

void initADC()
{
    /* Select Vref=AVcc*/
    ADMUX |= (1<<REFS0);
    
    ADCSRA=(1<<ADEN)|(7<<ADPS0);
}
uint16_t ReadADC(uint8_t ch)
{

    /*To select mux channel enabling last 3 bits*/
    ADMUX &= 0xF8;
    /*single conversion mode*/
    ch &= 0x07;
    ADMUX |= ch;
    ADCSRA |= (1<<ADSC);
    /* wait until ADC conversion is complete*/
    while(!(CONVERSION_INCOMPLETE));
    ADCSRA|=(1<<ADIF);
    return (ADC);

 
}
