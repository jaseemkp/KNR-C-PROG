#include<unistd.h>
#include<stdio.h>
main()
{
	int get_char(void);


	while((get_char(void)) != EOF)
		putchar(void);
}
/* getchar: unbuffered single character input */

int get_char(void)
{
	char c;
	return(read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}
