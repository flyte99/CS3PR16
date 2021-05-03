#include <stdio.h>

int main(void)
{
	char paint[10][31];

	int patch[10][3];
	patch[0][0];	patch[1][0];	patch[2][0];	patch[3][0];	patch[4][0];	patch[5][0];	patch[6][0];	patch[7][0];	patch[8][0];	patch[9][0];
	patch[0][1];	patch[1][1];	patch[2][1];	patch[3][1];	patch[4][1];	patch[5][1];	patch[6][1];	patch[7][1];	patch[8][1];	patch[9][1];
	patch[0][2];	patch[1][2];	patch[2][2];	patch[3][2];	patch[4][2];	patch[5][2];	patch[6][2];	patch[7][2];	patch[8][2];	patch[9][2];
	
	int avg[10];
	avg[0];	avg[1];	avg[2];	avg[3];	avg[4];	avg[5];	avg[6];	avg[7];	avg[8];	avg[9];

	/* int sample1 = 0;
	int sample2 = 0;
	int sample3 = 0;
	Initial time for each sample is set to 0 minutes*/

	int inputs = 0;	/*Initial inputs is set to 0*/
		printf("How many paints would you like to input?: \n");	 /*The user is asked how many paints they want to type in*/
		scanf("%d", &inputs);

	for (char counter = 0; counter < 10; ++counter) /*The program will repeat to ask for the details of 4 different paints*/
	{
		printf("Please enter the name of paint: \n");
		scanf("%30s", &paint[counter]);
		printf("Please enter the time taken for the first sample of paint to dry in minutes: \n");
		scanf("%d", &patch[counter][0]);
		printf("Please enter the time taken for the second sample of paint to dry in minutes: \n");
		scanf("%d", &patch[counter][1]);
		printf("Please enter the time taken for the third sample of paint to dry in minutes: \n");
		scanf("%d", &patch[counter][2]);

		if (inputs = counter) /*The loop will stop when the inputs is equal to the counter*/
			break;
	}
	
	for (int counter = 0; counter < 10; ++counter)
	{
		int average = (patch[counter][0] + patch[counter][1] + patch[counter][2]) / 3; /*The mean average is calculated*/

		int var1 = average / 60; /*The ratio is found*/
		int var2 = average % 60; /*The modulus is found*/

		printf("%s finished in %d hours and %d minutes \n", paint[counter], var1, var2);

		if (average <= 60) /*If the paint dries within the 1 hour (60 minutes) it is instant drying*/
			printf("The paint is instant drying. \n");
		else if (average <= 120) /*If the paint dries within the 2 hours (120 minutes) it is fast drying*/
			printf("The paint is fast drying. \n");
		else if (average <= 360) /*If the paint dries within the 6 hours (360 minutes) it is quick drying*/
			printf("The paint is quick drying. \n");
		else printf("This paint does not qualify \n");

		if (inputs = counter) /*The loop will stop when the inputs is equal to the counter*/
			break;
	}
  
	return 0;

}
