#include <stdio.h>

#define MAXLINE 1000 /* maximum input line */

int  getlne(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
main()
{
	int len;
	int max;
 	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;

	while((len = getlne(line, MAXLINE)) > 0)
	{
	printf("%d %s", len, line);

	if(len > max)
	{
		max = len;
		copy(longest, line);
	}
	}
	if(max > 0)
	{
	printf("Longest is %d characters:\n%s", max, longest);
	}
	printf("\n");
	return 0;
}

/* getline: read a line into s, return length */

	int getlne(char s[], int lim)
{
	int c, i, j;
	
	for(i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; ++i)
	{
	if(i < lim - 1)
	{
		s[j++] = c;
	}
}
if(c == '\n')
{
	if(i <= lim - 1)
	{
		s[j++] = c;
	}
	++i;
	}
s[j] = '\0';
return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while((to[i] = from[i]) != '\0')
 	{
		++i;
	}
}  
