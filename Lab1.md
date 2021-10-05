# Digital_Electronics2

1. * '|' = OR operator and its result will be always 1 unless we have a 0 0 situation that is 0 as well
2. * '&' = AND operator and if there is a 0 in our situation it will always be 0 and if we have 1 and 1 the result will be 1
3. * '^' = XOR operator 
4. * '~' = tilde operator that it reverses the bit, so if we have 0 we get 1 and if we have 1 we get 0
5. * '<<' = slide the bits left one position
6. * '>>' = slide the bits right one position

| **b** | **a** |**b or a** | **b and a** | **b xor a** | **not b** |
| :-: | :-: | :-: | :-: | :-: | :-: |
| 0 | 0 | 0 | 0 | 0 | 1 |
| 0 | 1 | 1 | 0 | 1 | 1 |
| 1 | 0 | 1 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 | 0 |

Morse Code

#define LED_GREEN   PB5 
#define DOT 1000        
#define DASH 3000
#ifndef F_CPU           
                        
#define F_CPU 16000000 
#endif               

#include <util/delay.h> 
#include <avr/io.h>     

int main(void)
{
    DDRB = DDRB | (1<<LED_GREEN);
    PORTB = PORTB & ~(1<<LED_GREEN);

    
    while (1)
    {
        PORTB = PORTB ^ (1<<LED_GREEN);
        // Pause several milliseconds
        _delay_ms(DOT);
        PORTB = PORTB ^ (1<<LED_GREEN);
        _delay_ms(DASH);

    }
    
    return 0;
}
