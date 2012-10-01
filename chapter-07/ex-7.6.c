/***************************************************************************
EX-7.6: Write a program to compare two files, printing the first line where they differ
***************************************************************************/
#include<stdio.h>
#include<string.h>

#define MAXLINE 1000

main(int argc, char *argv[])
{
	char *name_a, *name_b;
	FILE *fa, *fb;
	char *prog = argv[0];
	char line_a[MAXLINE], line_b[MAXLINE];
	char *pa, *pb;
	int x;

	name_a = NULL;
	fa = NULL;
	name_b = "<stdin>";
	fb = stdin;
	for(x = 1; x < argc; x++){
	    name_a = name_b;
	    fa = fb;
	    name_b =argv[x];
	    fb = fopen(name_b, "r");
	    if(fb == NULL){
		fprintf(stderr, "%s: can't open %s\n", prog, name_b);
		return 1;
	    }
	}
	if(fa == NULL){
	fprintf(stderr, "%s: need an input file\n", prog);
	return 1;
	}
	for(;;){
	     pa = fgets(line_a, MAXLINE, fa);
	     pb = fgets(line_b, MAXLINE, fb);
	     if(pa == NULL && pb == NULL){
		break;
	     } else if(pa == NULL){
		fprintf(stderr, "%s: EOF on %s\n", prog, name_a);
		break;
	     } else if(pb == NULL) {
		fprintf(stderr, "%s: EOF on %s\n", prog, name_b);
		break;
	     } else if (strcmp(line_a, line_b) != 0) {
		printf("%s", line_a);
		printf("%s", line_b);
		break;
	     }
         }
	return 0;
}
