/**************************************************************************  
Exersise7.5: Rewrite the postfix calculator of Chapter4 to use scanf and/or scanf to do the input and number conversion.
***************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXOP 100
#define NUMBER '0'

int getop(char s[]);
void push(double f);
double pop(void);

/* reverse Polish calculator */

main()
{
	int type;
	double op1, op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF) {
	    switch(type){
	    case NUMBER:
		sscanf(s, "%lf", &op1);
		push(op1);
		break;
	    case '+':
		push(pop() + pop());
		break;
	    case '*':
		push(pop() * pop());
		break;
	    case '-':
		op2 = pop();
		push(pop() - op2);
		break;
	    case '/':
		op2 = pop();
		if(op2 != 0.0)
			push(pop() / op2);
		else
			printf("error: zero division \n");
		break;
	    case '\n':
			printf("\t%.8g\n", pop());
		break;
	    default:
		printf("error: unknown command %s\n", s);
		break;
	    }
	}
	return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if(sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getop(char s[])
{
	double d;

	while((s[0] = getchar()) == ' ' || s[0] == '\t')
		;
	if(s[0] == '\n') {
		s[1] = '\0';
		return s[0];
	}
	ungetc(s[0], stdin);
	if(scanf("%s", s) == EOF)
		return EOF;
	if(sscanf(s, "%lf", &d) == 1)
		return NUMBER;
	else
		return s[0];
}
