#include <stdio.h>
#include <string.h>

struct message {
	char userid[11];
	char message[142];
	int upvotes;
} CawCaw;

int main()
{
	struct message message[99]; /*Program can store 100 messages*/
	message[0];  message[1];  message[2];  message[3];  message[4];  message[5];  message[6];  message[7];  message[8];  message[9];
	message[10]; message[11]; message[12]; message[13]; message[14]; message[15]; message[16]; message[17]; message[18]; message[19];
	message[20]; message[21]; message[22]; message[23]; message[24]; message[25]; message[26]; message[27]; message[28]; message[29];
	message[30]; message[31]; message[32]; message[33]; message[34]; message[35]; message[36]; message[37]; message[38]; message[39];
	message[40]; message[41]; message[42]; message[43]; message[44]; message[45]; message[46]; message[47]; message[48]; message[49];
	message[50]; message[51]; message[52]; message[53]; message[54]; message[55]; message[56]; message[57]; message[58]; message[59];
	message[60]; message[61]; message[62]; message[63]; message[64]; message[65]; message[66]; message[67]; message[68]; message[69];
	message[70]; message[71]; message[72]; message[73]; message[74]; message[75]; message[76]; message[77]; message[78]; message[79];
	message[80]; message[81]; message[82]; message[83]; message[84]; message[85]; message[86]; message[87]; message[88]; message[89];
	message[90]; message[91]; message[92]; message[93]; message[94]; message[95]; message[96]; message[97]; message[98]; message[99];

	int choice = 0;
	int msgNo = 0;	/*Number of initial messages is set at 0*/
	
	FILE *reader;
	char file[20];

	printf("Please enter your user id \n");
	scanf("%s", &CawCaw.userid);

	do
	{
		printf("Choose 1 to write a message \n");
		printf("Choose 2 to display all your previous messages \n");
		printf("Choose 3 to load messages from a file \n");
		printf("Choose 4 to exit \n");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:	if (msgNo < 100)
					{
						printf("What's your message? \n");
						scanf("%[^/n]", &message[msgNo].message);
					}
				
					if (msgNo >= 100)		
					{
						printf("Error: Maximum messages reached \n");
					}
						
					msgNo = msgNo++; /*Number of messages increased by one*/
					
					break;

			case 2: printf("You have %d previous messages \n", msgNo);
						
					for (int counter = msgNo; 0<= counter <= msgNo; counter--) /*Will loop whilst number of messages is counted down*/
					{
						printf("%s \n", message[msgNo].message);
					}
					break;

			case 3:	printf("Which file would you like to load? \n");
					scanf("%s", &file);
					reader = fopen("C:/Users/Mollie/OneDrive/Desktop/example_caws.psv", "r"); //change 
					
					if (reader != NULL)
					{
						msgNo = 0; /*All previous messages will be overwritten*/
						
						for (int counter = 0; counter = 27; counter++);
						{
							fscanf(reader, "%s", CawCaw.userid);
							fscanf(reader, "%[^\n]", &message[msgNo].message);
							fscanf(reader, "%d", &message[msgNo].upvotes);

							fprintf(reader, "User id: %s \n", CawCaw.userid);
							fprintf(reader, "%[^|] \n", message[msgNo].message);
							fprintf(reader, "Upvotes: %d \n", message[msgNo].upvotes);

							msgNo = msgNo++;
						}
						
						fclose(reader);
					}
					else
					{
						printf("Unable to load file \n");
					}

					break;

			case 4: printf("You chose to exit \n");
				    break;

			default: printf("Invalid command \n");
		}
	} while (choice != 4);
	
	return 0;
}