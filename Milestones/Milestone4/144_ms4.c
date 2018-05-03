#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* Define statements */

#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
#define MAX_ITEM_NO 500
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100
#define DATAFILE "items.txt"


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


/* Function Prototypes Milestone 2 */

double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int noOfRecs, int sku, int* index);


/* Function Prototypes Milestone 3 */

void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item *itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int *NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);


/* Function Prototypes Milestone 4 */

void saveItem(struct Item item, FILE *dataFile);
int loadItem(struct Item *item, FILE *dataFile);
int saveItems(const struct Item item[], char fileName[], int NoOfRecs);
int loadItems(struct Item item[], char fileName[], int *NoOfRecsPtr);


/* Main Function */

int main(void) {
	GroceryInventorySystem();
	return 0;
}


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
	struct Item item[MAX_ITEM_NO];
	int numOfRecord;
	int option, quit;
	welcome();
	if(loadItems(item, DATAFILE, &numOfRecord) != 1){
		printf("Could not read from %s.\n",DATAFILE);
	
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
	int itemQuantityStatus = 0;
	if(item.quantity < item.minQuantity){
		itemQuantityStatus = 1;
	}
	return itemQuantityStatus;
}

//for item entry
struct Item itemEntry(int sku){
	struct Item data;
	data.sku = sku;

	printf("        SKU: %d\n",sku);

	printf("       Name: ");
	scanf(" %[^\n]",data.name);
	flushKeyboard();

	printf("      Price: ");
	data.price = getDoubleLimited(0.01, 1000.00);

	printf("   Quantity: ");
	data.quantity = getIntLimited(1, MAX_QTY);	

	printf("Minimum Qty: ");
	data.minQuantity = getIntLimited(0, 100);

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
		
		if(isLowQuantity(item) || item.minQuantity == 0){
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
int locateItem(const struct Item item[], int noOfRecs, int sku, int *index){
	int i;
	int status = 0;
	for(i = 0; i < noOfRecs; i++){
		if(item[i].sku == sku){
			*index = i;
			status = 1;
		}
	}
	return status;
}


/* Function Implementations milestone 3 */

//search item by sku 
void search(const struct Item item[], int NoOfRecs){
	int skuByUser;
	int status, index;

	printf("Please enter the SKU: ");
	//get sku in limit sku_min and sku_max
	skuByUser = getIntLimited(SKU_MIN, SKU_MAX);
	
	//locate item by sku number
	status = locateItem(item, NoOfRecs, skuByUser, &index);

	if(status == 1){
		//display item in form format
		displayItem(item[index], FORM);
	} else {
		printf("Item not found!\n");
	}
}

//update the item fields
void updateItem(struct Item *itemptr){
	struct Item data;
	int overWriteData;

	printf("Enter new data:\n");
	data = itemEntry(itemptr->sku);
	
	printf("Overwrite old data? (Y)es/(N)o: ");
	//ask user if want to overwrite data or not
	overWriteData = yes();

	if(overWriteData == 1){
		printf("--== Updated! ==--\n");
		*(itemptr) = data;
	} else {
		printf("--== Aborted! ==--\n");
	}
}

//add item if user want if limit is not excceded
void addItem(struct Item item[], int *NoOfRecs, int sku){
	struct Item data;
	
	if( *NoOfRecs != MAX_ITEM_NO ){
		int wantToAddItem;
		data = itemEntry(sku);
		printf("Add Item? (Y)es/(N)o: ");
		wantToAddItem = yes();

		if(wantToAddItem == 1){
			*NoOfRecs += 1;
			item[*NoOfRecs - 1] = data;
			printf("--== Added! ==--\n");
		} else {
			printf("--== Aborted! ==--\n");
		}
	} else {
		printf("Can not add new item; Storage Full!\n");
	}
}

//updates or add item in array of item
//depends on SKU being present in an item array or not
void addOrUpdateItem(struct Item item[], int *NoOfRecs){
	int skuByUser;
	int status;
	int index;

	printf("Please enter the SKU: ");
	skuByUser = getIntLimited(SKU_MIN, SKU_MAX);
	
	status = locateItem(item, *NoOfRecs, skuByUser, &index);
	if(status == 1){
		int isUpdate;
		
		displayItem(item[index], FORM);

		printf("Item already exists, Update? (Y)es/(N)o: ");
		isUpdate = yes();

		if(isUpdate == 1){
			updateItem(&item[index]);
		} else {
			printf("--== Aborted! ==--\n");
		}
	} else {
		addItem(item, NoOfRecs, skuByUser);
	}
}	

//increase and decrease the quantity of the selected item in the array 
//by recieving value from user
void adjustQuantity(struct Item item[], int NoOfRecs, int stock){
	int validSkuByUser;
	int locate;
	int index = -1;
	int qty;
	
	printf("Please enter the SKU: ");
	scanf("%d", &validSkuByUser);
	
	//locate item by its sku number
	locate = locateItem(item, NoOfRecs, validSkuByUser, &index);
	
	if(locate != 1){
		printf("SKU not found in storage!\n");
	} else {
		//display item in form format
		displayItem(item[index], FORM);
		
		printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ",stock == STOCK ? "to stock" : "to checkout", stock == STOCK ? (MAX_QTY - item[index].quantity) : item[index].quantity);
		scanf("%d",&qty);
		if(qty == 0){
			printf("--== Aborted! ==--\n");
		} else {
			if(stock == STOCK){
				while((qty > (MAX_QTY - item[index].quantity)) || (qty < 0)){
					printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", stock == STOCK ? "to stock" : "to checkout", stock == STOCK ? MAX_QTY - item[index].quantity : item[index].quantity);
					scanf("%d",&qty);
				}
				item[index].quantity += qty;
				printf("--== Stocked! ==--\n");
			}
			if(stock == CHECKOUT){
				while((qty > item[index].quantity) || (qty < 0)){
					printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", stock == STOCK ? "to stock" : "to checkout", stock == STOCK ? MAX_QTY - item[index].quantity : item[index].quantity);
					scanf("%d", &qty);
				}
				item[index].quantity = item[index].quantity - qty;
				printf("--== Checked out! ==--\n");
			}
			if(item[index].quantity <= item[index].minQuantity){
				printf("Quantity is low, please reorder ASAP!!!\n");
			}
		}
	}
}


/* Function Implementations Milestone 4 */

//save the item data in file
void saveItem(struct Item item, FILE *dataFile){
	fprintf(dataFile,"%d,%d,%d,%.2lf,%d,%s\n",item.sku, item.quantity, item.minQuantity, item.price, item.isTaxed, item.name);
}

//read the item data from the file 
int loadItem(struct Item *item, FILE *dataFile){
	int status;
	
	status = fscanf(dataFile, "%d%*c%d%*c%d%*c%lf%*c%d%*c%[^\n]", &(*item).sku, &(*item).quantity, &(*item).minQuantity, &(*item).price, &(*item).isTaxed, (*item).name);
	
	if (status == 6){
		status = 1;
	} else {
		status = 0;
	}
	return status;
}

//save the entire array in file
int saveItems(const struct Item item[], char fileName[], int NoOfRecs){
	int status = 0;
	int i;

	FILE *fp = fopen(fileName,"w");
	if(fp != NULL){
		for(i=0; i<NoOfRecs; i++){
			saveItem(item[i], fp);
		}
		status = 1;
	}
	fclose(fp);
	return status;
}

//read all the record saved in a file in to array item
int loadItems(struct Item item[], char fileName[], int *NoOfRecsPtr){
	int status = 0;
	FILE *fp = fopen(fileName, "r");
	if(fp != NULL){
		(*NoOfRecsPtr) = 0;
		while (loadItem(&item[*NoOfRecsPtr],fp) != 0){
			(*NoOfRecsPtr)++;
		}
		fclose(fp);
		status = 1;
	}
	return status;
}
