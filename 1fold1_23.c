#include <stdio.h>
#include <stdbool.h>

#define SIZE 2345

void getLine (void);

unsigned int i=0;
char c, out[SIZE];

int main(void)
{	
	bool in_quotes=false, ic=false, is=false;
	unsigned int x=0, y=0;
	const char a='*', b='/';
	
	while((c=getchar())!=EOF && i<SIZE){
		if(c=='"')
		in_quotes=!in_quotes;

		// check /*---*/
		if(c==a && out[i-1]==b && !is && !in_quotes){
			if(ic)
				continue;
			ic=!ic; x=i-1; y=i+1; 
		}
		else if(c==b && out[i-1]==a && ic && !in_quotes && i>y){
			i=x; x=0; y=0; ic=!ic; 
			continue;
		}
		// check //---
		if(c==b && out[i-1]==b && !ic && !in_quotes){
			if(is)
				continue;
			is=!is; x=i-1; 			
		}
		else if(c=='\n' && is && !in_quotes){
			i=x; x=0; is=!is; 			
		}
		out[i]=c;
		i++;	
	}
	out[i]='\0';
	printf("\noutput=\n%s\n", out);		
	return 0;		
}


