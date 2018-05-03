#include <stdio.h>

#define SIZE 4
	
int main(void){
	
	int option = 0, i = 0, count = 0, id = 0, flag = 0, j;

	struct employee {
		int emp_id;
		int emp_age;
		double emp_salary;
	};	

	printf("---=== EMPLOYEE DATA ===---\n\n");

	struct employee emp[SIZE] = {{0}};

	do {
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		
		scanf("%d",&option);
		printf("\n");
		
		switch (option) {
		
			case 0:
				printf("Exiting Employee Data Program. Good Bye!!!\n");
				break;
			
			case 1:
				printf("EMP ID  EMP AGE EMP SALARY\n");
				printf("======  ======= ==========\n");
				if(count!=0){
					for(i=0;i<count;i++){
						if(emp[i].emp_id != 0){
							printf("%6d%9d%11.2lf\n",emp[i].emp_id,emp[i].emp_age,emp[i].emp_salary);
						}
					}
					printf("\n");
				} else {
					printf("ERROR!!! No Data Found For Employee\n\n");
				}
				break;

			case 2:
				printf("Adding Employee\n");
				printf("===============\n");
				if(count < SIZE){
					printf("Enter Employee ID: ");
					scanf("%d",&emp[count].emp_id);
					printf("Enter Employee Age: ");
					scanf("%d",&emp[count].emp_age);
					printf("Enter Employee Salary: ");
					scanf("%lf",&emp[count].emp_salary);
					count = count + 1;
					printf("\n");
				}else{
					printf("ERROR!!! Maximum Number of Employees Reached\n\n");
				}
				break;

			case 3:
				printf("Update Employee Salary\n");
				printf("======================\n");
				do{
					printf("Enter Employee ID: ");
					scanf("%d",&id);	
					for(i=0;i<SIZE;i++){
						if(emp[i].emp_id == id){
							printf("The current salary is %.2lf\n",emp[i].emp_salary);
							printf("Enter Employee New Salary: ");
							scanf("%lf",&emp[i].emp_salary);
							printf("\n");
							break;
						}
						if (i == SIZE){
							printf("Enter Employee ID: ");
							scanf("%d",&id);
						}
					}
				}while(i == SIZE);
				break;
				
			case 4:
				printf("Remove Employee\n");
				printf("===============\n");
				flag = 0;
				do{
					printf("Enter Employee ID: ");
					scanf("%d",&id);
					for(j=0;j<SIZE;j++){
						if(emp[j].emp_id == id){
							flag = 1;
							for(i=j;i<count;i++){
								emp[i] = emp[i+1];
							}
							printf("Employee %d will be removed\n\n",id);
							break;
						}
					}
					if(!flag){
						printf("Enter Employee ID: ");
						scanf("%d",&id);
					}
					count--;
				}while(!flag);
				break;
				
			default:
				printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);
	
	return 0; 
}
