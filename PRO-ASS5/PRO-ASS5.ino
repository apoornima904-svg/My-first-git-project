#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0x07;     // Set PB0, PB1, PB2 as output

    while(1)
    {
        PORTB = 0x01;    // RED LED ON
        _delay_ms(5000);

        PORTB = 0x02;    // YELLOW LED ON
        _delay_ms(2000);

        PORTB = 0x04;    // GREEN LED ON
        _delay_ms(5000);
    }

    return 0;
}