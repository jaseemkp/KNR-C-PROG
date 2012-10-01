/* Copies string t to string s, converting special characters
 into their appropriate escape sequence. */

void escape(char * s, char * t){
	int i, j;
	i = j = 0;

	while(t[i]) {
 /* Translate the special character, if we have one */
		switch(t[i]){
		case '\n':
			s[j++] = '\\';
			s[j] = 'n';
			break;

		case '\t':
			s[j++] = '\\';
			s[j] = 't';
			break;
		case '\a':
			s[j++] = '\\';
			s[j] = 'a';
			break;
		case '\b':
			s[j++] = '\\';
			s[j] = 'b';
			break;
		case '\f':
			s[j++] = '\\';
			s[j] = 'f';
			break;
		case '\r':
			s[j++] = '\\';
			s[j] = 'r';
			break;
		case '\v':
			s[j++] = '\\';
			s[j] = 'v';
			break;
		case '\\':
			s[j++] = '\\';
			s[j] = '\\';
			break;
		case'\"':
			s[j++] = '\\';
			s[j] = '\"';
			break;
		
		default:
			s[j] = t[i];
			break;
		}
		++i;
		++j;
	}
	s[j] = t[i];
}


#include<stdio.h>

int main(void){
	char text1[50] = "\aHello, \n\tWorld! Mistakee\b was \"Extra 'e'\"!\n";
	char text2[51];

	printf("Original string:\n%s\n", text1);
	escape(text2, text1);
	printf("Escaped string:\n%s\n", text2);
	
	
	return 0;
}
