// write getfloat, the floating point analog of getint.

#include<stdio.h>
#define BSIZE 10
main()
{
        int i;
	float array[BSIZE];
	int getfloat(float *pn);
	int val;
    	
	for(i = 0; i < BSIZE && (val = getfloat(&array[i])) != EOF; i++)
           printf("array[%d] = %f, \tvalue returned:  (%s)\n", i, array[i], 			val != 0 ? "number" : "not a number");

	return 0;
}


int getch(void);
void ungetch(int);
#include<ctype.h>

int getfloat(float *pn) /* get next integer from input into *pn */
{
	int c, sign;
	float pw;
	
	while(isspace(c = getch())) /* skip white space */
		;
	if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
		ungetch(c); /* it is not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0.0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (c - '0');
	if(c == '.')
		c = getch();
	for(pw = 1.0;isdigit(c); c = getch()){
		*pn = 10.0 * *pn + (c - '0');
		pw *= 10.0;
	}
	*pn *= sign / pw;
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



