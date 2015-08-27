/*##########################################################################  */
/*                                                                            */
/* HW1_Sahin_Egilmez_131044059.c                                              */
/* 									      */
/* Created on 22/02/2015 by Sahin Egilmez                                     */
/*                                                                            */
/*Description                                                                 */
/*                                                                            */
/*finds x and y using the following linear equations with two unknowns and    */
/*calculates f (x,y).                                                         */
/*Inputs:                                                                     */
/*	- Coefficients of the linear equation.                                */
/*Outputs:                                                                    */
/*	- x,y and f(x,y)                                                      */
/*########################################################################### */
/*----------------------------------------------------------------------------*/
/*                           Includes                                         */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<math.h>

int main() {
	
	double x, y, fxy, k;/*define x, y , f(x,y) and k */  
	double a1, b1, c1, s1;/*coefficients of the  equation*/
	double a2, b2, c2, s2;/*coefficients of the equation*/
	/*create ınput and outputs files*/
	FILE *inp1, *inp2, *outp;
	/*open input and output files*/
	inp1 = fopen("EqCoefficients.txt", "r");
	inp2= fopen("FuncCoefficients.txt", "r");
	outp = fopen("Results2.txt", "w");
	/*read the coefficients from the input files*/ 
	fscanf(inp1, "%lf%lf%lf", &a1, &b1, &c1);
	fscanf(inp1, "%lf%lf%lf", &a2, &b2, &c2);
	fscanf(inp2, "%lf%lf", &s1, &s2);
	/*calculate x, y and f(x,y)*/
	k=a2/a1;
	y=((k*c1)-c2)/((k*b1)-(b2));
	x=(c1-(b1*y))/a1;
	fxy=(s1*x)+(s2*y);
	/*write the output values in the output file*/
	fprintf(outp, "%5.0f %5.0f %5.0f\n", x, y, fxy);
	/*close the files*/
	fclose(inp1);
	fclose(inp2);
	fclose(outp);

	return 0;
}
