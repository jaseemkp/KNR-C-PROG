#include <stdio.h>

#define MINLENGTH 81

int getlne(char *line){
	size_t i = 0;
	int c;
	while(i < MINLENGTH){
	c = getchar();
	if(c == EOF) return -1;
	if(c == '\n') return 0;
	line[i++] = c;
	}
	return 1;
}

int copyline(char *line){
	size_t i;
	int c;
	int status = 1;
	for(i = 0; i<MINLENGTH; i++)
		putchar(line[i]);
	while(status == 1){
		c = getchar();
		if(c == EOF)
		status = -1;
 		else if(c == '\n')
		status = 0;
		else
		putchar(c);
	}
	putchar('\n');
	return status;
}

main(){
	char line[MINLENGTH];
	int status =0;
	while(status != -1){
	status = getlne(line);
	if(status == 1)
		status = copyline(line);
	}
	return 0;
}

