#define F_CPU 160000000UL
#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
  DDRB|=(1<<PB5);
  DDRC|=(1<<PC3);
  while(1)
  {
    PORTB^=(1<<PC3);
    _delay_ms(500);
    if (PORTB&&(1<<PC3))
    {
      PORTC=(1<<PC6);

    }
  }
 
}
