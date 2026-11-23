#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    unsigned char count = 0;

    DDRB = 0x0F;          // PB0-PB3 as output (LEDs)
    DDRD &= ~(1 << PD0);  // PD0 as input (Button)

    PORTD |= (1 << PD0);  // Enable pull-up resistor

    while(1)
    {
        if(!(PIND & (1 << PD0)))
        {
            _delay_ms(50);  // Debouncing

            if(!(PIND & (1 << PD0)))
            {
                count++;

                if(count > 15)
                    count = 0;

                PORTB = (PORTB & 0xF0) | count;

                while(!(PIND & (1 << PD0)));
                _delay_ms(50);
            }
        }
    }

    return 0;
}
