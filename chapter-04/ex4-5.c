/******** add access to library like sin, exp,and pow ********/

#include<stdio.h>
#include<string.h> /* for atof() */
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0'/* signal that a number was found */
#define IDENTIFIER '1'
int getop(char []);
void push(double);
double pop(void);
void showTop(void);
void duplicate(void);
void swapitems(void);
void clearstack();
void mathname(char s[]);

/******************** reverse Polish calculater *******************/
int main(void)
{
	int type;
	double op2;
	char s[MAXOP];
	while((type = getop(s)) != EOF)
	{
		switch(type){
		case NUMBER:
			push(atof(s));
			break;
		case IDENTIFIER:
			mathname(s);
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
				printf("error: zero divisor\n");
			break;
		case'%':
			op2 = pop();
			if(op2 != 0.0)
				push(fmod(pop(), op2));
			else
				printf("error: zero divisor\n");
 		case'?':
			showTop();
			break;
		case'#':
			duplicate();
			break;
		case'~':
			swapitems();
		case'!':
			clearstack();
			break;
  		case'\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /*next free stack position */
double val[MAXVAL]; /* value stack */

/************** push: push f onto value stack  *****************************/
void push(double f)
{
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}
/*************** pop: pop and return top value from stack *******************/
double pop(void)
{
	if(sp > 0)
		return val[--sp];
	else{
		printf("error: stack empty\n");
		return 0.0;
		}
}

/*print the top element of stack without popping */
void showTop(void)
{
	if(sp > 0)
		printf(" Top of stack : %8g\n", val[sp-1]);
	else
		printf("stack is empty!\n");
}

void duplicate(void)
{
	double temp = pop();

	push(temp);
	push(temp);
}

void swapitems(void)
{
	double item1 = pop();
	double item2 = pop();

	push(item1);
	push(item2);
}

void clearstack(void)
{
	sp = 0;
}

/* maths functions sin, cos,exp, pow */
void mathname(char s[])
{
	double op2;

	if(0 == strcmp(s, "sin"))
		push(sin(pop()));
	else if(0 == strcmp(s, "cos"))
		push(cos(pop()));
	else if(0 == strcmp(s, "exp"))
		push(exp(pop()));
	else if(!strcmp(s, "pow"))
	{
		op2 = pop();
		push(pow(pop(), op2));
	}
	else
		printf("%s is not a supported one.\n", s);
}

int getch(void);
void ungetch(int);

/*************** getop: get next character or numeric operand ************/

int getop(char s[])
{
	int i = 0;
	int c;
	int next;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t')/* skip white space****/
		;
	s[1] = '\0';
	if(isalpha(c))
	{
	i = 0;
	while(isalpha(s[i++] = c))
		c = getch();
	s[i -1] = '\0';
	if(c != EOF)
		ungetch(c);
	return IDENTIFIER;
	}
	if(!isdigit(c) && c != '.' && c !='-')
		return c;	/* not a number but may contain unary minus */
	if(c == '-'){
			next = getch();
		if(!isdigit(next) && next != '.')
		{
			return c;
		}
			c = next;
		}
		else
			c = getch();
		
		while(isdigit(s[++i] = c))
			c =getch();
	if(c == '.') /* collect fraction part */
		while(isdigit(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if(c != EOF)
			ungetch(c);
		return NUMBER;
}	


#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;	/* next free position in buf */

int getch(void) /***************** get a character ********************/
	{
		return (bufp > 0) ? buf[--bufp] : getchar();
	}

void ungetch(int c) /********* push character back on input ************/
	{
		if(bufp >= BUFSIZE)
			printf("ungetch: too many characters\n");
		else
			buf[bufp++] = c;
}
