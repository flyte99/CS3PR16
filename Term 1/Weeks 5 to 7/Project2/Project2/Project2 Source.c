#include <stdio.h>
/*stdio.h refers tot the standard io library*/

int main(void)
{
	int  var1 = 17;
		/* The first integer is 17*/
	int var2 = 4;
		/*The second integer is 4*/
	
	int ratio = var1/var2;
		/*var 1 will be divided by var2*/
	int modulus = var1%var2;

		printf("ratio is %d \n", ratio);
		printf("modulus is %d \n", modulus);
		return 0;
}