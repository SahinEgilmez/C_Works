/*##########################################################################  */
/*                                                                            */
/* HW1_Sahin_Egilmez_131044059.c                                              */
/* 									      */
/* Created on 22/02/2015 by Sahin Egilmez                                     */
/*                                                                            */
/*Description                                                                 */
/*                                                                            */
/*reads car information from an input text file                               */
/*named as ‘Cars.txt’ and output total fuel cost.                             */
/*Inputs:                                                                     */
/*	- cars information                                                    */
/*Outputs:                                                                    */
/*	- total fuel costs                                                    */
/*########################################################################### */
/*----------------------------------------------------------------------------*/
/*                           Includes                                         */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<math.h>

int main() {
	int tl1, tl2, tl3;/*values of TL                                      */
	double kr1, kr2, kr3;/* values of kurus                               */
	double lt1, pr1, km1, cost1;/*information of 1st car                  */
	double lt2, pr2, km2, cost2;/*information of 2nd car                  */
	double lt3, pr3, km3, cost3;/*information of 3rd car                  */
	/*create ınput and outputs files*/
	FILE *inp, *outp;
	/*open input and output files*/
	inp = fopen("Cars.txt", "r");
	outp = fopen("TotalFuelCosts.txt", "w");
	/*read the information of the cars*/         
	fscanf(inp, "%lf%lf%lf", &lt1, &pr1, &km1);
	fscanf(inp, "%lf%lf%lf", &lt2, &pr2, &km2);
	fscanf(inp, "%lf%lf%lf", &lt3, &pr3, &km3);
	/*calculate total fuel costs*/
	cost1 = km1*lt1*pr1;
	cost2 = km2*lt2*pr2;
	cost3 = km3*lt3*pr3;
	
	tl1=cost1;
	tl2=cost2;
	tl3=cost3;

	kr1=cost1-tl1, kr1=kr1/0.01;
	kr2=cost2-tl2, kr2=kr2/0.01;
	kr3=cost3-tl3, kr3=kr3/0.01;	
	
	/*write the output values in the output file*/
	fprintf(outp, "%5.2f\n%5.2f\n%5.2f\n", cost1, cost2, cost3);
	/*write the output values in the console*/
	printf("The total fuel cost of the car 1 is %d TL and %2.0f Kurus.\n",
 tl1, kr1);
	printf("The total fuel cost of the car 2 is %d TL and %2.0f Kurus.\n",
 tl2, kr2);
	printf("The total fuel cost of the car 3 is %d TL and %2.0f Kurus.\n",
 tl3, kr3);
	/*close the files*/
	fclose(inp);
	fclose(outp);

	return 0;
}
	
