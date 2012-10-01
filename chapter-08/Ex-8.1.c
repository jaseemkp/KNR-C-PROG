/***************************************************************************
EX-8.1: Rewrite the program cat from Chapter7 using read, write, open and 
close insteaded of their standard library equivalents.Perform experiments to
 determine the relative speed of two versions.
***************************************************************************/
#include<stdio.h>
#include<fcntl.h>

#define STD_IN 0
#define STD_OUT 1

/* cat: concatenate files */
main(int argc, char *argv[])
{
	int fd;
	void filecopy(int, int);
	char *prog = argv[0]; /* program name for errors */

	if(argc == 1) /* no args: copy standard input */
		filecopy(STD_IN, STD_OUT);
	else
	    while(--argc > 0)
		if((fd = open(*++argv, O_RDONLY, 0)) == -1){
		   fprintf(stderr, " %s: can't open %s\n", prog, *argv);
		   return 1;
		} else {
		    filecopy(fd, STD_OUT);
		    close(fd);
		}
	return 0;
}

/* filecopy: copy file inoutfd to outputfd */
void filecopy(int ifd, int ofd)
{
	char c;

	while(read(ifd, &c, sizeof(c)) == 1)
	     write(ofd, &c, 1);
}
