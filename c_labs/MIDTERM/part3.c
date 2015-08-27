/*Writen by Evren Cifci as a sample solution for Midterm part3 CSE108	*/
/*GTU, Computer Engineering, April,21th, 2015							*/

#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define COL_CAP 50

int is_element(char str_arr[][COL_CAP], int size, char c);
int is_element_rec(char str_arr[][COL_CAP], int size, char c);

int main(){
	char test_arr[][COL_CAP] = {"abc", "sbc", "dsds"};

	if(is_element_rec(test_arr, 3, 'a'))
		printf("a is an element of the array.\n");
	else
		printf("a is not an element\n");

	if(is_element_rec(test_arr, 3, 's'))
		printf("s is an element of the array.\n");
	else
		printf("s is not an element\n");

	if(is_element_rec(test_arr, 3, 't'))
		printf("t is an element of the array.\n");
	else
		printf("t is not an element\n");
}

/*Iterative implementation*/
int is_element(char str_arr[][COL_CAP], int size, char c){
	int i;
	int found = FALSE;

	for(i=0; i<size; ++i){
		if(strchr(str_arr[i], c))
		/*equally: if(strchr(str_arr[i], c) != NULL)*/
			found = TRUE;	/*element is found*/
	}

	return found;
}

/*Alternative recursive implementation*/
int is_element_rec(char str_arr[][COL_CAP], int size, char c){
	int found;
	
	/*Base Case*/
	if(size == 0)
		found = FALSE;
	else if(strchr(str_arr[0], c))
		found = TRUE;	/*element is found*/
	
	else 
		/*Recursive Call*/
		found = is_element_rec(&str_arr[1], size-1, c);
	
	return found;
}
