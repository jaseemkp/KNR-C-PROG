/*Upper case to Lower case */

int lower(int c)
{
return c >= 'A' && c <= 'Z'? c + 'a' - 'A' : c;
}
#include <stdio.h>
 main(void)
{
	char *Test = "AaBbCcD34wttySWRTG";
	char *p = Test;
	int result = 0;

	while('\0' != *p)
	{
	result = lower(*p);
	printf("[%c] gives [%c]\n", *p, result);
	++p;	
}
result = lower(0);
printf("'\\0' gives %d\n", result);
return 0;
}
