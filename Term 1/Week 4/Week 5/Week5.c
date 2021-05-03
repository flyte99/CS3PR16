#include <stdio.h>

int main(void)
{
	char paint[31];
	int sample1 = 0; /*Sample 1 is the first sample of paint tested*/
	int sample2 = 0; /*Sample 2 is the second sample of paint tested*/
	int sample3 = 0; /*Sample 3 is the third sample of paint tested*/
	/*Initial time for each sample is set to 0 minutes*/

	printf("Please enter the name of paint: \n");
	scanf("%30s", &paint);
	printf("Please enter the time taken for the first sample of paint to dry in minutes: \n");
	scanf("%d", &sample1);
	printf("Please enter the time taken for the second sample of paint to dry in minutes: \n");
	scanf("%d", &sample2);
	printf("Please enter the time taken for the third sample of paint to dry in minutes: \n");
	scanf("%d", &sample3);

	int average = (sample1 + sample2 + sample3) / 3; /*The mean average is calculated*/

	int var1 = average / 60; /*The ratio is found*/
	int var2 = average % 60; /*The modulus is found*/

	printf("%s finished in %d hours and %d minutes \n", paint, var1, var2);

	if (average <= 60) /*If the paint dries within the 1 hour (60 minutes) it is instant drying*/
		printf("The paint is instant drying. \n"); 
	else if (average <= 120) /*If the paint dries within the 2 hours (120 minutes) it is fast drying*/
			printf("The paint is fast drying. \n");
	else if (average <= 360) /*If the paint dries within the 6 hours (360 minutes) it is quick drying*/
				printf("The paint is quick drying. \n");
	else printf("Does not qualify \n");

	return 0;
}
