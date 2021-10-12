# Digital_Electronics2

# Lab 3: George Stavrakis


### Data types in C

1. Complete table.

| **Data type** | **Number of bits** | **Range** | **Description** |
| :-: | :-: | :-: | :-- | 
| `uint8_t`  | 8 | 0, 1, ..., 255 | Unsigned 8-bit integer |
| `int8_t`   | 8 | -127,..0..,127 | Signed 8-bit integer |
| `uint16_t` | 16 | 0,..,65535 | Unsigned 16-bit integer |
| `int16_t`  | 16 | -32767,..0..,32767 | Signed 16-bit integer |
| `float`    | 8 | -3.4e+38, ..., 3.4e+38 | Single-precision floating-point |
| `void`     | 0 |  | Empty data type |


### GPIO library

1. 
   * Function declaration
     Function declaration is a prototype where we can define the function name and type and its parameters without a function body.
   * Function definition
     In function definition where we can define the function name and type and its parameters with a function body.
     

2. Part of the C code listing with syntax highlighting, which toggles LEDs only if push button is pressed. Otherwise, the value of the LEDs does not change. Use function from your GPIO library. Let the push button is connected to port D:

```c
    // Configure Push button at port D and enable internal pull-up resistor
    // WRITE YOUR CODE HERE
    DDRD = DDRD & ~(1<<PD5);
    PORTD = PORTD | (1<<PD5);

    // Infinite loop
    while (1)
    {
        // Pause several milliseconds
        _delay_ms(BLINK_DELAY);

        // WRITE YOUR CODE HERE
        if(PIND.5=0)
        {
          PORTC ^= (1<<PC5); // Let's say that the LED is at PORTC.5
        }
    }
```


### Traffic light

1. Scheme of traffic light application with one red/yellow/green light for cars and one red/green light for pedestrians. Connect AVR device, LEDs, resistors, one push button (for pedestrians), and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   
