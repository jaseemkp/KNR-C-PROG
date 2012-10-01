#include <stdio.h>

main()
{
	int blks, tabs, nwlns;
	int c;
	int done = 0;
	int lastchar = 0;
	blks = 0;
	tabs = 0;
	nwlns = 0;

 	while((c = getchar()) != EOF){
		
		if(c == ' ')
		++blks;

		if(c == '\t')
		++tabs;
		
		if(c == '\n')
		++nwlns;
		if(c == EOF)
		{
		if(lastchar != '\n')
		{
		++nwlns;
		}
	done = 1;
	}
	lastchar = c;
}	
	printf("Blks: %d\nTabs: %d\nLines: %d\n", blks, tabs, nwlns);
}

	
