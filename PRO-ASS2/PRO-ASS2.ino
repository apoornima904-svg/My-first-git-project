#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0xFF;       // Set PORTB as output

    while(1)
    {
        PORTB = 0xFF;  // LED ON
        _delay_ms(500);

        PORTB = 0x00;  // LED OFF
        _delay_ms(500);
    }

    return 0;
}
