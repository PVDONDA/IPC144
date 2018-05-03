#include <stdio.h>

// tools
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);

// app interface
int yes(void);
void GroceryInventorySystem(void);
int menu(void);

//Printing the title
void welcome(void){
	printf("---=== Grocery Inventory System ===---\n\n");
}

//printing the title of fields
void printTitle(void){
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}

//printing the footer
void printFooter(double gTotal){
	printf("--------------------------------------------------------+----------------\n");
	if(gTotal > 0){
	printf("					   Grand Total: |%12.2lf\n",gTotal);
	}
}

//makes sure that the keyboard is clear
void flushKeyboard(void){
	char c;
	while( (c = getchar()) != '\n' && c != EOF){
	}
}

//pauses execution of application and wait for user to hit enter
void pause(void){
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}

//get valid integer from user
int getInt(void){
	int value;
	char charValue;
	do{
		scanf("%d%c",&value,&charValue);
		if(charValue != '\n'){
			flushKeyboard();
			printf("Invalid integer, please try again: ");
		}
	}while(charValue != '\n');
	return value;
}

//get integer between limits
int getIntLimited(int lowerLimit, int upperLimit){
	int value;
	do{
		value = getInt(); //check whether value is integer or not
		if(value < lowerLimit || value > upperLimit){
			printf("Invalid value, %d < value < %d: ",lowerLimit,upperLimit);
		}
	}while(value < lowerLimit || value > upperLimit); 
       return value;	
}

//get valid double from user
double getDouble(void){
	double value;
	char charValue;
	do{
		scanf("%lf%c",&value,&charValue);
		if(charValue != '\n'){
			flushKeyboard();
			printf("Invalid number, please try again: ");
		}
	}while(charValue != '\n');
	return value;
}

//get double between limits
double getDoubleLimited(double lowerLimit, double upperLimit){
	double value, result;
	do{
		value = getDouble(); //check whether value is float or not
		if(value > lowerLimit && value < upperLimit){
			result = value;
		}
		if(value < lowerLimit || value > upperLimit){
			printf("Invalid value, %lf< value < %lf: ",lowerLimit,upperLimit);
		}
	}while(value < lowerLimit || value > upperLimit);
	return result;
}

//ask user to enter single character Y or N
int yes(void){
	int quit = 0;
	char charValue;
	do{
		scanf(" %c",&charValue);
		if(charValue != 'y' && charValue != 'Y' && charValue != 'n' && charValue != 'N'){
			flushKeyboard();
			printf("Only (Y)es or (N)o are acceptable: ");
		}else if(charValue == 'y' || charValue == 'Y'){
			quit = 1;
		}else if(charValue == 'n' || charValue == 'N'){
			quit = 0;
		}
	}while(charValue != 'y' && charValue != 'Y' && charValue != 'n' && charValue != 'N');
	return quit;
}

//printing menu list
int menu(void){
	int option;     
	printf("1- List all items\n");
	printf("2- Search by SKU\n");  
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf("> ");
	option = getIntLimited(0, 7);
	return option;
}

//function which perform main tasks in program
//user select option according to task they want to do
void GroceryInventorySystem(void){
	welcome();
	int option, quit;
	do{
		option = menu();
		switch(option){
			case 1:
				printf("List Items under construction!\n");
				pause();
				break;
			case 2:
				printf("Search Items under construction!\n");
				pause();
				break;
			case 3:
				printf("Checkout Item under construction!\n");
				pause();
				break;
			case 4:
				printf("Stock Item under construction!\n");
				pause();
				break;
			case 5:
				printf("Add/Update Item under construction!\n");
				pause();
				break;
			case 6:
				printf("Delete Item under construction!\n");
				pause();
				break;
			case 7:
				printf("Search by name under construction!\n");
				pause();
				break;
			case 0:
				printf("Exit the program? (Y)es/(N)o: ");
				quit = yes();
				break;

			default:
				printf("Invalid value, 0 < value < 7: ");
				break;
		}
	}while(option != '\n' && quit != 1);
}