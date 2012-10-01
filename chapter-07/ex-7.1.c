/**************************************************************************
Exercise 7.1
Write a program that converts upper case to lower or lower case to upper, depending on the name it is invoked with, as found in argv[0].
***************************************************************************/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	int (*convert[2])(int) = {toupper, tolower} ;
	int c;
	int ch;
	if(argc > 0){
		if(toupper((char)argv[0][0]) == 'U')
			
				c = 0;
		else
				c = 1;
		while((ch = getchar()) != EOF)
			{
			ch = (*convert[c])((char)ch);
			putchar(ch);
			}
	}
	else 
		printf("failed\n");
	return ch;
}			
	
			
			
