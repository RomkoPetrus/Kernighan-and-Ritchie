#include <stdio.h>

#define SIZE 50

int main(void)
{
	int i=0;
	char c;

	while((c=getchar())!=EOF){
		i++;
		if(i==SIZE-1){
			putchar(c);
			i++;
			c='\n';			
		}
		if(c=='\n')
			i=0;		

		putchar(c);
	}
	return 0;
}