/*##########################################################################  */
/*                                                                            */
/* HW07_Sahin_Egilmez_131044059_part2.c                                       */
/* 									      */
/* Created on 12/04/2015 by Sahin Egilmez                                     */
/*                                                                            */
/*Description                                                                 */
/*                                                                            */
/*C program for calculate in how many distinct ways you can climb to the top  */
/*and to print it on the screen.                                              */
/*Inputs:                                                                     */
/*      - number of stairs                                                    */
/*Outputs:                                                                    */
/*	- Print to screen number of different ways                            */
/*########################################################################### */
/*----------------------------------------------------------------------------*/
/*                           Includes                                         */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
/*########################################################################### ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­*/
/*                         Function Prototypes                                */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­########################################################################### */
int combination (int n , int k);/*calculate combination*/
int ways(int n);/*calculate in how many distinct ways you can climb to the top*/
int ways_rec(int n,int k);/*function used in the ways function as recursion   */
int main() 
{	
	int number,stair;/*define the ways number and number of stair*/
	
	printf("Lütfen kaç merdiven çıkmanız gerektiğini giriniz.\n");
	scanf("%d",&stair);/*take the stair number*/
	number=ways(stair);/*call ways function and calculate ways number*/
	printf("%d merdiveni %d farklı şekilde çıkabilirsiniz.\n",stair,number);

	return 0;
}

int combination (int n , int k)/*calculate combination*/
{	int result;/*define the return value*/
	if(((n-k)==1)|| (k==1))/*this control for end of function*/
		result=n;/*initialize result*/
	else	
		if((k==0) || (n==k))/*control of the special situation*/
			result=1;
		else
			result=combination(n-1,k-1)+combination(n-1,k);/*recursion 
			branching and assign result value*/
		
	return result;
}

int ways(int n)/*calculate in how many distinct ways you can climb to the top*/
{
	int result;/*define return value*/

	result=ways_rec(n,0);/*call the ways_rec recursive function*/

	return result;
}

int ways_rec(int n,int k)/*function used in the ways function as recursion   */
{
	int result,comb;/*define return value and combination value*/

	if(n>=k) {/*this control for end of the function*/
		comb=combination(n,k);/*calculate combination*/
		result=comb+ways_rec(n-1,k+1);/*call ways_rec function and assign 
		result*/
	}
	else 
		result=0;/*initialize result*/
	
	return result;
}


