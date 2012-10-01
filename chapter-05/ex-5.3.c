/*EX-5.3: Write a pointer version of the function strcat, copies the string t to the end of s  */

#include<stdio.h>
#include<string.h>
/* strcat: conncatenate t to end of s; s must be big enough */
void str_cat(char *s, char *t)
{
	while(*++s != '\0') /* find end of s */
		;
	while ((*s++ = *t++) != '\0') /* copy t */
		;
}

main()
{
	char s1[11] = "jas";
	char s2[11] = "eem";

	printf("first string : %s\n", s1);
	printf("second string : %s\n", s2);

	str_cat(s1, s2);
	printf("The combined string is %s\n", s1);
	
	return 0;
}
