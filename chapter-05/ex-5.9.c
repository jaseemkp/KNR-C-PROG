/*Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers instead of indexing.*/

#include<stdio.h>

static char daytab[2][13] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 31, 30, 31, 30},
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 31, 30, 31, 30}
};

/* day_of year: set day of year from month & day */

int day_of_year(int year, int month, int day)
{
	int i, leap;
	char *p;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	p = &daytab[leap][1];
	
	for( i = 1; i < month; i++){
		day += *p;
		++p;
	}
return day;
}
/* month_day  */
void month_day(int year, int yearday, int *pmonth, int *pday)
{	
	int i, leap;
	char *p;

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	p = &daytab[leap][1];
	for(i = 1; yearday > *p; i++){
		yearday -= *p;
		++p;
	}
	*pmonth = i;
	*pday = yearday;
}

 main()
{
 int year, month, day, yearday;
 
 year = 2012;
 month = 9;
 day = 6;
 printf("The date is: %d-%02d-%02d\n", year, month, day);
 printf("day_of_year: %d\n", day_of_year(year, month, day));
 
 
 
 yearday = 248; 
 printf("Yearday is: %d\n", yearday);
 month_day(year, yearday, &month, &day);
 printf("month_day: %d-%2d-2%d\n",year, month, day);
 
 return 0;
}
