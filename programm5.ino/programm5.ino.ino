#define F_cpu 160000000UL
#include<avr/io.h>
#include<util/delay.h>
int main(void)
{
  DDRB|=(1<<PB0)|(1<<PB1)
      |(1<<PB2)|(1<<PB3);
  while(1)
  {
    PORTB=(1<<PB0)|(1<<PB2);
    _delay_ms(3000);
    PORTB=0*00;
    _delay_ms(2000);
    PORTB=(1<<PB1)|(1<<PB3);
    _delay_ms(3000);
    PORTB=0*00;
    _delay_ms(2000);
  }
}