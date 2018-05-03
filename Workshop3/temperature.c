#include <stdio.h>
#define NUMS 4

int main(void){

	int highTemp[NUMS], lowTemp[NUMS], i=0, hTemp, lTemp, dayHigh, dayLow;
	double avgTemp=0, totalHigh=0, totalLow=0;

	printf("---=== IPC Temperature Analyzer ===---\n");
	
	do{
		for(i=0;i<4;i++){
			printf("Enter the high value for day %d: ",i+1);
			scanf("%d",&highTemp[i]);
			printf("\nEnter the low value for day %d: ",i+1);
			scanf("%d",&lowTemp[i]);
			while(highTemp[i]<lowTemp[i] || highTemp[i]>=41 || lowTemp[i]<=-41){
				printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
				printf("\nEnter the high value for day %d: ",i+1);
				scanf("%d",&highTemp[i]);
				printf("\nEnter the low value for day %d: ",i+1);
				scanf("%d",&lowTemp[i]);
			}
			printf("\n");
			totalHigh = totalHigh + highTemp[i];
			totalLow = totalLow + lowTemp[i];
		}
	} while(highTemp[i]>lowTemp[i] && highTemp[i]<41 && lowTemp[i]>-41);
	
	avgTemp = (totalHigh+totalLow)/(2*NUMS);
	hTemp = highTemp[0];
	dayHigh = 1;
	lTemp = lowTemp[0];
	dayLow = 1;
	
	for(i=1;i<4;i++){
		if(highTemp[i] > hTemp){
			hTemp = highTemp[i];
			dayHigh = i+1;
		}
		if(lowTemp[i] < lTemp){
			lTemp = lowTemp[i];
			dayLow = i+1;
		}
	}
	
	printf("The average (mean) temperature was: %.2lf\n",avgTemp);
	printf("The highest temperature was %d, on day %d\n",hTemp,dayHigh);
	printf("The lowest temperature was %d, on day %d\n",lTemp,dayLow);
	
	return 0;

}