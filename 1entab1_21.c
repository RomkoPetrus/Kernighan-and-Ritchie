#include <stdio.h>

#define TAB 8

int main(void)
{	
	int i=0;
	int k=0;
	char c;
	while ((c=getchar())!=EOF){
		i++;		
		if (c=='\n'){
			i=0; 				
		}
		// This is a counter of white spaces.
		if (c==' ' && i%TAB!=0)
			k++;

		if (c!=' ' && k==0)
			putchar(c);

		if (c!=' ' && k>0){
			while (k!=0){
				putchar('*');
				k--; 				
			}
			putchar(c);		
		}		
		if (c==' ' && i%TAB==0){
			k=0;
			putchar('\t');
		}			
	}	
}