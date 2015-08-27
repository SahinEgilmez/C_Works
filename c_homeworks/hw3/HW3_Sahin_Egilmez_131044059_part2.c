/*##########################################################################  */
/*                                                                            */
/* HW3_Sahin_Egilmez_131044059_part2.c                                        */
/* 									      */
/* Created on 07/03/2015 by Sahin Egilmez                                     */
/*                                                                            */
/*Description                                                                 */
/*                                                                            */
/*C program for  “Evaluating the vertical distance of the bouncing ball”.     */
/*Inputs:                                                                     */
/*      - Between 0.4 and 0.8 random ratio                                    */
/*	- Between 10 and 40 random first height.                              */
/*Outputs:                                                                    */
/*	- Screen-file feedback for calculation                                */
/*########################################################################### */
/*----------------------------------------------------------------------------*/
/*                           Includes                                         */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<time.h>
/*----------------------------------------------------------------------------*/
/*                            Defines                                         */
/*----------------------------------------------------------------------------*/
#define LIMIT 1
/*########################################################################### ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­*/
/*                         Function Prototypes                                */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­########################################################################### */
double calculate_the_new_height(double rebound, double ratio);
double calculate_the_vertical_distance(double rebound, double vertical);
int count_the_number(int count);
void report(int count, double rebound, double vertical, FILE* outp);
int main()
{	
	double first_height, ratio, rebound, vertical;/*define doubles*/
	int count;/*defines the integer count number*/

	FILE *outp;/*define the output file*/
	outp=fopen("Result_Table.txt", "w");/*create the output file*/	
	srand(time(NULL));/*first value for rand function*/
	ratio=(rand()%4000)/10000.0000+0.4;/*create the ratio between 0.4-0.8 */
	first_height=rand()%40;/*create the first height between 0 and 40*/
	if (first_height<10) {
	first_height=first_height+10;/*create the first height between 10 and 40*/
	}

	printf("ratio %f \n", ratio);/*print to screen ratio*/
	rebound=first_height;/*define the first height for rebound*/
	vertical=first_height;/*define the first height for total vertical*/
	count=1;/*define the first count*/
	/*print to screen/output file values kind name*/
	printf("No – The Rebounching Height -- The Total vertical Distance\n");
	fprintf(outp, "No – The Rebounching Height -- The Total vertical Distance\n");
	/*this loop repeat as long as rebound<1. */
	while(rebound>=LIMIT) {
		/*print to screen/file count,rebound,total vertical values*/
		report(count, rebound, vertical, outp);
		/*calculate the new height from rebound and ratio*/
		rebound=calculate_the_new_height(rebound,ratio);
		/*calculte the vertical from old vertical and rebound.*/
		vertical=calculate_the_vertical_distance(vertical, rebound);
		/*calculate the count number.*/
		count=count_the_number(count);
	}
	/*print to screen/file text for finish to calculate and program. */ 
	printf("The bouncing is stopped and the task completed...\n");
	fprintf(outp, "The bouncing is stopped and the task completed...\n");
	fclose(outp);/*close to output file.*/

	return 0;

}
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­############################################################################*/
/*                         Function Implementations                           */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­############################################################################*/

/*this function calculate the new rebouncing height.                          */
double calculate_the_new_height(double rebound, double ratio)
{
	rebound=rebound*ratio;
	return rebound;
}
/*this function calculate the vertical distance                               */
double calculate_the_vertical_distance(double vertical, double rebound)
{
	vertical=vertical+(2*rebound);
	return vertical;
}
/*this function calculate the count number.                                   */
int count_the_number(int count) 
{
	count=count+1;
	return count;
}
/*this function print to screen/file count, rebound, vertical distance.       */
void report(int count, double rebound, double vertical, FILE* outp) {
	
	printf("%d    %f                   %f\n", count, rebound, vertical);
	fprintf(outp, "%d      %f                 %f\n", count, rebound, vertical); 
}

/*########################################################################### */
/*                    End of  HW3_Sahin_Egilmez_131044059_part2.c             */
/*########################################################################### */



