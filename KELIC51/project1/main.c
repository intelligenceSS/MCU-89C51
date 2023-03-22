#include <REG51.H>

void delay(unsigned i)
{
    unsigned j;
    for (; i > 0; i--)
        for (j = 244; j > 0; j--)
			;
}

void main()
{
    unsigned char x;
    unsigned char n;
    while (1)
    {
        x = 0x01;
        for (n = 0; n < 8; n++)
        {
            P1 = ~x;
            delay(200);
            x=x<<1;
        }
    }
}