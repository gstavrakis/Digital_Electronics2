# Digital_Electronics2
# Lab 5: George Stavrakis

Link to your `Digital-electronics-2` GitHub repository:

https://github.com/gstavrakis/Digital_Electronics2


### 7-segment library

1. In your words, describe the difference between Common Cathode and Common Anode 7-segment display.
   * CC SSD: In common cathode 7-segment display the LEDs are connected to the ground and we need logical 1 to turn them on.
   * CA SSD: In common anode 7-segment display the LEDs are connected to logical 1 and we need to connect them to ground to turn them on.

2. Code listing with syntax highlighting of two interrupt service routines (`TIMER1_OVF_vect`, `TIMER0_OVF_vect`) from counter application with at least two digits, ie. values from 00 to 59:

```c
/**********************************************************************
 * Function: Timer/Counter1 overflow interrupt
 * Purpose:  Increment counter value from 00 to 59.
 **********************************************************************/
ISR(TIMER1_OVF_vect)
{
    // WRITE YOUR CODE HERE
    cnt0++;
    if (cnt0 > 9)
    {
      cnt1++;
      cnt0=0;
      SEG_update_shift_regs(cnt0, 0);
      SEG_update_shift_regs(cnt1, 1);
    }

}
```

```c
/**********************************************************************
 * Function: Timer/Counter0 overflow interrupt
 * Purpose:  Display tens and units of a counter at SSD.
 **********************************************************************/
ISR(TIMER0_OVF_vect)
{
    static uint8_t pos = 0;

    // WRITE YOUR CODE HERE
    pos++;

}
```

3. Flowchart figure for function `SEG_clk_2us()` which generates one clock period on `SEG_CLK` pin with a duration of 2&nbsp;us. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![248466291_5139089206120697_1136065458897827901_n](https://user-images.githubusercontent.com/91612258/139038358-d5d9ec13-c77e-49c4-93ca-9191719287af.jpg)




### Kitchen alarm

Consider a kitchen alarm with a 7-segment display, one LED and three push buttons: start, +1 minute, -1 minute. Use the +1/-1 minute buttons to increment/decrement the timer value. After pressing the Start button, the countdown starts. The countdown value is shown on the display in the form of mm.ss (minutes.seconds). At the end of the countdown, the LED will start blinking.

1. Scheme of kitchen alarm; do not forget the supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![lab5](https://user-images.githubusercontent.com/91612258/139036282-d60639b3-d37e-4e23-9c2f-e25dc16bdc69.png)

