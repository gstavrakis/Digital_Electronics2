# Digital_Electronics2
# Lab 6: George Stavrakis

Link to this file in your GitHub repository:

https://github.com/gstavrakis/Digital_Electronics2


### LCD display module

1. In your words, describe what ASCII table is.
   * ASCII table: The ascii table is an array that contains characters and their display in 7-bits.

2. (Hand-drawn) picture of time signals between ATmega328P and LCD keypad shield (HD44780 driver) when transmitting three character data `De2`.

   ![CamScanner 11-02-2021 23 56_1](https://user-images.githubusercontent.com/91612258/139963287-ec998d1f-e079-451c-b7d1-da64664d83b3.jpg)



### Stopwatch

1. Flowchart figure for `TIMER2_OVF_vect` interrupt service routine which overflows every 16&nbsp;ms but it updates the stopwatch LCD approximately every 100&nbsp;ms (6 x 16&nbsp;ms = 100&nbsp;ms). Display tenths of a second and seconds `00:seconds.tenths`. Let the stopwatch counts from `00:00.0` to `00:59.9` and then starts again. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![CamScanner 11-02-2021 23 56_2](https://user-images.githubusercontent.com/91612258/139963273-c206add5-d420-430d-b49f-322a60832422.jpg)
   

### Custom characters

1. Code listing of two custom character definition. Always use syntax highlighting and meaningful comments:

```c
/* Variables ---------------------------------------------------------*/
// Custom character definition
uint8_t customChar[16] = {
  // WRITE YOUR CODE HERE
  0b11111,
	0b10000,
	0b10000,
	0b10000,
	0b10111,
	0b10001,
	0b10001,
	0b11111 //G
  
  0b11111,
	0b10000,
	0b10000,
	0b10000,
	0b11111,
	0b00001,
	0b00001,
	0b11111 //S

};
```


### Kitchen alarm

Consider a kitchen alarm with an LCD, one LED and three push buttons: start, +1 minute, -1 minute. Use the +1/-1 minute buttons to increment/decrement the timer value. After pressing the Start button, the countdown starts. The countdown value is shown on the display in the form of mm.ss (minutes.seconds). At the end of the countdown, the LED will start blinking.

1. Scheme of kitchen alarm; do not forget the supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![lab6](https://user-images.githubusercontent.com/91612258/139963595-20900808-9694-4cc0-b654-a8672af6cd32.png)


