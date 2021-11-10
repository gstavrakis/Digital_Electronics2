# Digital_Electronics2

# Lab 7: George Stavrakis

Link to this file in your GitHub repository:

[https://github.com/your-github-account/repository-name/lab_name](https://github.com/...)

### Analog-to-Digital Conversion

1. Complete table with voltage divider, calculated, and measured ADC values for all five push buttons.

   | **Push button** | **PC0[A0] voltage** | **ADC value (calculated)** | **ADC value (measured)** |
   | :-: | :-: | :-: | :-: |
   | Right  | 0&nbsp;V | 0   |  |
   | Up     | 0.495&nbsp;V | 101 |  |
   | Down   | 1.203&nbsp;V      | 246    | 256 |
   | Left   | 1.97&nbsp;V      |  403   | 409 |
   | Select | 3.18&nbsp;V      |  651   | 639 |
   | none   | 5&nbsp;V      |  1023   | 1023 |

2. Code listing of ACD interrupt service routine for sending data to the LCD/UART and identification of the pressed button. Always use syntax highlighting and meaningful comments:

```c
/**********************************************************************
 * Function: ADC complete interrupt
 * Purpose:  Display value on LCD and send it to UART.
 **********************************************************************/
ISR(ADC_vect)
{
    uint16_t value = 0;
    char lcd_string[4] = "0000";

    value = ADC;                  // Copy ADC result to 16-bit variable
    itoa(value, lcd_string, 10);  // Convert decimal value to string

    // WRITE YOUR CODE HERE
    if (value==0)
    {   
        lcd_gotoxy(10, 1);
        lcd_puts("     ");
        lcd_gotoxy(10, 1);
        lcd_puts("Right");
    }
    
    if (value>=97 && value<=98)
    {
        lcd_gotoxy(10, 1);
        lcd_puts("    ");
        lcd_gotoxy(10, 1);
        lcd_puts("Up");
    }
    
    if(value>=256 && value<=257)
    {
        lcd_gotoxy(10, 1);
        lcd_puts("    ");
        lcd_gotoxy(10, 1);
        lcd_puts("Down");
    }
    
    if(value==409)
    {
        lcd_gotoxy(10, 1);
        lcd_puts("    ");
        lcd_gotoxy(10, 1);
        lcd_puts("Left");
    }   
    
     if(value>=639 && value<=640)
     {
         lcd_gotoxy(10, 1);
         lcd_puts("      ");
         lcd_gotoxy(10, 1);
         lcd_puts("Select");
     }  
     
      if(value==1023)
      {
          lcd_gotoxy(10, 1);
          lcd_puts("      ");
          lcd_gotoxy(10, 1);
          lcd_puts("none");
      } 

}
```

### UART communication

1. (Hand-drawn) picture of UART signal when transmitting three character data `De2` in 4800 7O2 mode (7 data bits, odd parity, 2 stop bits, 4800&nbsp;Bd).

   ![CamScanner 11-10-2021 11 26](https://user-images.githubusercontent.com/91612258/141098859-0fc1e7a8-0ecf-46bc-b029-91c997257deb.jpg)


2. Flowchart figure for function `uint8_t get_parity(uint8_t data, uint8_t type)` which calculates a parity bit of input 8-bit `data` according to parameter `type`. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   

### Temperature meter

Consider an application for temperature measurement and display. Use temperature sensor [TC1046](http://ww1.microchip.com/downloads/en/DeviceDoc/21496C.pdf), LCD, one LED and a push button. After pressing the button, the temperature is measured, its value is displayed on the LCD and data is sent to the UART. When the temperature is too high, the LED will start blinking.

1. Scheme of temperature meter. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![lab7](https://user-images.githubusercontent.com/91612258/141098900-edb7ba12-4cff-4cff-88f9-9268a80108a5.png)

