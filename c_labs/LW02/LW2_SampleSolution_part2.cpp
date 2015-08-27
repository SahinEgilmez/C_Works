/*##########################################################*/
/*Sample Solution LW1  Part2                                */
/*________________________                                  */
/*Written by Arzu Kakisim on Feb 27, 2015                   */
/*                                                          */
/*                                                          */
/*Description:                                              */
/*____________                                              */
/*Calculates Fahrenheit and sound velocity in               */
/*air at given three temperatures (Celcius).                */
/*Inputs:                                                   */
/*  Variables temperatures (Celcius) x                      */
/*from text file Variables2.txt                             */
/*Outputs:                                                  */
/*  Sound Velocity                                          */
/*##########################################################*/

#include <stdio.h>
#include <math.h>
#include <conio.h>
#define IN_FILE "Variables2.txt"
#define OUT_FILE "Results2.txt"

/* this is function prototype, must appear before function definition.*/
double CelciusToFahrenheit(double x);
double CalculateVelocity  (double f);
double FeetToMeter        (double m);
void PrintResult          (double k, FILE* outF);

/*main() function*/
int main(void)
{  
   /*START_OF_MAIN*/
     
   /*Define Celcius,Fehrenheit*/
   int x1,x2,x3;
   double F1,F2,F3,Vm1,Vm2,Vm3,Vf1,Vf2,Vf3;
   
   FILE* inF = fopen(IN_FILE, "r");    /*Input file pointer*/
   FILE* outF = fopen(OUT_FILE, "w");  /*Output file pointer*/
   /*END_OF_VARIABLES*/
     
   /*Get the variable r*/
   fscanf(inF, "%d", &x1);
   fscanf(inF, "%d", &x2);
   fscanf(inF, "%d", &x3);
         
   /*Calculate Fahrenheit, feet of Sound Velocity and meter of Sound Velocity*/
   F1=CelciusToFahrenheit((double)x1);
   Vf1=CalculateVelocity (F1);
   Vm1=FeetToMeter      (Vf1);
   F2=CelciusToFahrenheit((double)x2);
   Vf2=CalculateVelocity (F2);
   Vm2=FeetToMeter      (Vf2);
   F3=CelciusToFahrenheit((double)x3);
   Vf3=CalculateVelocity (F3);
   Vm3=FeetToMeter      (Vf3);

  /*Print sound velocity (meter)*/
   PrintResult(Vm1,outF);
   PrintResult(Vm2,outF);
   PrintResult(Vm3,outF);
   
   fclose(inF);
   fclose(outF);
   return 0;
}
 
/* defining functions*/
double CelciusToFahrenheit(double x)
{
  double F;
  F=(1.8*x)+32; 
  return F;
}
double CalculateVelocity(double f)
{
  double Vf;
  Vf=658*sqrt((f+459)/180); 
  return Vf;
}
double FeetToMeter(double m)
{
  double Vm;
  Vm=0.3048*m; 
  return Vm;
}
void PrintResult(double k, FILE* outF)
{
   printf(" %f \n",k);  
   fprintf(outF, " %f \n", k);
}
