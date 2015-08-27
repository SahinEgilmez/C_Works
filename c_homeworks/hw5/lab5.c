#include<stdio.h>

typedef enum
		{FALSE,TRUE}
		BOOL;

BOOL is_prime(int number);
BOOL is_odd(int number);
BOOL is_even(int number);
void print_int_array(const int p_arr[], int size);
void print_char_array(const char p_arr[], int size);
void assign_numbers_to_array(int p_arr[], int size, BOOL func(int));
int main()
{
	int number;
	int x[5];
	int p_arr[5];
	BOOL a,b,c;
	
	a=is_prime(number);
	b=is_prime(number);
	c=is_prime(number);
	if(a==TRUE)
		printf("asal");
	assign_numbers_to_array(p_arr,5,is_odd);
	print_int_array(p_arr,5);

	return 0;

}

BOOL is_prime(int number)
{	int i;
	if(number<2)
		return FALSE;
	for(i=2;i<number;++i){
		if(number%i==0)
			return FALSE;
	}
	return TRUE;	 
}

BOOL is_odd(int number)
{
	
	if(number%2==0)
		return TRUE;
	else return FALSE;
}
BOOL is_even(int number)
{
	
	if(number%2==0)
		return FALSE;
	else return TRUE;
}

void print_int_array(const int p_arr[], int size)
{
	int i;
	for(i=0;i<size;i++) {
		printf("%d ", p_arr[i]);
	}
}
void print_char_array(const char p_arr[], int size)
{
	int i;
	for(i=0;i<size;i++) {
		printf("%c", p_arr[i]);
	}
}
void assign_numbers_to_array(int p_arr[], int size, BOOL func(int))
{	
	int number,i;
	for(i=0,number=0;number<size;i++) {
		if(func(i)==TRUE) {
			p_arr[number]=i;
			number++;
		}
	}
	
}		
		




	



