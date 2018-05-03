#include <stdio.h>

#define distRate1  0.69	
#define distRate2  0.49

struct Rental
{
	int id;
	double baseDay;
	double earnings;
};

double addPositive(double amount, double newAmount);

double taxCalc(double price, double rate);

double subtractPositive(double amount, double newAmount);

double addPositive(double amount, double newAmount){
	
	double sum;
	if(newAmount > 0){
		sum = newAmount + amount;
	} else {
		sum = amount;
	}
	return sum;

}

double taxCalc(double price, double rate){

	double tax;
	tax = price * (rate / 100);
	return tax;
}

double subtractPositive(double amount, double newAmount){
	
	double subAmount;
	if(newAmount > 0){
		subAmount = amount - newAmount;
	} else {
		subAmount = amount;
	}
	return subAmount;

}

int main(){
	
	const int noVehicles = 3;
	int option;
	int flag = 0;
	int tempID;
	int i = 0;
	
	struct Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 },{ 125, 29.95, 0 } };
	
	double taxRate = 14;
	double discount = 5; 
	
	int day = 0, km = 0;
	char prompt = ' ';
	double basePrice = 0, kmCost = 0, charge = 0, taxes = 0;
	int giftAmount = 0;
	
	printf("***** Rental Vehicle Management App *****\n\n");
	
	do
	{
		printf("1.) Rental Status\n");
		printf("2.) Apply Charges\n");
		printf("3.) Apply Taxes to All Rentals\n");
		printf("4.) Apply Gift Card\n");
		printf("0.) Log out\n\n");
		printf("Please enter an option to continue: ");
		scanf("%d", &option);

	switch (option){
		
		case 0:
			break;

		case 1:
			printf("\n-- Rental Vehicle Status --\n\n");
			printf("ID#      Earnings\n");
			printf("-------- ----------\n");
			for(i=0;i<noVehicles;i++){
				printf("%8d %10.2lf\n", vRent[i].id, vRent[i].earnings);
			}
			printf("\n");
			break;

		case 2:
			flag = -1;
			printf("\n-- Rental Charges --\n\n");
			printf("Enter vehicle ID: ");
			scanf("%d", &tempID);
			for (i = 0; i < noVehicles && flag == -1; i++) {
				if (tempID == vRent[i].id) {
					flag = i;
					break;
				}
			}

			if (flag != -1) {	
				printf("Enter Rental Period (in Days): ");
				scanf("%d",&day);
				printf("Enter kilometers driven: ");
				scanf("%d",&km);
				
				basePrice = day * vRent[i].baseDay;
				if(km > 100){
					kmCost = ((km - 100) * distRate2) + (distRate1 * 100);
				}
				if(km >= 0 && km <= 100){
					kmCost = km * distRate1;
				}

				charge = basePrice + kmCost;

				printf("Apply Discount: ");
				scanf(" %c",&prompt);

				if(prompt == 'Y' || prompt == 'y'){
					vRent[i].earnings = vRent[i].earnings + charge;
					vRent[i].earnings = subtractPositive(vRent[i].earnings,discount);
				} else if(prompt == 'N' || prompt == 'n'){
					vRent[i].earnings = addPositive(vRent[i].earnings,charge);
				}
			
				printf("\nBase   kmCost DiscStatus Total\n");
				printf("====== ====== ========== ======\n");
				printf("%6.2lf %6.2lf %10c %6.2lf\n\n",basePrice, kmCost, prompt, vRent[i].earnings);
				
			} else {
				printf("ERROR: Vehicle ID does not exist.\n\n");
			}
			break;

		case 3: 
			printf("\n-- Apply Taxes To all Accounts--\n\n");
			printf("ID#      Earnings   Taxes\n");
			printf("-------- ---------- ------\n");

			for(i=0;i<noVehicles;i++){
				taxes = taxCalc(vRent[i].earnings,taxRate);
				vRent[i].earnings = addPositive(vRent[i].earnings,taxes);
				printf("%8d %10.2lf %6.2lf\n",vRent[i].id, vRent[i].earnings, taxes);
			}
			printf("\n");
			break;
		
		case 4: 
			flag = -1;
			printf("\n-- Apply Gift Card --\n\n");
			printf("Enter vehicle ID: ");
			scanf("%d", &tempID);

			for (i = 0; i < noVehicles && flag == -1; i++) {
				if (tempID == vRent[i].id) {
					flag = i;
				}
			}
			
			if (flag != -1) {
				printf("Enter Gift Card Amount: ");
				scanf("%d",&giftAmount);
				printf("Discount Applied\n");
				vRent[flag].earnings = subtractPositive(vRent[flag].earnings, giftAmount);
			} else {
				printf("ERROR: Vehicle ID does not exist.\n\n");
			}
			printf("\n");
			break;
		
		default:
			printf("Error: Please enter a valid option to continue\n\n");
			break;
		}
	} while (option != 0);
	return 0;
	
}
