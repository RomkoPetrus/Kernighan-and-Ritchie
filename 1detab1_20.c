#include <stdio.h>

#define SIZE	500

char string[SIZE], longest[SIZE];
int detab(char array[], int cons);
void copy (char to[], char from[]);

int main(void){
	const int tab=4;
	int lenth, max;
	lenth=max=0;
	while ((lenth=detab(string, tab))>0)
		if (lenth>max){
			max=lenth-1;
			copy(longest, string);
		}

	if (max>0){
		printf("max: %d\n", max);
		printf("[%s]\n", longest);
	}	
	return 0;
}

int detab(char array[], int cons){
	int i, c;
	// одержуємо сторку
	for (i=0; i<SIZE && (c=getchar()) !=EOF && c !='\n'; i++){
		if (c =='\t'){
			for (int j=0; j<cons; j++)
				array[i+j]=' ';

				i=i+cons-1;
		}
		else array[i]=c;				
	}
	if (c=='\n'){
		array[i]=c;
		i++;
	}
	array[i]='\0';
	return i;
}

void copy (char to[], char from[]){
	int i=0;
	while ((to[i]=from[i]) != '\0')
		++i;
}
