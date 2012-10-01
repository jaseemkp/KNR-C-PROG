/*EX-5.7: Rewrite readlines to store lines in an array supplied by main, rat* her than calling alloc alloc to maintain storage ************************/

#include<stdio.h>
#include<string.h>

#define MAXLINES 5000 /* max lines to be sorted */
#define MAXLEN 5000 /* max length of line */

char *lineptr[MAXLINES]; /* pointer to text line */


void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* sort input lines */

main()
{
	int nlines; /* number of input lines read */

		if ((nlines = readlines(lineptr, MAXLINES)) > 0){
			qsort(lineptr, 0, nlines-1);
			writelines(lineptr, nlines);
			return 0;
		} else {
			printf("error: input too big to sort\n");
			return 1;
			}
}

int get_line( char *s, int lim)
{
	int  c;
	char *t = s;
	while(--lim > 0 && (c =getchar()) != EOF && c != '\n')
		*s = c;
	if(c == '\n'){
		*s++ = c;
	}
	*s = '\0';
	return s-t;
}

int readlines(char lines[][MAXLEN], int maxlines)
{
	int len, nlines;
	
	nlines = 0;
	while((len = get_line(lines[nlines], MAXLEN)) > 0)
	 if(nlines >= maxlines)
		return -1;
	else
		lines[nlines++][len -1] = '\0';
	return nlines;
}


/* writelines: write output lines */

void writelines(char *lineptr[], int nlines)
{
        int i;
	for(i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	if(left >= right) /* do nothing if array contains */
		return; /* fewer than two elements */
	swap(v, left,(left + right)/2);
	last = left;
	for(i = left+1; i <= right; i++)
		if(strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/* swap: interchanging v[i] and v[j] */

void swap(char *v[], int i, int j)
{
	char *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}





