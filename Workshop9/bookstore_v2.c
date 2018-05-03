#include <stdio.h>

#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 20

struct Book {
	int _isbn;
	float _price;
	int _year;
	char _title[MAX_TITLE_SIZE];
	int _qty;
};


/* function prototypes */

void menu();

int readRecord(FILE *fp, struct Book *b2read);

void displayInventory(const char filename[]);

float calculateCapital(const char filename[]);

int searchInventory(FILE *fp, const int isbn2find);

void addBook(const char filename[], struct Book *b2Add);

void checkPrice(const char filename[], const int isbn2find);

int numberOfRecord(FILE *fp);

/* main Function */

int main(){
	int option;
	int isbn2Find;
	struct Book mybook;
	float capitalTotal;
	char filename[] = "144_w9_inventory.txt";

	printf("Welcome to the Book Store\n");
	printf("=========================\n");

	do{
		menu();

		printf("Select: ");
		scanf("%d",&option);
		switch(option){
			
			case 1:
				displayInventory(filename);
				break;
			
			case 2:
				addBook(filename,&mybook);
				break;
			
			case 3:
				printf("Please input the ISBN number of the book:\n\n");
				scanf("%d",&isbn2Find);
				checkPrice(filename, isbn2Find);
				break;
			
			case 4:
				capitalTotal = calculateCapital(filename);
				printf("The total capital is: $%.2f.\n",capitalTotal);
				break;
			
			case 0:
				printf("Goodbye!\n");
				break;
			
			default:
				printf("Invalid input, try again:\n");
				break;
	
		}
	
	}while(option != 0);

	return 0;
}


/* Function definition */

void menu(){

	//Display the menu list
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("4) Calculate total capital of the store.\n");
	printf("0) Exit.\n\n");

}

//To read the record from file
int readRecord(FILE *fp, struct Book *b2read){

	fscanf(fp,"%d%*c",&(*b2read)._isbn);
	fscanf(fp,"%f%*c", &(*b2read)._price);
	fscanf(fp,"%d%*c",&(*b2read)._year);
	fscanf(fp,"%d%*c",&(*b2read)._qty);
	fscanf(fp,"%[^\n]%*c", (*b2read)._title);
	
	return 0;
	
}

//to display the inventory on the screen in particular format
void displayInventory(const char filename[]){
	
	struct Book book;
	int i = 0;
	int number;

	FILE *fp = fopen(filename,"r");
	if(fp!= NULL){
		number = numberOfRecord(fp);
		rewind(fp);
		printf("\n\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");
		for(i=0; i<number; i++){
			readRecord(fp,&book);
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n",book._isbn, book._title, book._year, book._price, book._qty);
		}
		printf("===================================================\n\n");
	}
	fclose(fp);

}

//calculate the capital by adding all the multiplication of the price and quantity
float calculateCapital(const char filename[]){
	
	struct Book book;
	int i = 0;
	float total_capital = 0;
	int number;

	FILE *fp = fopen(filename, "r");
	if (fp != NULL){
		number = numberOfRecord(fp);
		rewind(fp);
		for(i=0;i<number;i++){
			readRecord(fp,&book);
			total_capital = total_capital + (book._price * book._qty);
		}
	}
	fclose(fp);

	return total_capital;

}

//search through the file to check that book is there or not
int searchInventory(FILE *fp,const int isbn2find){
	
	struct Book book;
	int i = 0;
	int status = -1;
	int number;

	if(fp != NULL){
		number = numberOfRecord(fp);
		rewind(fp);
		for(i=0; i<number; i++){
			readRecord(fp, &book);
			if(book._isbn == isbn2find){
				status = i;
				break;
			}
		}
	}
	return status;
	
}

//to add the book in file if book does not exists
void addBook(const char filename[], struct Book *b2Add){
	
	int status;
	
	FILE *fp = fopen(filename,"a+");
	
	printf("ISBN:");
	scanf("%d",&(*b2Add)._isbn);
	printf("Title:");
	scanf(" %[^\n]",(*b2Add)._title);
	printf("Year:");
	scanf("%d",&(*b2Add)._year);
	printf("Price:");
	scanf("%f",&(*b2Add)._price);
	printf("Quantity:");
	scanf("%d",&(*b2Add)._qty);
	
	status = searchInventory(fp,(*b2Add)._isbn);

	if(status != -1){
		printf("The book exists in the repository!\n\n");
	} else if(fprintf(fp,"%d;%.2f;%d;%d;%s\n",(*b2Add)._isbn,(*b2Add)._price,(*b2Add)._year,(*b2Add)._qty,(*b2Add)._title)){
		printf("The book is successfully added to the inventory.\n\n");
	}
	fclose(fp);
	
}

//check the price of the inventory item by id
void checkPrice(const char filename[],const int isbn2find){
	
	struct Book book;
	int i, number;

	FILE *fp = fopen(filename,"r");
	number = numberOfRecord(fp);
	rewind(fp);
	if(fp != NULL){
		for(i=0;i<number;i++){		
			readRecord(fp,&book);
			if(book._isbn == isbn2find){
				printf("Book %d costs $%.2f\n\n",isbn2find,book._price);
				break;
			}
		}
	} else {
		printf("Book does not exist in the bookstore! Please try again.\n\n");
	}
	fclose(fp);
	
}

//to find the number of records in .txt file
int numberOfRecord(FILE *fp){
	
	int numOfRec = 0,id,year,qty;
	float price;
	char name[20];
	
	rewind(fp);
	
	if (fp != NULL){
		while(fscanf(fp,"%d%*c%f%*c%d%*c%d%*c%[^\n]",&id, &price, &year, &qty, name) > 0){
			numOfRec++;
		}
	}
	return numOfRec;
	
}