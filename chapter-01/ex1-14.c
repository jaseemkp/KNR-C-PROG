#include <stdio.h>

#define NUM_CHARS 256

main()

	int c;
	long freqarr[NUM_CHARS + 1];
	
	long thisval = 0;
	long maxval = 0;
	int thisidx = 0;

	for(thisidx = 0; thisidx <= NUM_CHARS; thisidx++)
	{
		freqarr[thisidx] = 0;
	}
	while((c= getchar()) != EOF)
	{
		if(c < NUM_CHARS)
		{
			thisval = ++freqarr[c];
			if(thisval > maxval)
			{
				maxval = thisval;
			}
		}
	}
	for(thisval = maxval 


 
	
