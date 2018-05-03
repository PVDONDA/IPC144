#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* Define statements */

#define LINEAR 1
#define FORM 0


/* Constant TAX value */

const double TAX = 0.13;


/* Item structure */

struct Item {
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};

/* Function Prototypes Milestone 1 */

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


/* Function Prototypes Milesone 2 */

double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int noOfRecs, int sku, int* index);


/* Function Implementations Milestone 1 */

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
	printf("                                           Grand Total: |%12.2lf\n",gTotal);
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


/* Function Implementations Milestone 2 */

//calculate total inventory price with tax or without tax
double totalAfterTax(struct Item item){
	double totalInvPrice;
	double total;
	total = item.price * item.quantity;
	if(item.isTaxed == 1){
		totalInvPrice = total + total * TAX;
	} else {
		totalInvPrice = total;
	}
	return totalInvPrice;
}

//check item quantity
int isLowQuantity(struct Item item){
	int itemQuantityStatus;
	if(item.quantity < item.minQuantity){
		itemQuantityStatus = 1;
	} else {
		itemQuantityStatus = 0;
	}
	return itemQuantityStatus;
}

//for item entry
struct Item itemEntry(int sku){
	struct Item data;
	data.sku = sku;

	printf("        SKU: %d\n",sku);

	printf("       Name: ");
	scanf("%20[^\n]",data.name);
	flushKeyboard();

	printf("      Price: ");
	data.price = getDouble();

	printf("   Quantity: ");
	data.quantity = getInt();	

	printf("Minimum Qty: ");
	data.minQuantity = getInt();

	printf("   Is Taxed: ");
	data.isTaxed = yes();

	flushKeyboard();

	return data;
}

//To display items in linear or form format
void displayItem(struct Item item, int linear){
	if(linear == LINEAR){

		if(isLowQuantity(item)){
			printf("|%3d|%-20s|%8.2lf|  %3s| %3d | %3d |%12.2lf|***\n", item.sku, item.name, item.price, item.isTaxed ? "Yes" : "No", item.quantity, item.minQuantity, totalAfterTax(item));
		} else {
			printf("|%3d|%-20s|%8.2lf|  %3s| %3d | %3d |%12.2lf|\n", item.sku, item.name, item.price, item.isTaxed ? "Yes" : "No", item.quantity, item.minQuantity, totalAfterTax(item));
		}

	} else {

		printf("        SKU: %d\n",item.sku);
		printf("       Name: %s\n",item.name);
		printf("      Price: %.2lf\n",item.price);
		printf("   Quantity: %d\n",item.quantity);
		printf("Minimum Qty: %d\n",item.minQuantity);
		
		if(item.isTaxed == 1){
			printf("   Is Taxed: Yes\n");
		} else {
			printf("   Is Taxed: No\n");
		}
		
		if(isLowQuantity(item)){
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}

	}
}

//print the items in list
void listItems(const struct Item item[], int noOfItems){
	int counter;
	double grandTotal = 0;
	printTitle();
	for(counter = 0; counter < noOfItems; counter++){
		printf("%-4d",counter+1);
		displayItem(item[counter],LINEAR);
		grandTotal = grandTotal + totalAfterTax(item[counter]);
	}
	printFooter(grandTotal);
}

//to search particular item index
int locateItem(const struct Item item[], int noOfRecs, int sku, int* index){
	int i;
	int status = 0;
	for(i = 0; i < noOfRecs; i++){
		if(item[i].sku == sku){
			*index = i;
			status = 1;
		} else {
			status = 0;
		}
	}
	return status;
}