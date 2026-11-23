#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0x0F;       // Set PB0-PB3 as output

    while(1)
    {
        PORTB = 0x01;  // LED 1 ON
        _delay_ms(500);

        PORTB = 0x02;  // LED 2 ON
        _delay_ms(500);

        PORTB = 0x04;  // LED 3 ON
        _delay_ms(500);

        PORTB = 0x08;  // LED 4 ON
        _delay_ms(500);
    }

    return 0;
}
