/*********************************************************************
Delete each character in s1 that matches any charecter in the string s2
**********************************************************************/

#include<stdio.h>
#include<string.h>

void squeeze2 (char s1[], char s2[])
{

	int i, j, k;
	int instr2 = 0;

	for(i = j = 0; s1[i] != '\0'; i++)
	{
		instr2 = 0;
		for(k = 0; s2[k] != '\0' && !instr2; k++)
		{
			if(s2[k] == s1[i])
			{
				instr2 = 1;
			}
		}

		if(!instr2)
		{
			s1[j++] = s1[i];
		}
	}
	s1[i] = '\0';
}
/* test driver */

main(void)
{
	char *leftstr[] =
	{
		"",
		"a",
		"beautifications",
		"characteristically",
		"deterministically",
		"fami;iarisation"
};

char *rightstr[] =
{
	"",
	"a",
	"brown",
	"dog",
	"linux",
	"install",
};
	char buffer[32];
	size_t numlefts = sizeof leftstr / sizeof leftstr[0];
	size_t numrights = sizeof rightstr / sizeof rightstr[0];
	size_t left = 0;
	size_t right = 0;

	for(left = 0; left < numlefts; left++)
	{
	for(right = 0; right < numrights; right++)
		{
		strcpy(buffer, leftstr[left]);
		squeeze2(buffer, rightstr[right]);
		printf("[%s] - [%s] = [%s]\n", leftstr[left], rightstr[right], buffer);
		}
	}
	return 0;
}

