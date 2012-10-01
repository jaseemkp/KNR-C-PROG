/** EX4.14 Define a macro swap(t,x,y) that interchange to argument of type t **/
#include <stdio.h>

#define swap(t, x, y){ t _temp;   \
			_temp = y; \
			y = x; \
			x = _temp;}

main()
{
int i, j; 
printf("Enter to integers:\n");
scanf("%d%d",&i,&j);
printf("\ninteger unswapped:\n x: %d\n y: %d\n", i, j);
swap(int, i, j);
printf("integer swapped:\n x: %d\ty: %d\n", i, j);
}
