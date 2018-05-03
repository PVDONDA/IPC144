#include <stdio.h>

int main(void){
	
	double cash, owingBal, GST;
	int loonies, quarters, dimes, nickels, pennies;

	printf("Please enter the amount to be paid: $");
	scanf("%lf",&cash);

	GST = cash * .13 + .005;
	printf("GST: %.2lf\n",GST);

	owingBal = cash + GST;
	printf("Balance owing: $%.2lf\n",owingBal);

	loonies = owingBal / 1;
	owingBal = owingBal - loonies;
	printf("Loonies required: %d, balance owing $%.2lf\n",loonies,owingBal);

	quarters = owingBal / .25;
	owingBal = owingBal - (quarters * .25);	
	printf("Quarters required: %d, balance owing $%.2lf\n",quarters,owingBal);

	dimes = owingBal / .10;
	owingBal = owingBal - (dimes * .10);
	printf("Dimes required: %d, balance owing $%.2lf\n",dimes,owingBal);

	nickels = owingBal / .05;
	owingBal = owingBal - (nickels * .05);
	printf("Nickels required: %d, balance owing $%.2lf\n",nickels,owingBal);

	pennies = owingBal / .01;
	owingBal = owingBal - (pennies * .01);
	printf("Pennies required: %d, balance owing $%.2lf\n",pennies,owingBal);

	return 0;

}
