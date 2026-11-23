
}#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define RS PB0
#define EN PB1

// Enable pulse
void lcd_enable(void)
{
    PORTB |= (1 << EN);
    _delay_ms(1);
    PORTB &= ~(1 << EN);
    _delay_ms(1);
}

// Send 4-bit data
void lcd_nibble(unsigned char data)
{
    PORTB = (PORTB & 0x0F) | (data & 0xF0);
    lcd_enable();
}

// Send command
void lcd_command(unsigned char cmd)
{
    PORTB &= ~(1 << RS);
    lcd_nibble(cmd & 0xF0);
    lcd_nibble(cmd << 4);
    _delay_ms(2);
}

// Send character
void lcd_data(unsigned char data)
{
    PORTB |= (1 << RS);
    lcd_nibble(data & 0xF0);
    lcd_nibble(data << 4);
    _delay_ms(2);
}

// Display string
void lcd_string(char *str)
{
    while(*str)
    {
        lcd_data(*str++);
    }
}

// LCD initialization
void lcd_init(void)
{
    DDRB = 0xFF;
    _delay_ms(20);

    PORTB &= ~(1 << RS);

    lcd_nibble(0x30);
    _delay_ms(5);
    lcd_nibble(0x30);
    _delay_ms(1);
    lcd_nibble(0x30);
    _delay_ms(1);
    lcd_nibble(0x20);

    lcd_command(0x28);
    lcd_command(0x0C);
    lcd_command(0x06);
    lcd_command(0x01);
}

// Main function
int main(void)
{
    DDRD &= ~(1 << PD0);   // Push button as input
    PORTD |= (1 << PD0);   // Enable internal pull-up

    lcd_init();

    while(1)
    {
        lcd_command(0x01);

        if(!(PIND & (1 << PD0)))
        {
            lcd_command(0x80);
            lcd_string("SWITCH PRESSED");
        }
        else
        {
            lcd_command(0x80);
            lcd_string("SWITCH RELEASED");
        }

        _delay_ms(100);
    }

    return 0;
}
