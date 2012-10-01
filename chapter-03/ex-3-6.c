#include<stdio.h>
#include<limits.h>

int main(void){
char buffer[20];

	itoa(INT_MIN, buffer, 7);
	printf("Buffer:%s\n", buffer);

	return 0;
}
void itoa(int n, char s[],int width){
	int i,sign;
	
	if((sign = n) < 0)
	n= -n;
	i = 0;
	do{
		s[i++] = n % 10 + '0';
		printf(
