#include <stdio.h>

#define SIZE 3

void decompose(long long phoneNumber, int *areaCode, int *prefix, int *lineNumber);

int isValid(long long number);

struct phNumbers
{
	long long phoneNumber;
	int areaCode;
	int prefix;
	int lineNumber;
};

/* main program */
int main(void) {
	
	int option, i = 0, count = 0;
	long long phoneNumber1;
	struct phNumbers phoneNumber[SIZE] = {{0LL,0,0,0}};
	long long tempNumber;

	printf("---=== Phone Numbers ===---\n\n");

	do {
		// Display the Option List
		printf("1. Display Phone List\n");
		printf("2. Add a Number\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:
			printf("Exiting Phone Number App. Good Bye!!!\n");
			break;

		case 1: 
			printf("Phone Numbers\n");
			printf("==============\n");
			// Display each number in decomposed form
			for(i=0;i<count;i++){
				printf("(%3d)-%3d-%4d\n",phoneNumber[i].areaCode,phoneNumber[i].prefix,phoneNumber[i].lineNumber);
			}
			printf("\n");
			break;

		case 2:
			printf("Add a Number\n");
			printf("============\n");
			//check if phoneNumber array is full or not to store phone numbers
			if(count < SIZE){
				scanf("%lld",&phoneNumber1);//get phone Number
				tempNumber = isValid(phoneNumber);
				
				if(tempNumber == 1){
					printf("\n");
					phoneNumber[count].phoneNumber = phoneNumber1; //assign phone
					decompose(phoneNumber[count].phoneNumber, &phoneNumber[count].areaCode, &phoneNumber[count].prefix, &phoneNumber[count].lineNumber);
					count++;
				} else {
					printf("ERROR!!! Phone Number is not Valid");
				}
			} else {
				printf("ERROR!!! Phone Number List is Full\n");
				printf("\n");
			}
			break;

		default:
			printf("ERROR: Please enter a valid option to continue\n\n");
			break;
		}

	} while (option != 0);
	return 0;
	
}

void decompose(long long phoneNumber, int *areaCode, int *prefix, int *lineNumber){
	
	*lineNumber = phoneNumber % 10000;
	*prefix = ((phoneNumber-*lineNumber)/10000)%1000;
	*areaCode = (phoneNumber-*prefix*10000-*lineNumber)/10000000;
	
}

int isValid(long long number){

	int status;
	int area, prefix;
	area = int(number)/10000000;
	prefix = (int)(number/10000) % 1000;
	
	if(area == 416 || area == 647 || area == 905){
		if(prefix >= 100 && prefix <= 999){
			status = 1;
		} else {
			status = 0;
		}
	} else {
		status = 0;
	}
	
	return status;
	
}