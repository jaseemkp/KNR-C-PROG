/***************************************************************************
Ex-8.5: Modify the fsize program to print the other information contained in the inode entry.
***************************************************************************/


#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<time.h>


void fsize(char *, char *);
#define FORMAT "%m %t %s %n\n"
/* print file name */

main(int argc, char **argv)
{
	if(argc == 1) /* default: current directory */
		fsize(".", FORMAT);
	else
		while(--argc > 0)
			fsize(*++argv, FORMAT);
		return 0;
}

int stat(const char *, struct stat *);
void dirwalk(char *,char *, void(*fcn)(char *, char *));

/* fsize: print the size of file "name" */
void fsize(char *name, char *fmt)
{
	struct stat stbuf;
	const char *mode_s = "rwrwxrwx";
	char time_buf[256];
	short mask;
	int n;
	int c;

	if(stat(name, &stbuf) == -1) {
	     fprintf(stderr, "fsize: can't access %s\n", name);
	     return;
	}
	if((stbuf.st_mode & S_IFMT) == S_IFDIR)
	     dirwalk(name, fmt, fsize);
	while(*fmt != '\0') {
	    if(*fmt == '%') {
		fmt++;
		switch(*fmt) {
		   case 'i':
			printf("%ld", stbuf.st_ino);
			break;
		   case'm':
			switch(stbuf.st_mode & S_IFMT) {
			   case S_IFDIR:
				c = 'd';
				break;
			   case S_IFCHR:
				c = 'c';
			   	break;
			   case S_IFBLK:
				c = 'b';
				break;
			   case S_IFREG:
				c = '-';
				break;
			   default:
				c = '?';
				break;
			   }
			   putchar(c);
			   for( n = 0, mask = 0400;
				mode_s[n] != '\0' && mask > 0;
				n++, mask >>= 1) {
				if(mask & stbuf.st_mode)
				   putchar(mode_s[n]);
				else
				   putchar('-');
				}
			   	break;
			   case 'n':
				printf("%s", name);
				break;
			   case 's':
				printf("%8ld", stbuf.st_size);
				break;
			   case 't':
				strftime(time_buf, sizeof(time_buf) -1, "%Y-%m-%d %H:%M:%S", localtime(&stbuf.st_mtime));
				printf("%s", time_buf);
				break;
			   default:
				putchar(*fmt);
				break;
			}
		   }else {
			putchar(*fmt);
		   }
		   fmt++;
		}
}

#define MAX_PATH 1024

/* dirwalk: apply fcn to all files in dir */
void dirwalk(char *dir, char *fmt, void (*fcn)(char *, char *))
{
	char name[MAX_PATH];
	struct dirent *dp;
	DIR *dfd;

	if((dfd = opendir(dir)) == NULL) {
	    fprintf(stderr, "dirwalk: can't open %s\n", dir);
	    return;
	}
	while((dp = readdir(dfd)) != NULL) {
	   if(strcmp(dp->d_name, ".") == 0
		|| strcmp(dp->d_name, "..")== 0)
		continue; /* skip self and parent */
	if(strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name))
	   fprintf(stderr, "dirwalk: name %s/%s too long\n",
			dir, dp->d_name);
	else{
	    sprintf(name, "%s/%s", dir, dp->d_name);
	    (*fcn)(name, fmt);
	}
    }
   closedir(dfd);
}


