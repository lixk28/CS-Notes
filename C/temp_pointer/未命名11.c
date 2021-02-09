#include<stdio.h>
void copy1(char *, const char *);
void copy2(char *, const char *);

int main()
{     
	char string1[10], *string2="Hello";
	char string3[10], string4[]="Good Bye";

	copy1(string1, string2);
	printf("string1=%s\n",string1);

	copy2(string3, string4);
	printf("string3=%s\n",string3);
	return 0;
}

void copy1(char *s1, const char *s2)
{
	int i;

	for (i=0; s1[i]=s2[i]; i++)
		;
}

void copy2(char *s1, const char *s2)
{
	for (; *s1=*s2; s1++, s2++)
		;
}

