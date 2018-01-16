#include <stdio.h>
#include <stdlib.h>

//declare function
void triangles();
char getch();

//?arf a[ kopmmena

void main() {

	float amount;
	float balance;
	char Transaction_Type;
	char anykey;
	_Bool done = 0;

	triangles();

	printf("\n\n\n\n\nBANK ACCOUNT PROGRAM!\n--------------------\nEnter the old balance: ");
	scanf_s("%f", &balance);

	printf("\nEnter the transactions now.\nEnter an F for the transaction type when you are finished.\n");
	printf("Your balance is: %.2f \n", balance);
	printf("Transaction Type (D=deposit, W=withdrawal, F=finished):  ");

	while (!done) {
		Transaction_Type = getch();

		switch (Transaction_Type) {
		case 'd':
		case 'D':
			printf("\nDeposit Amount: ");
			scanf_s("%f", &amount);
			if (amount >= 0) {
				balance = balance + amount;
				printf("Your balance is now %.2f\n", balance);
				printf("Transaction Type (D=deposit, W=withdrawal, F=finished):  ");
			}
			else {
				printf("You can only deposit a positive amount. \n");
				printf("Transaction Type (D=deposit, W=withdrawal, F=finished):  ");
			}
			break;
		case 'w':
		case 'W':
			printf("\nWithdrawal Amount: ");
			scanf_s("%f", &amount);
			if (balance >= amount && amount >= 0) {
				balance = balance - amount;
				printf("Your balance is now %.2f\n", balance);
				printf("Transaction Type (D=deposit, W=withdrawal, F=finished):  ");
				break;
			}
			else if (amount < 0) {
				printf("You can only withdraw a positive amount.\n");
				printf("Transaction Type (D=deposit, W=withdrawal, F=finished):  ");
				break;

			}
			else {
				printf("You do not have enough in the account for this request, please make a deposit first :-) ! \n");
				printf("Transaction Type (D=deposit, W=withdrawal, F=finished):  ");
				break;
			}
		case 'f':
			printf("You pressed f\n");
		case 'F':
			printf("Your ending balance is %.2f, bye! \n", balance);
			done = 1;
			break;
		default:
			if (Transaction_Type != 'F' || Transaction_Type != 'D' || Transaction_Type != 'W') {
				printf("\nSelect a valid option please. ");
				printf("Transaction Type (D=deposit, W=withdrawal, F=finished):  ");
				break;
			}
		}


	}


	printf("Thank you for banking with HugiBank, press anykey to exit the program!\n\n\n\n\n");
	triangles();
	anykey = getch();  //only works in windows I think :-/



}

void triangles()
{
	//declare variables
	int i;
	int n;
	int spacing = 20;


	//creating rows
	printf("(A) %*s %*s %*s", spacing, "(B)", spacing, "(C)", spacing, "(D)\n");


	for (i = 0; i < 10; i++) {
		//creating column
		// # 1
		for (n = 0; n <= i; n++) {
			printf("*");
		}
		// spaces
		for (n = 20; n > i; n--) {
			printf(" ");
		}
		// # 2
		for (n = 10; n > i; n--) {
			printf("*");
		}
		// spaces
		for (n = -10; n < i; n++) {
			printf(" ");
		}
		// invert triangles
		for (n = 0; n <= i; n++) {
			printf(" ");
		}
		// # 3
		for (n = 10; n > i; n--) {
			printf("*");
		}
		//spaces
		for (n = 20; n > i; n--) {
			printf(" ");
		}
		// # 4
		for (n = 0; n <= i; n++) {
			printf("*");
		}
		printf("\n");
	}

	return;
}