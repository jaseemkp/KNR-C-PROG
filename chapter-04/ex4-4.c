/******** add commands to print the top element of the stack without popping,to duplicate it, and to swap the top two elements.add a command to clear the stack ********/

#include<stdio.h>
#include<string.h> /* for atof() */
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0'/* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);
void showTop(void);
void duplicate(void);
void swapitems(void);
void clearstack();

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

int getch(void);
void ungetch(int);

/*************** getop: get next character or numeric operand ************/

int getop(char s[])
{
	int i, c;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t')/* skip white space****/
		;
	s[1] = '\0';
	i = 0;
	if(!isdigit(c) && c != '.' && c !='-')
		return c;	/* not a number but may contain unary minus */
	if(c == '-')
		if(isdigit(c = getch()) || c =='.')
			s[i++] == c;
		else if(c != EOF)
			{	ungetch(c);
				return'-';
		}
	if(isdigit(c))	/* collect integer part */
		while(isdigit(s[++i] = c = getch()))
			;
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
