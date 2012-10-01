/* Expands shorthand notations like a-z in the string into the equivalent
complete list ****/

#include<stdio.h>
#include<string.h>

void expand(char * s1, char * s2);

main(void){
	char *s[] = {"a-z-", "z-a-", "-1-6-",
			"a-ee-a", "a-R-L", "1-9-1",
			"5-5", NULL};
	char result[100];
	int i = 0;
	
	while (s[i]) {
		expand(result, s[i]);
		printf("Unexpanded: %s\n", s[i]);
		printf("Expanded  : %s\n", result);
		++i;
		}
	return 0;
}

void expand(char * s1, char * s2)
{
	static char up_alph[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	static char low_alph[27] = "abcdefghijklmnopqrstuvwxyz";
	static char digits[11] = "0123456789";


	char *start, * end, * p;
	int i = 0;
	int j =0;
	
/* Loop	through characters in s2 */

while (s2[i]) {
	switch(s2[i]){
		case '-':
			if(i == 0 || s2[i+1] == '\0'){
				
			s1[j++] = '-';
			++i;
			break;
		}	
		else{
		 if((start = strchr(up_alph, s2[i-1])) && 
			(end = strchr(up_alph, s2[i+1])))
	 		;
		else if((start = strchr(low_alph, s2[i-1])) && 
			(end = strchr(low_alph, s2[i+1])))
			;
		else if((start = strchr(digits, s2[i-1])) && 
			(end = strchr(digits, s2[i+1])))
		;
		else{
			fprintf(stderr,"Mismatched operands '%c-%c'\n",
				s2[i-1], s2[i+1]);
			s1[j++] = s2[i-1];
			s1[j++] = s2[i++];
			break;
		}

	/* Expand the range */

	p = start;
	while(p != end){
		s1[j++] = *p;
		if( end > start)
			++p;
		else
			--p;
		}
		s1[j++] = *p;
		i += 2;
		}
		break;
	default:
	if(s2[i+1] == '-' && s2[i+2] != '\0'){
		++i;
		}
	else{
	s1[j++] = s2[i++];
	}
	break;
	}
	}
	s1[j] = s2[i];
}


