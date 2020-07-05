#include<stdio.h>


int main(){
	int i;
	double first , second ;
	printf(" \n 1. Addition \n 2. Subtraction \n 3. Multiplication \n 4. Division ");
	
	printf(" \nEnter your choice : ");
	scanf("%d", &i);
	
	printf("\n Enter first number : ");
	scanf("%lf", &first);
	printf("\n Enter second number : ");
	scanf("%lf", &second);
	
	switch(i)
	{
		case 1:
		
			printf("\n The Addition of first number %.2lf and second number %.2lf is = %.2lf" , first , second , first + second);
			break;
			
		case 2:
		
			printf("\n The Subtraction of first number %.2lf and second number %.2lf is = %.2lf" , first , second , first - second);
			break;
			
		case 3:
		
			printf("\n The Multiplication of first number %.2lf and second number %.2lf is = %.2lf" , first , second , first * second);
			break;
			
		case 4:
		
			printf("\n The Division of first number %.2lf and second number %.2lf is = %.2lf" , first , second , first / second);
			break;
			
		default:
		
			printf("\n Invalid entry !");
	}
	

	return 0;
}
			
	
	
