/*#############################################################################################*/
/*HW00_Sahin_Egilmez_131044059.c                                                               */
/*_____________________________                                                                */
/*Written by Sahin Egilmez on February 15, 2015                                                */
/*                                                                                             */
/*Description                                                                                  */
/*____________                                                                                 */
/*Takes the Integral of a given 1st degree polynomial                                          */
/*Inputs:                                                                                      */
/*   -Coefficients of the 1st degree polynomial                                                */
/*   -Zero input value of the resulting polynomial                                             */
/*Outputs:                                                                                     */
/*   -Resulting 2nd degree polynomial                                                          */
/*#############################################################################################*/
/*                                                                                             */
/*---------------------------------------------------------------------------------------------*/
/*                            Includes                                                         */
/*---------------------------------------------------------------------------------------------*/
#include<stdio.h>


int 
main() {
	double ia0, ia1;      /*coefficients of the input poly*/
	double p0;            /*P(0) value of the resulting poly*/
	double ra0, ra1, ra2; /*coefficients of the resulting poly*/
		
	/*Get the 1st degree input polynomial*/
	printf("Enter the coefficients of the polynomial (from higher to lower order)>\n");
	scanf("%lf%lf", &ia1, &ia0);
	/*Get the zero input value of the resulting poly*/
	printf("Enter P(0) value for the resulting polynomial>\n");
	scanf("%lf",&p0);

	/*Calculate the resulting poly*/
	ra2 = ia1*(0.5);
	ra1 = ia0;
	
	/*Output the resulting poly*/
	printf("The resulting polynomial is\n %5.3fx^2+%5.3fx^1+%5.3f.", ra2, ra1, p0);

	return 0;
}

/*#############################################################################################*/
/*                             End of HW00_Sahin_Egilmez_131044059.c                           */
/*#############################################################################################*/

