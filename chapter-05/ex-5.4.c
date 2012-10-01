/* write the function strend(s,t), which returns 1 if the string t occurs at the end of s, and zero otherwise. */

#include<stdio.h>
int str_end(char *s, char *t)	
{
	char *st = t;
	
	while(*s++ != '\0');
	
	while(*t++ != '\0');
	
	while(*t-- == *s--){
		if( t == st){
			return 1;
		}
}
return 0;
}




main()
{
	char s1[20] ="jaseem jas", s2[20] = "jas";
		if(str_end(s1, s2))
		
			printf("01\n");
		else
			printf("00\n");
}
