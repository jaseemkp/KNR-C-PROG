#include <stdio.h>

	int binsearch(int x, int v[], int n){
	int low, high, mid;

	low = 0;
	high = n -1;
	mid = (low + high) / 2;

	while (low <= high && x != v[mid]){
		if(x < v[mid])
			high = mid - 1;
		else
			low = mid +1;
		mid = (low + high) / 2;
		}
		if(x == v[mid])
			return mid;
		else
			return -1;
}

main()
{
	int test[] = {1,3,4,7,9,11,13};
	int i;
	for (i = (sizeof(test)/sizeof(int))-1; i >= 0; --i)
		printf("looking for %d. index=%d\n",test[i],binsearch(test[i], test, sizeof(test)/sizeof(*test)));

	return 0;
}
