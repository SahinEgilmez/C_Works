/*##########################################################################  */
/*                                                                            */
/* HW1_Sahin_Egilmez_131044059.c                                              */
/* 									      */
/* Created on 22/02/2015 by Sahin Egilmez                                     */
/*                                                                            */
/*Description                                                                 */
/*                                                                            */
/*Calculates fog(x) and gof(x)                                                */
/*Inputs:                                                                     */
/*	-x                                                                    */
/*Outputs:                                                                    */
/*	-f(x) g(x) fog(x and gof(x)                                           */
/*########################################################################### */
/*----------------------------------------------------------------------------*/
/*                           Includes                                         */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<math.h>
/*----------------------------------------------------------------------------*/
/*                           #defines                                         */
/*----------------------------------------------------------------------------*/
#define Y 8 

int main() {
	
	double a, b;/*input values*/
	double fog, gof, f, g;/*output values*/
	/*create input and output files*/
	FILE	*inp, *outp;

	/*open input and output file*/
	inp = fopen("variables.txt", "r"); 
	outp = fopen("results.txt", "w");

	/*input values read and write from the file*/
	fscanf(inp, "%lf%lf", &a, &b);
	fprintf(outp, "a= %5.3f, b= %5.3f.\n", a, b);
	
	/*calculate g(x) and f(x)*/
	g=a+(1/(a+(Y/(2*a))));
	f=sin(pow(((b+Y)/b+sqrt(log((pow(3, b))/(2*b+1)))), 2.5));
	
	/*calculate fog(x) and gof(x)*/
	fog=sin(pow(((g+Y)/g+sqrt(log((pow(3, g))/(2*g+1)))), 2.5));
	gof=f+(1/(f+(Y/(2*f))));

	/*write output values in the output file*/
	fprintf(outp, "f(%5.3f)=%5.3f g(%5.3f)=%5.3f\n",b , f, a, g);
	fprintf(outp, "fog(%5.3f)=%5.3f gof(%5.3f)=%5.3f", a, fog, b, gof);
	/*close the files*/
	fclose(inp);
	fclose(outp);
	
	return 0;
}
	
	
