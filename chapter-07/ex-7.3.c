/***************************************************************************
Ex-7.3: Revice minprintf to handle more of the other facilities of printf****************************************************************************/
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdarg.h>

void minprintf(char *format, ...);

main()
{
	printf("printf:    %% %d %f %s\n", 20, 55.34, "jaseem");
	minprintf("minprintf: %% %d %f %s\n", 20, 55.34, "jaseem");
	printf("printf:    %% %10d %3f %7s %p\n", 20, 55.34, "jaseem", NULL);
	minprintf("minprintf: %% %10d %3f %7s %p\n", 20, 55.34, "jaseem", NULL);
	return 0;
}

enum {LEFT,RIGHT}; /* alignment for left and right */
/* minprintf: minimal printf with variable argument list */
void minprintf(char *format, ...)
{
	va_list ap; /* points to each unnamed arg in turn */
	char *p, *sval;
	int ival;
	double dval;
	void *pval;
	int alignment = RIGHT;
	int width;
	int precision = 0;
	int x;

	va_start(ap, format); /* make ap point to 1st unnamed arg */
	for(p = format; *p; p++){
	  if(*p != '%'){
	      putchar(*p);
	      continue;
	}
	p++;
	if(*p == '-'){
	   alignment = LEFT;
	   p++;
	}
	width  = 0; /* for width*/
	while(isdigit(*p)){ 
		width = width * 10 + (*p - '0');
		p++;
	}
	switch(*p){
	case 'd':
	    ival = va_arg(ap, int);
	    if(alignment == RIGHT)
	    	printf("%*d",width, ival);
	    else
		printf("%-*d", width, ival);
	    break;
	case 'f':
	    dval = va_arg(ap, double);
	    if(alignment == RIGHT)
		printf("%*f", width, dval);
	    else
		printf("%-*f", width, dval);
	    break;
	case 's':
	    sval = va_arg(ap, char *);
	    if(alignment == RIGHT){
		for(x = 0; x < width - (int) strlen(sval); x++)
		   putchar(' ');
	    }
	    for(x = 0; sval[x] != '\0'; x++)
		putchar(sval[x]);
	    if(alignment == LEFT){
		for( ; x < width; x++)
		  putchar(' ');
	    }
	    break;
	case 'p':
		pval = va_arg(ap, void *);
		if(alignment == RIGHT)
		   printf("%*p", width, pval);
		else
		   printf("%-*p", width, pval);
		break;
	default:
		putchar:
		   putchar(*p);
		   break;
	    }
	
   }
    va_end(ap); /* clean up when done */
}   

