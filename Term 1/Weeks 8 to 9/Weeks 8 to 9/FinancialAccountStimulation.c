#include <stdio.h>

float CalculateBalance(float InitialMoney, float InterestRate)
{
	float Interest = 0;

	Interest = InitialMoney * (InterestRate / 100);

	return InitialMoney + Interest; /*New balance is found*/
}

float CalculateInterest(float InitialMoney)
{
	float InterestRate = 0;

	if (InitialMoney < 100)
	{
		InterestRate = 10;
	}
	else if (InitialMoney < 200)
	{
		InterestRate = 50;
	}
	else if (InitialMoney < 500)
	{
		InterestRate = 80;
	}
	else if (InitialMoney >= 500)
	{
		InterestRate = 90;
	}
	else if (InitialMoney < 0)
	{
		InterestRate = 20;
	}
	else if (InitialMoney < -100)
	{
		InterestRate = 40;
	}
	else if (InitialMoney < -500)
	{
		InterestRate = 80;
	}

	return InterestRate;
}

int DepositIntoAccount(float *Account, float Amount)
{
	*Account += Amount;

	return *Account;
}

int WithdrawFromAccount(float *Account, float Amount)
{
	*Account -= Amount;

	return *Account;
}


int main()
{
	int currentdeposit = 0;
	int currentinterest = 0;
	int currentbalance = 0;
	int currentsentinel = -1000; /*There is an overdraft limit of £1000*/
	
	int savingsdeposit = 0;
	int savingsinterest = 0;
	int savingsbalance = 0;
	int savingssentinel = 0; /*The savings account cannot go into the overdraft*/
	
	char answer;
	int months = 0;

	int choice = 0;
	int amount = 0;

	printf("What is the initial deposit for the current account?:");
	scanf("%d", &currentdeposit);
	currentinterest = CalculateInterest(currentdeposit);
	printf("The initial interest rate for the current account is %d\%% \n", currentinterest);
	currentbalance = CalculateBalance(currentdeposit, currentinterest);

	printf("What is the initial deposit for the savings account?:");
	scanf("%d", &savingsdeposit);
	savingsinterest = CalculateInterest(savingsdeposit);
	printf("The initial interest rate for the savings account is %d\%% \n", savingsinterest);
	savingsbalance = CalculateBalance(savingsdeposit, savingsinterest);

	do /*Acts as a main menu so the customer can select what they want to do*/
	{
		printf("Choose 1 to view the balances of the current and saving accounts \n");
		printf("Choose 2 to deposit money into the current account \n");
		printf("Choose 3 to deposit money into the savings account \n");
		printf("Choose 4 to withdraw money from the current account \n");
		printf("Choose 5 to withdraw money from the savings account \n");
		printf("Choose 6 to continue the stimulation for the current account \n");
		printf("Choose 7 to continue the stimulation for the savings account \n");
		printf("Choose 8 to end the stimulation \n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: printf("You chose to view the balances of the current and saving accounts \n");
				printf("The current balance of the current account is \x9C%d \n", currentbalance);
				printf("The current balance of the savings account is \x9C%d \n", savingsbalance);

			break;

		case 2: printf("You chose to deposit money into the current account \n");

			printf("What is the amount you would like to deposit into the current account? \n");
			scanf("%d", &amount);

			if (amount > 0)
			{
				DepositIntoAccount(currentbalance, amount);
				printf("\x9C%d has been successfully deposited into the account \n", amount);
				printf("The balance is now \x9C%d", currentbalance);
			}

			if (amount < 0)
			{
				printf("<main> Error: Unable to deposit amount into the account \n");
			}
			break;

		case 3: printf("You chose to deposit money into the savings account \n");

			printf("What is the amount you would like to deposit into the savings account? \n");
			scanf("%d", &amount);

			if (amount > 0)
			{
				DepositIntoAccount(savingsbalance, amount);
				printf("\x9C%d has been successfully deposited into the account \n", amount);
				printf("The balance is now \x9C%d", savingsbalance);
			}

			if (amount < 0)
			{
				printf("<main> Error: Unable to deposit amount into the account \n");
			}
			break;

		case 4: printf("You chose to withdraw money from the current account \n");

			printf("What is the amount you would like to withdraw from the current account? \n");
			scanf("%d", &amount);

			if (amount > 0)
			{
				WithdrawFromAccount(currentbalance, amount);
				printf("\x9C%d has been successfully withdrawn from the account \n", amount);
				printf("The balance is now \x9C%d", currentbalance);
			}

			if (amount < 0)
			{
				printf("<main> Error: Unable to deposit amount into the account \n");
			}

			break;

		case 5: printf("You chose to withdraw money from the savings account \n");

			printf("What is the amount you would like to withdraw from the savings account? \n");
			scanf("%d", &amount);

			if (amount > 0)
			{
				WithdrawFromAccount(savingsbalance, amount);
				printf("\x9C%d has been successfully withdrawn from the account \n", amount);
				printf("The balance is now \x9C%d", savingsbalance);
			}

			if (amount < 0)
			{
				printf("<main> Error: Unable to deposit amount into the account \n");
			}

			break;

		case 6: printf("You chose to continue the stimulation for the current account \n");

			while (currentbalance >= currentsentinel) /*Loop will continue whilst the account is within the overdraft limit*/
			{
				printf("How many months would you like to stimulate?: \n"); /*The user is asked how many months they want to be stimulated*/
				scanf("%d", &months);

				for (int counter = 0; counter < months; counter++)
				{
					printf("The final balance of the account at the end of the month is \x9C%d \n", currentbalance); /*The balance for following months will be calculated*/

					currentinterest = CalculateInterest(currentbalance);
					printf("The new interest rate is %d\%% \n", currentinterest);

					currentbalance = CalculateBalance(currentbalance, currentinterest);

					if (currentbalance <= -1000)
					{
						printf("Warning your account is at the overdraft limit \n");
					}
				}
				printf("Do you wish to continue? (y/n) \n"); /*Loop will end when user specifies*/
				scanf(" %c", &answer);
				if (answer == 'n')
				{
					break;
				}
			}
			break;

		case 7: printf("You chose to continue the stimulation for the savings account \n");

			while (savingsbalance >= savingssentinel) /*Loop will continue whilst the account is within the overdraft limit*/
			{
				printf("How many months would you like to stimulate?: \n"); /*The user is asked how many months they want to be stimulated*/
				scanf("%d", &months);

				for (int counter = 0; counter < months; counter++)
				{
					printf("The final balance of the account at the end of the month is \x9C%d \n", savingsbalance); /*The balance for following months will be calculated*/

					savingsinterest = CalculateInterest(savingsbalance);
					printf("The new interest rate is %d\%% \n", savingsinterest);

					savingsbalance = CalculateBalance(savingsbalance, savingsinterest);
				}
				printf("Do you wish to continue? (y/n) \n"); /*Loop will end when user specifies*/
				scanf(" %c", &answer);
				if (answer == 'n')
				{
					break;
				}
			}
			break;

		case 8: printf("You chose to end the stimulation \n");
			break;

		default: printf("Invalid command \n");
		}
	} while (choice != 8);

	return 0;
}
