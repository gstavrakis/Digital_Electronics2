#include <avr/io.h>
#include <MrLcd/MrLCDmega32.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>

static volatile int pulse = 0;
static volatile int i = 0;

int main(void)
{
    int16_t count_a = 0;
    char show_a[16];
    DDRD = 0b11111011;
    _delay_ms(50);


    GICR |= 1<<INT0;
    MCUCR |= 1<<ISC00;

    sei();
    
    while(1)
    {
        PORTD |= 1<<PIND0;
        _delay_us(15);

        PORTD &= ~(1<<PIND0);
        count_a = pulse/58;

           }
}

ISR(INT0_vect)
{
    if(i == 0)
    {
        TCCR1B |= 1<<CS10;
        i = 1;
    }
    else
    {
        TCCR1B = 0;
        pulse = TCNT1;
        TCNT1 = 0;
        i = 0;
    }
}