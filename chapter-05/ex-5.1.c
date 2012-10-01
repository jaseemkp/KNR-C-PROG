/* As written treats a + or - not followed by a digit as a valid
representation of zero.Fix it to push such a character back on the input  */
#include<stdio.h>
#define BSIZE 10
main()
{
        int i, array[BSIZE], getint(int *pn);
       	int val;
    	
	for(i = 0; i < BSIZE && (val = getint(&array[i])) != EOF; i++)
           printf("array[%d] = %d, \tvalue returned:  (%s)\n", i, array[i], 			val != 0 ? "number" : "not a number");

	return 0;
}


int getch(void);
void ungetch(int);
#include<ctype.h>

int getint(int *pn) /* get next integer from input into *pn */
{
	int c, sign, x;
	
	while(isspace(c = getch())) /* skip white space */
		;
	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c); /* it is not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if(x = (c == '+' || c == '-'))
		c = getch();
	if(!isdigit(c)){
		ungetch(c);
	if(x)
		ungetch((sign == -1) ? '-' : '+');
		return 0;
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if(c != EOF)
		ungetch(c);
		return c;
}
int bufp = 0;
int buf[BSIZE];

int getch(void)
	{
		return bufp > 0 ? buf[--bufp] : getchar();
	}
void ungetch(int c)
	{
		if(bufp < BSIZE)
			buf[bufp++] = c;
	}



