/*---------------------------------------------------------------------------------------------*/
/*HW1_Sahin_Egilmez_131044059.c                                                                */
/*Written by Sahin Egilmez on February 15, 2015                                                */
/*Description                                                                                  */
/*____________                                                                                 */
/*Takes the multiplication of the two 2nd degree polynomial                                    */
/*Inputs:                                                                                      */
/*     -Coefficients of the  two 2nd degree polynomials                                        */
/*Outputs:                                                                                     */
/*     -Resulting 4th degree polynomial                                                        */
/*---------------------------------------------------------------------------------------------*/

#include<stdio.h>

int 
main()	{
	double a2, a1, a0;        /*coefficients of the input first poly*/
	double b2, b1, b0;        /*coefficients of the input second poly*/
	double c4, c3, c2, c1, c0;/*coefficients of the resulting poly*/

	/*Get the 1st input polynomial*/
	printf("Enter the coefficients of the first polynomial\n");
	scanf("%lf%lf%lf", &a2, &a1, &a0);
	/*Get the 1st input polynomial*/
	printf("Enter the coefficients of the second polynomial\n");
	scanf("%lf%lf%lf", &b2, &b1, &b0);
	
	/*Calculate the resulting poly*/
	c4 = a2*b2;
	c3 = (a2*b1)+(a1*b2);
	c2 = (a2*b0)+(a1*b1)+(a0*b2);
	c1 = (a1*b0)+(a0*b1);
	c0 = a0*b0;
	
	/*Output the resulting poly*/
	printf("The result of multiplacation\n %5.3fx^4+%5.3fx^3+%5.3fx^2+%5.3fx^1+%5.3f.", c4, c3, c2, c1, c0);
	return 0;
}

