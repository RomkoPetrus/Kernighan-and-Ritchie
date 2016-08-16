#include <stdio.h>

int main(void){
	const int tab=6;
	char c, i=0;

	while ((c=getchar())!= EOF){
		i++;
		if (c=='\n'){
			i=0;
			putchar(c);
		}
		else if (c=='\t'){			
			while ((i%(tab+1)) !=0){
				putchar('*');
				i++;
			}
		}
		else 
			putchar(c);				
	}
			
	return 0;
}