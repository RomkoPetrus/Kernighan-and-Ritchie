#include <stdio.h>

float power (int);

int main(void)
{
	for (int i=0; i<300; i=i+20)
		printf("F=%d \tC=%0.2f\n", i, power (i));
	return 0;
}

float power (int F)
	{
		float c = 5.0/9.0*(F-32);

		return (c);
	}