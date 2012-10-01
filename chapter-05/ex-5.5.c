/* write versions of the library functiond strncpy ,strncat and strncmp, which operate on at most the first n characters of their argument strings.
Eg:strncpy(s,t,n) copies atmost n characters of t to s */

#include<stdio.h>

char str_cpy(char *s, char *t, int n)
{
	int i;
	
	for(i = 0; i < n; i++)
		*(s + i) = *(t + i)? *(t +i) : '\0';
	return *s;
}

char str_cat(char *s, char *t, int n)
{	
	
	while( *s++ != '\0');
	*s--;
	
	for( ; n >=0; n--)
		*s++ = *t++;
		
		*s = '\0';

}

int str_cmp(char *s, char *t, int n)
{
		
	for( ; (*s == *t); s++, t++, n--)
	
	if(n == 0)
		return 0;

	return *s - *t;
}
		
main()
{
	char s1[100] = "my name is jaseem";
	char s2[100] = "kolankadavath";
	char s3[100] = "of";
	char s4[100];
	char s5[100];
	char s6[100] = "my name is my prog";

	str_cpy(s4,s1,20);

	printf(" Result: %s\n",s4);

	str_cpy(s5,s3,6);

	printf("Result: %s\n",s5);

	str_cat(s1,s2,12);
	
	printf("result: %s\n",s1);

	if(str_cmp(s1, s6, 10) == 0)
		printf("Equal\n");
	else
		printf("Not equal");

	if(str_cmp(s1, s6, 15) == 0)
		printf("Equal\n");
	else
		printf("Not Equal\n");
}
