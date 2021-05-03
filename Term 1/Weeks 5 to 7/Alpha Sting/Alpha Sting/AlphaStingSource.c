#include <stdio.h>

int main(void)
{
	char var1[10];

	printf("This program will read someone's name and say hello back \n");
	printf("What is your name?: \n");
	scanf("%s", &var1);

	printf("Hello %s \n", var1);
	return 0;
}