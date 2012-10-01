/***********EX4.1:  Write function strindex(s,t) which returns the position of rightmost occurance of t in s,or -1 if hter is none.**************** */

#include<stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int geTline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /*pattern to search for */

main()
{
	char line[MAXLINE];

	while(geTline(line, MAXLINE) > 0)
		printf("right most occurence of  pattern: %d\n", strindex(line, pattern));
}

/* getline: get line into s, return length */

int geTline(char s[], int lim)
{
	int c, i;
	
	i = 0;
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
		s[i] = '\0';
		return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k;
	for(i = 0; s[i] != '\0' ; i++)
		{
		for(j = i, k=0; t[k] !='\0' && s[j] == t[k]; j++, k++)
		;
		if(k > 0 && t[k] == '\0')
			return i;
		}
		return -1;
}

