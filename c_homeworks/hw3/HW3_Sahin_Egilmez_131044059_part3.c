/*##########################################################################  */
/*                                                                            */
/* HW3_Sahin_Egilmez_131044059_part3.c                                        */
/* 									      */
/* Created on 08/03/2015 by Sahin Egilmez                                     */
/*                                                                            */
/*Description                                                                 */
/*                                                                            */
/*C program for  draw a vertical diagram of a bouncing ball.                  */
/*Inputs:                                                                     */
/*      - First height, height per feet, the peak point and the path point.   */
/*Outputs:                                                                    */
/*	- Print to screen what vertical diagram of a bouncing ball.           */
/*########################################################################### */
/*----------------------------------------------------------------------------*/
/*                           Includes                                         */
/*----------------------------------------------------------------------------*/

#include<stdio.h>
/*########################################################################### ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­*/
/*                         Function Prototypes                                */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­########################################################################### */

int draw_diag_step(int height, int feet_height, char the_peak_point ,char 
the_path_point);/*function draw the diagram of a bouncing ball for each step. */

int draw_ver_diag_of_bb(int first_height, int feet_height, char the_peak_point, 
char the_path_point);/*this function draw all diagram of a bouncing ball.     */

int finish_diag(int total_char);/*this function draw the finish diagram.      */

int main() 
{
	int first_height, feet_height;/*definesfirst height and feet height   */
	char the_path_point, the_peak_point;/*defines the points              */
	/*take the first height, feet height and peak/path points.            */
	printf("Please enter respectively first height, feet height, the peak point and path point.\n");
	scanf("%d %d %c %c", &first_height, &feet_height, &the_peak_point,	   		&the_path_point);
	/*draw the diagram of the bouncing ball with this function.           */
	draw_ver_diag_of_bb(first_height, feet_height, the_peak_point ,the_path_point);
	
	return 0;
}

/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­############################################################################*/
/*                         Function Implementations                           */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­############################################################################*/

int draw_diag_step(int   height, int feet_height, char the_peak_point , char 
the_path_point)/*function draw the diagram of a bouncing ball for each step. */ 
{	
	int count, count1, count2, count3, count4, count5, count6, count7, 
	count8, total, total_char;/*defines integers*/
	total=0;/*first total value*/
	/*this control for going to next feet.*/ 
	if(height>0) {
		printf("|");
		/*this loop for move up.*/
		for(count2=1; count2<=height; count2++) {
			/*this loop for draw diagram per height.*/
			for(count=1; count<=feet_height; count++) {
			printf("%c",the_path_point);
			}
		printf("\n");
			printf("|");
			/*this loop for draw diagram per height.*/
			for(count4=0; count4<=total; count4++) {
				/*this loop for per space.*/
				for(count3=1; count3<=feet_height; count3++) {
				printf(" ");
				}
			}
			total++;
		}
		printf("%c\n", the_peak_point);/*draw the peak point*/
		/*this loop for move down.*/ 
		for(count5=height; count5>=1; count5--) {
			printf("|");
			/*this loop for draw diagram per height.*/
			for(count8=total-2; count8>=0; count8--) {
				/*this loop for per space.*/
				for(count7=1; count7<=feet_height; count7++) {
				printf(" ");
				}
			}
			total--;
				/*this loop for draw path point.*/
				for(count6=1; count6<=feet_height; count6++) {
				printf("%c",the_path_point);
				}
			printf("\n");
		}
	}
	total_char=2*(height*feet_height)+1;/*calculate the return's value.*/
	return total_char;
}

int finish_diag(int lenght)/*this function draw the finish diagram.           */ 
{	
	int  j;/*defines the integers.*/
	char the_peak_point , the_path_point;/*defines the points.*/
	
	printf("L");/*print the orjin*/
	/*this loop for draw "-" as long as the most distance*/
	for(j=0; j<=lenght; j++) {
		printf("-");
	}
	printf(">");

	return 1;
}


int   draw_ver_diag_of_bb(int first_height, int feet_height, char the_peak_point
, char the_path_point)/*this function draw all diagram of a bouncing ball.    */ 
{
	int count, count1, lenght, total_char, total_step;/*defines integers*/
	total_step=0;/*defines the first value of total step*/
	lenght=(first_height*feet_height)+1;/*calculate the lenght*/
	/*this loop for draw the diagram as long as first height.*/
	for(count1=first_height; count1>=0; count1--) { 
		total_char=draw_diag_step(first_height, feet_height, 
		the_peak_point ,the_path_point);
		total_step=total_step+total_char;	
		first_height--;
	}
	finish_diag(lenght);/*use to finish diag functions*/
	total_step=total_step-1;/*calculate the return's value.*/
	
	return total_step;
}

/*########################################################################### */
/*                    End of  HW3_Sahin_Egilmez_131044059_part3.c             */
/*########################################################################### */



