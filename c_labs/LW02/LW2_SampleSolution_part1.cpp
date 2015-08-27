/*##########################################################*/
/*Sample Solution LW1  Part1                                */
/*________________________                                  */
/*Written by Arzu Kakisim on Feb 27, 2015                   */
/*                                                          */
/*                                                          */
/*Description:                                              */
/*____________                                              */
/*Calculates surface area and volume of sphere              */
/*Inputs:                                                   */
/*  Variable r from text file Variables1.txt                */
/*  pi is constant macro                                    */
/*Outputs:                                                  */
/*  Surface area and volume of sphere                       */
/*##########################################################*/
 
#include<stdio.h>

#define IN_FILE "Variables1.txt"
#define OUT_FILE "Results1.txt"
#define PI 3.14
 
int main(){
    
    /*START_OF_MAIN*/
     
    /*Define Surface Area and Volume of Sphere*/
    double A, V;
    int r; 
     
    FILE* inF = fopen(IN_FILE, "r");    /*Input file pointer*/
    FILE* outF = fopen(OUT_FILE, "w");  /*Output file pointer*/
    /*END_OF_VARIABLES*/
     
    /*Get the variable r*/
    fscanf(inF, "%d", &r);
         
    /*Calculate area and volume*/
    A=4*PI*r*r;
    V=((double)4/3)*PI*r*r*r;
     
    /*Output the evaluation value*/
    printf("The area a sphere is %5.2f.\nThe volume of sphere is %5.2f.", A, V);
    fprintf(outF, "%f %f", A, V);
 
    fclose(inF);
    fclose(outF);
 
    return 0;
     
    /*END_OF_MAIN*/
}
