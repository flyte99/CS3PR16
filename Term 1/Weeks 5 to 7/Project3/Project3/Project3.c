#include <stdio.h>

int main(void)
{
	float num1 = 0;
	float num2 = 0;
	
	printf("This program will divide one integer by another integer \n");
	printf("Please input an integer: \n");
	scanf("%f", &num1);
	printf("Please input a second integer: \n");
	scanf("%f", &num2);
	
	float ratio = num1/num2;
	/* int modulus = num1%num2*/

	printf("ratio is %f \n", ratio);
	/*printf("modulus is %d \n", modulus)*/
	return 0;
}