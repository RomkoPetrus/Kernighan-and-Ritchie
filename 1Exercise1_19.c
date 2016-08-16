#include <stdio.h>
#define MAXLINE 1000

int getline();
void copy();
void reverse();

int main(void)
{
	int len=0;
	int max=0;
	char line[MAXLINE];
	char longest[MAXLINE];

	while ((len=getline(line, MAXLINE))>0)
	{
		// вилучає кінцеві пробіли і табуляцію
		while (line[len-2]==' ' || line[len-2]=='\t')
		{
			line[len-2]=line[len-1];
			line[len-1]=line[len];
			len--;
		}
		
		if (len>max)
		{			
			max=len-1;
			copy(longest, line);
		}
	}

	if (max>0)
	printf("max: %d\n", max);
	printf("??%s\n", longest);

	reverse(longest, max);

	printf("max: %d\n", max);
	printf("%s\n", longest);

	return 0;
}

int getline(char s[], int lim)
{
	int i, c;
	for (i=0; i<lim && (c=getchar()) != EOF && c != '\n'; ++i)
		s[i]=c;
	if (c=='\n')
	{
		s[i]=c;
		++i;
	}
	s[i]='\0';

	return i;
}

void copy (char to[], char from[])
{
	int i=0;
	while ((to[i]=from[i]) != '\0')
		++i;
}

void reverse (char array[], int lenth)
{
	int x;
	for (int i; i<=lenth/2; i++)
	{
		x=array[i];
		array[i]=array[lenth-i];
		array[lenth-i]=x;
	}

}

