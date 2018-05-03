#include<stdio.h>

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

void displayInventory(const struct Book book[], const int size);

int searchInventory(const struct Book book[], const int isbn, const int size);

void addBook(struct Book book[], int *size);

void checkPrice(const struct Book book[], const int size);

/* main program */
int main(void) {

	struct Book book[MAX_BOOKS];
	int option, size = 0;

	printf("Welcome to the Book Store\n");
	printf("=========================\n");

	do{
		menu();

		printf("Select: ");
		scanf("%d",&option);
	
		switch(option){
			case 1:
				displayInventory(book, size);
				break;
			case 2:
				
				addBook(book, &size);
				break;	
			case 3:
				checkPrice(book, size);
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

/* Function defination */

void menu(){
	//Display the menu list
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("0) Exit.\n\n");
}

void displayInventory(const struct Book book[], const int size){
	
	int i = 0;
	if(size == 0){
		printf("The inventory is empty!\n");
		printf("===================================================\n\n");
	} else {
		printf("\n\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");
		for(i=0; i<size; i++){
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n",book[i]._isbn,book[i]._title,book[i]._year,book[i]._price,book[i]._qty);
		}
		printf("===================================================\n\n");
	}
	
}

int searchInventory(const struct Book book[], const int isbn, const int size){
	
	int i = 0, status = -1;
	for(i=0; i<size; i++){
		if(book[i]._isbn == isbn){
			status = i;
			break;
		}
	}
	return status;
	
}

void addBook(struct Book book[], int *size){
	
	int isbn, status;

	printf("ISBN:");
	scanf("%d",&book[*size]._isbn);
	isbn = book[*size]._isbn;
	printf("Quantity:");
	scanf("%d",&book[*size]._qty);
	
	status = searchInventory(book, isbn, (*size));

	if(status != -1){
		book[status]._qty = book[*size]._qty + book[status]._qty;
		printf("The book exists in the repository, quantity is updated.\n\n");
	} else {
		if(*size == MAX_BOOKS){
			printf("the inventory is full");
		} else {
			printf("Title:");
			scanf(" %[^\n]",book[*size]._title);
			printf("Year:");
			scanf("%d",&book[*size]._year);
			printf("Price:");
			scanf("%f",&book[*size]._price);
			printf("The book is successfully added to the inventory.\n\n");
			(*size)++;
		}
	}
	
}

void checkPrice(const struct Book book[], const int size){
	
	int input, status;
	
	printf("Please input the ISBN number of the book:\n\n");
	scanf("%d",&input);
	
	status = searchInventory(book, input, size);
	if (status != -1){
		printf("Book %d costs $%.2f\n\n",book[status]._isbn,book[status]._price);
	} else {
		printf("Book does not exist in the bookstore! Please try again.\n\n");
	}
	
}