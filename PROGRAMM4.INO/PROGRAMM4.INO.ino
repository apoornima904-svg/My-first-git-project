#define F_CPU 160000000UL
#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
 DDRB|=(1<<PB5);
 DDRC|=(1<<PC3);
 while(1)
 {
  PORTB|=(1<<PB5);
  if(PINB &(1<<PB5))
  {
    PORTC|=(1<<PC3);

  }
  else
  {
    PORTC &~(1<<PC3);

  }
  _delay_ms(1000);
  PORTB &=~(1<<PC3);
  if(PINB &(1<<PB5))
  {
    PORTC|=(1<<PB3);
  }
  else
  {
    PORTC &=~(1<<PC3);
  }
  _delay_ms(1000);
  PORTB &=~(1<<PB5);
  if(PINB &(1<<PC5))
  {
    PORTC|=(1<<PC3);
  }
  else
  {
    PORTC &=~(1<<PC3);
  }
  _delay_ms(1000);
 }
}

