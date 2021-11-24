#include <avr/io.h>
#include <stdlib.h>
#include "uart.h"
#include "gpio.h"
#include <util/delay.h>

#define trigPin PB5

#define echoPin PB4

#define led PB3

#ifndef F_CPU
#define F_CPU 16000000
#endif

int main(void)
{
   uart_init(UART_BAUD_SELECT(9600, F_CPU));
   
   GPIO_config_output(&DDRB, trigPin);
   
   GPIO_config_input_pullup( &DDRB, echoPin);
   
   GPIO_config_output(&DDRB, led);
   
   while(1)
   {
       GPIO_write_low(&PORTB, trigPin);      
       _delay_us(2);
       
       GPIO_write_high(&PORTB,trigPin);
       _delay_us(10);
       
       GPIO_write_low(&PORTB,trigPin);
   }
   
   return 0;
}

/*#define trigPin 13

#define echoPin 12

#define led 11

void setup()

{ Serial.begin (9600);

pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT);

pinMode(led, OUTPUT);

}

void loop()

{ long duration, distance;

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = (duration/2) / 29.1;

if (distance < 10)

{ digitalWrite(led,HIGH);

}

else {

digitalWrite(led,LOW);

}

Serial.print(distance);

Serial.println(" cm");

delay(500);

}\*