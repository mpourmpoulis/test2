#include <avr/io.h>
char x;
int main(void)
{
	DDRA=0xFF;
	DDRC=0x00;
// Αρχικοποίηση PORTB ως output
// Αρχικοποίηση PORTA ως input
	x = 1;
// Αρχικοποίηση μεταβλητής για αρχικά αναμμένο led
	while(1)
	{
		if ((PINC & 0x01)){

			while ((PINC & 0x01)); 
			if (x==128)
				x = 1;
			else
				x = x<<1; 
		}
		else if ((PINC & 0x02)){

			while ((PINC & 0x02)); 
			if (x==1)
				x = 128;
			else
				x = x>>1; 
		}
		else if ((PINC & 0x04)){

			while ((PINC & 0x01)); 
			
				x = 128;
			
		}
		else if ((PINC & 0x08)){

			while ((PINC & 0x08)); 
			
				x = 1;

		}
		PORTA = x;
	}
	return 0;
}
Hello
