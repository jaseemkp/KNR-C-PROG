#include <stdio.h>

#define MAXLINE 1000 /* max input line size */
#define TAB2SPACE 4	/* 4 spaces to a tab */

char line[MAXLINE]; /*current input line */

int getlne(void);

main()
{
	int i, t;
	int spacecount, len;

	while((len = getlne()) > 0)
	{
	spacecount = 0;
	for(i = 0; i < len; i++)
		{
		if(line[i] == ' ')
		 spacecount++; /* increment counter for each space */
		if(line[i] != ' ')
		 spacecount = 0; /* reset counter */
		if(spacecount == TAB2SPACE) /* now we have enpugh spaces 
						to replace them with tab*/
	{
	i -=3; /*same as i = i-3 */
	len -= 3;
	line[i] = '\t';

	for(t =i+1;t < len; t++)
		line[t] = line[t+3];
	spacecount = 0;
	line[len] = '\0';
	}
	}
	printf("%s", line);
	}
	return 0;
}

/* getline: specialized version */

int getlne(void)
{
	int c, i;
	extern char line[];

	for(i = 0; i < MAXLINE -1 && (c = getchar()) != EOF && c != '\n'; ++i)
	line[i] = c;
	
	if(c == '\n')
	{
	line[i] = c;
	++i;
	}
	line[i] = '\0';
	return i;
}
	 
