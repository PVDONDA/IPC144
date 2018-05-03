#include <stdio.h>
#define NUMS 10  

int main(void){

	int Days, dayForAvg, i=0, highTemp[NUMS], lowTemp[NUMS];
	float totalHigh=0, totalLow=0, avgTemp=0;

	printf("---=== IPC Temperature Analyzer V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d",&Days);

	while(Days < 3 || Days > 10){
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d",&Days);
	}

	printf("\n");

	for(i=0;i<Days;i++){
		printf("Day %d - High: ",i+1);
		scanf("%d",&highTemp[i]);
		printf("Day %d - Low: ",i+1);
		scanf("%d",&lowTemp[i]);
	}

	printf("\nDay  Hi  Low\n");

	for(i=0;i<Days;i++){
		printf("%d    %d    %d\n",i+1,highTemp[i],lowTemp[i]);
	}

	printf("\nEnter a number between %d and %d to see the average temperature for the entered number of days, enter a negative number to exit: ",(i+1)-Days, Days);
	scanf("%d",&dayForAvg);

	while(dayForAvg > Days || dayForAvg < 0){
		if(dayForAvg > Days){
			printf("\nInvalid entry, please enter a number between %d and %d, inclusive: ",(i+1)-Days, Days);
			scanf("%d",&dayForAvg);
		}else{
			printf("\nGoodbye!\n");
			break;
		}
		while(dayForAvg > 0 && dayForAvg <= Days){
			for(i=0;i<dayForAvg;i++){
				totalHigh = totalHigh + highTemp[i];
				totalLow = totalLow + lowTemp[i];			
			}
			avgTemp = (totalHigh + totalLow ) / (2*dayForAvg);
			i=0;
			totalHigh = 0;
			totalLow = 0;
			printf("\nThe average temperature up to day %d is: %.2f\n",dayForAvg,avgTemp);
			printf("\nEnter a number between %d and %d to see the average temperature for the entered number of days, enter a negative number to exit: ",i+1,Days);
			scanf("%d",&dayForAvg);
		}
	}

	return 0;

}