/* Ex4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling a recursive routine.************************************************************/

#include<stdio.h>
#include<math.h>
#define INT_MIN 'A'
/* itoa: convert n to characters in s" recursive" */

void itoa(int n, char s[]);
main()
{
	int n;
	char buff[20];
	scanf("INT_MIN: %d\n", &n);
	itoa(n, buff);
	printf("Buffer : %s\n", buff);

return 0;
}

void itoa(int n, char s[])
{
	static int i;

	if(n/10)
	{
	itoa(n/10, s);
	}
	else
	{
	i = 0;
	if(n < 0)
		s[i++] = '-';
		}
	s[i++] = abs(n) %10 + '0';
	s[i] ='\0';

}
