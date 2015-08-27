/*##########################################################################  */
/*                                                                            */
/* HW05_Sahin_Egilmez_131044059_part2.c                                       */
/* 									      */
/* Created on 21/03/2015 by Sahin Egilmez                                     */
/*                                                                            */
/*Description                                                                 */
/*                                                                            */
/*C program for  doing some operation in any array                            */
/*Inputs:                                                                     */
/*      - Any array                                                           */
/*Outputs:                                                                    */
/*	- Print to screen max. value,second max. value in array,sum all array */
/*	- Print to screen count and location in array of enter value.	      */
/*########################################################################### */
/*----------------------------------------------------------------------------*/
/*                           Includes                                         */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
/*----------------------------------------------------------------------------*/
/*                           Defines                                          */
/*----------------------------------------------------------------------------*/
typedef enum {TRUE= 1,FALSE= 0} BOOL;
/*########################################################################### ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­*/
/*                         Function Prototypes                                */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­########################################################################### */
int find_maximum(int a[], int n);/*find max value in array                    */
int second_max_array(int array[], int n);/*find second max value in array     */
int sum_all_array (int array[], int n);/*find sum of all array                */
int count_array(int array[], int n, int value);/*find count of value in array */
BOOL search_array (int array[], int n, int value);/*find location in array    */

int main() 
{
	int sec_max,max,sum;/*defines second max value,second max value, sum. */
	int count,value;/*defines count of values in array and defines value  */
	int i,k,j;/*defines some integers for loops and scanf function*/
	int array[]={6,8,3,3,12,8,3,8,2};/*array what use in this program*/
	int n=9;/*array size*/

	printf("++++++++++++++++++++++++++++++++++++++++\n");
	max=find_maximum(array,n);/*call find maximum function*/
	printf("Maksimum array is %d\n",max);/*print to screen maximum value*/
	printf("++++++++++++++++++++++++++++++++++++++++\n");

	sec_max=second_max_array(array,n);/*call second maximum function*/
	printf("Maksimum second array is %d\n",sec_max);/*print second value*/
	printf("++++++++++++++++++++++++++++++++++++++++\n");

	sum=sum_all_array(array,n);/*call sum of all array function*/
	printf("Sum of all array is %d\n",sum);/*print sum value*/
	printf("++++++++++++++++++++++++++++++++++++++++\n");
	
	/*this loop for enter value at three times*/
	for(j=0; j<3; j++) {
		printf("Plese enter value for count: ");
		scanf("%d",&value);/*scan the keyboard to value*/

		count=count_array(array,n,value);/*call count array function*/
		printf("Count of value %d is %d\n",value,count);/*print count*/
	}	
	printf("++++++++++++++++++++++++++++++++++++++++\n");
	/*this loop for enter valu at three times*/
	for(k=0; k<3; k++) {
	printf("Please enter value for location in array: ");
	scanf("%d",&i);/*scan value for function*/
	search_array(array,n,i);/*call search array*/
	}
	printf("++++++++++++++++++++++++++++++++++++++++\n");
	
	return 0;
}


int find_maximum(int array[], int n)/*find max value in array */
{
	int i,max=0;	
	for(i=0; i<n; i++){
		if(array[i] > max){
		max=array[i];
		}
	}
 	return max;
}

int second_max_array(int array[], int n)/*find second max value in array */
{
	int i,max,x=0,sec_max=0;
	max=find_maximum(array,n);
	for(i=0; i<n; i++){
		sec_max=x;
		if(array[i] > x){
		x=array[i];
			if(x==max){
				x=sec_max;
			}
		}
	}
	
	return sec_max;
}

int sum_all_array (int array[], int n)/*find sum of all array */
{
	int i, sum=0;

	for(i=0; i<n; i++){
		sum += array[i];
	}

	return sum;
}

int count_array(int array[], int n, int value)/*find count of value in array */
{
	int i, count = 0;
	for(i=0; i<n; i++){
		if (array[i] == value)
		{
			count++;
		}
	}
	return count;
}

BOOL search_array(int array[], int n, int value)/*find location in array */
{
	int i;
	for(i=0; i<n; i++){
		if (array[i]==value) {
		printf("%d is at [%d]\n",value,i);
		return TRUE;
		}
	}
	printf("This array haven't this value!\n");
	return FALSE;
}

/*########################################################################### */
/*                    End of  HW05_Sahin_Egilmez_131044059_part2.c            */
/*########################################################################### */



