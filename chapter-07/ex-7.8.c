/*************************************************************************** EX-7.8: Write a progm to print a set of files, starting each new one on a new page, with a title and a running page count for each file.
***************************************************************************/
#include<stdio.h>

#define PAGELENGTH 20
#define HEADERLENGTH 2
#define FOOTERLENGTH 1

int printpage(char *filename);

main(int argc, char *argv[])
{
	int x;

	for(x = 1; x < argc; x++) {
	   if(printpage(argv[x]) == 0) {
		fprintf(stderr, "Error printing %s\n", argv[x]);
		return 1;
	   }
	}
	
	return 0;
}

#define MAXLINE 100
/* printpage: print each page separately*/
int printpage(char *filename)
{
	FILE *fp;
	char line[MAXLINE];
	int row;
	long pagenumber;

	fp = fopen(filename, "r");
	if(fp == NULL)
	    return 0;
	pagenumber = 1;
	while(!feof(fp)) {
		printf("=file: %s = page no: %ld\n====================\n", filename, pagenumber);
		printf("\n");
		for(row = HEADERLENGTH; row < PAGELENGTH - FOOTERLENGTH; row				++) {
		if(fgets(line, MAXLINE, fp) == NULL)
			printf("\n");
		else
			printf("%s", line);
		}
		printf("\n");
		pagenumber++;
	}
	fclose(fp);
	
	return pagenumber;
}
