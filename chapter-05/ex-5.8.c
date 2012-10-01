/*Exercise 5-8. There is no error checking in day_of_year or month_day. Remedy this defect.********************************************************/

#include<stdio.h>
static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;
	
	if(month <= 0 || month > 12 || day <= 0 )

	return -1;
	
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if(day > daytab[leap][month])
		return -1;
	for(i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month day: set month, day from day of year */

int month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	if(yearday < 1 || year <= 0)
		return -1;
	
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for(i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}
/* test*/
main()
{
	int year, month,yearday, day;

	year = 2012;
	month = 9;
	day = 8;
	printf("Date: %d-%02d-%02d\n", year, month, day);
	printf("day-of-year: %d\n", day_of_year(year, month, day));

	yearday = 62;
	month_day(year, yearday, &month, &day);
	printf("yearday: %d\n", yearday);
	printf("Date: %d-%02d-%02d\n", year, month, day);
}
	
