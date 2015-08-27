#include <stdio.h>
#include <math.h>

#define CSIZE 50
#define SIZE 10

typedef enum {
	FALSE = 0,
	TRUE = 1
} BOOL;

BOOL
is_prime(int number);

BOOL
is_odd(int number);

BOOL
is_even(int number);


void
print_int_array(const int p_arr[], int size);

void
print_char_array(const char p_arr[], int size);

void
assign_numbers_to_array(int p_array[], int size, BOOL func(int));

int
change_array(char c_arr1[], char c_arr2[], int size, char c);

double
compute_mean_of_array(int p_array[], int size);

double
compute_deviation_of_array(int p_array[], int size);

void
reverse_array(int arr[], int size);

int
main(int argc, char *argv[])
{
	int numbers[SIZE], size_c_array;
	double mean, std_dev;
	char c_array2[CSIZE], c_array[CSIZE] = "*_***-_**_-*_*-**-*-*****-****-**_-**-_-*****-***";

	assign_numbers_to_array(numbers, SIZE, is_odd);
	print_int_array(numbers, SIZE);

	assign_numbers_to_array(numbers, SIZE, is_even);
	print_int_array(numbers, SIZE);

	assign_numbers_to_array(numbers, SIZE, is_prime);
	print_int_array(numbers, SIZE);

	size_c_array = change_array(c_array, c_array2, CSIZE, '*');
	print_char_array(c_array2, size_c_array);

	mean = compute_mean_of_array(numbers, SIZE);
	std_dev = compute_deviation_of_array(numbers, SIZE);
	printf("Mean: %.3lf Std Dev: %.3lf\n", mean, std_dev);

	reverse_array(numbers, SIZE);
	print_int_array(numbers, SIZE);

	return 0;
}

BOOL
is_prime(int number)
{
	int i;
	if(number < 2)
		return FALSE;
	for(i=2; i<number; ++i)
	{
		if(number%i == 0)
			return FALSE;
	}
	return TRUE;
}

BOOL
is_odd(int number)
{
	if(number%2)
		return TRUE;
	return FALSE;
}

BOOL
is_even(int number)
{
	if(number%2)
		return FALSE;
	return TRUE;
}


void
assign_numbers_to_array(int p_array[], int size, BOOL func(int))
{
	int i = 0, count=0;
	while(count < size)
	{
		if(func(i))
		{
			p_array[count] = i;
			++count;
		}
		++i;
	}
}

void
print_int_array(const int p_arr[], int size)
{
	int i;
	printf("Printing Array\n");
	for(i=0; i<size; ++i)
	{
		printf("%4d ", p_arr[i]);
		if(i%10 == 9)
			printf("\n");
	}
	printf("\n");
}

void
print_char_array(const char p_arr[], int size)
{
	int i;
	printf("Printing Array\n");
	for(i=0; i<size; ++i)
	{
		printf("%c", p_arr[i]);
	}
	printf("\n");
}

int
change_array(char c_arr1[], char c_arr2[], int size, char c)
{
	int i,j=0;
	for(i=0; i<size; ++i)
	{
		if(c_arr1[i] != c)
		{
			c_arr2[j] = c_arr1[i];
			++j;
		}
	}

	return j;
}

double
compute_mean_of_array(int p_array[], int size)
{
	double total = 0, mean;
	int i;
	for(i=0; i<size; ++i)
		total += p_array[i];
	mean = total / size;
	return mean;
}

double
compute_deviation_of_array(int p_array[], int size)
{
	double total = 0, mean, std_dev;
	int i;
	mean = compute_mean_of_array(p_array, size);
	for(i=0; i<size; ++i)
	{
		total += pow(p_array[i]-mean, 2);
	}
	std_dev = sqrt(total / (size-1));
	return std_dev;
}

void
reverse_array(int arr[], int size)
{
	int i, temp;
	for(i=0; i<size/2; ++i)
	{
		temp = arr[i];
		arr[i] = arr[size-i-1];
		arr[size-i-1] = temp;
	}
}