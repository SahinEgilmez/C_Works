#include <stdio.h>

int
main(){
	int number;	/*input number*/
	int digit1, digit2, digit3; /*digits of the number*/
	
	/*get the number*/
	printf("Enter a 3 digit number: ");
	scanf("%d",&number);

	/*calculate the digits*/
	digit3 = number%10;
	digit2 = (number/10)%10;
	digit1 = number/100;

	/*output the digits*/
	printf("1st digit is: %d\n", digit1);
	printf("2nd digit is: %d\n", digit2);
	printf("3rd digit is: %d\n", digit3);
}