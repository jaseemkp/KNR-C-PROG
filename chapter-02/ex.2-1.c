#include <stdio.h>
#include <limits.h>

main()
{
	printf("size of char %d\n", CHAR_BIT);
	printf("size of char Max %d\n", CHAR_MAX);
	printf("size of char Min %d\n", CHAR_MIN);
	printf("size of int min %d\n", INT_MIN);
	printf("size of int max %d\n", INT_MAX);
	printf("size of long min %ld\n", LONG_MIN);
	printf("size of long max %ld\n", LONG_MAX);
	printf("size of short min %d\n", SHRT_MIN);
	printf("size of short max %d\n", SHRT_MAX);
	printf("size of unsigned char %u\n", UCHAR_MAX);
	printf("size of unsigned long %lu\n", ULONG_MAX);
	printf("size of unsigned int %u\n", UINT_MAX);
	printf("size of unsigned short %u\n", USHRT_MAX);
	return 0;
}
