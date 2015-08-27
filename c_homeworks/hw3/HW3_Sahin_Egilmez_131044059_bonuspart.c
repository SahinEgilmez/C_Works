/*##########################################################################  */
/*                                                                            */
/* HW3_Sahin_Egilmez_131044059_bonuspart.c                                    */
/* 									      */
/* Created on 08/03/2015 by Sahin Egilmez                                     */
/*                                                                            */
/*Description                                                                 */
/*                                                                            */
/*C program for  draw a horizontally diagram of a bouncing ball.              */
/*Inputs:                                                                     */
/*      - First height, height per feet, the peak point and the path point.   */
/*Outputs:                                                                    */
/*	- Print to screen what horizontally diagram of a bouncing ball.       */
/*########################################################################### */
/*----------------------------------------------------------------------------*/
/*                           Includes                                         */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
/*########################################################################### ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­*/
/*                         Function Prototypes                                */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­########################################################################### */

int draw_hor_diag_of_bb (int first_height,int feet_height, char the_peak_point,
char the_path_point);/*this function draw horizontal diagram of a bouncing ball*/

int main() 
{
	int first_height, feet_height;/*defines first height and feet height. */
	char the_path_point, the_peak_point;/*defines the points.*/
	/*take the first height, feet height, peak/path points by user.*/
	printf("Please enter respectively first height, feet height, the peak point and path point.\n");
	scanf("%d %d %c %c", &first_height, &feet_height, &the_peak_point,
	&the_path_point);
	/*draw the diagram with this function.                                */
	draw_hor_diag_of_bb(first_height, feet_height,the_peak_point,the_path_point);
	
	return 0;
}
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­############################################################################*/
/*                         Function Implementations                           */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­############################################################################*/

int draw_hor_diag_of_bb (int first_height,int feet_height, char the_peak_point,
char the_path_point)/*this function draw horizontal diagram of a bouncing ball*/
{	
	
	int count, count2, count3, count4, count5, count6, total, a, b, c, d, e, f,
	n, s, j, difference, space, x, total_char;/*defines the integers*/

	difference=first_height-2;/*calculate the difference value*/
	space=(2*difference)+1;/*calculate the space value by using difference*/
	a=1;/*first value of the a*/
	b=first_height;/*first value of the b*/
	c=1;/*first value of the c*/
	d=(-3);/*first value of the d*/
	f=2*first_height+1;/*calculate the first value of f*/
	e=feet_height;
	/*this loop for write the diagram end of the first height*/
	while(first_height>0) {
		/*this control for first space and peak point*/
		if(first_height==b) { 
			printf("|");
			for(count6=1; count6<=first_height; count6++) {
			printf(" ");
			}	
			printf("%c\n", the_peak_point); }
	/*this loop for write the diagram end of the per feet*/	
	for(count=feet_height; count>=1; count--) {
		printf("|");
		/*this loop for first space*/
		for(count3=1; count3<first_height; count3++) {
			printf(" ");
		}
		
		printf("%c", the_path_point);/*first path point*/
		n=1;/*defines first value of n*/
		s=1;/*defines first value of s*/
		/*this loop for other space and path point*/
		for(count5=f; count5>=0; count5--) {
			/*this loop for interior space*/
			for(count2=n; count2<=a; count2++) {
			printf(" ");
			}
			/*this control for path points*/
			if(c>=s && c<=b) { printf("%c", the_path_point); }
			
			if(c>s && c<b) {
			/*this loop for outer space*/
			for(count4=space; count4>=1; count4--) {
			printf(" ");			
			}
			}
			/*this control for path points*/ 
			if(c>s && c<b) { printf("%c", the_path_point); }

			n=n+2;
			s++;
		}
		/*this control for other peak points*/
		if(count==1 && first_height!=1) {
			for(count4=space; count4>=1; count4--) {
				printf(" ");			
				}
			printf("%c", the_peak_point);
		}
		
		printf("\n");/*for going to the next line*/
		
	}
	a=a+2;
	space=space-2;
	c++;
	d=c-2;
	first_height--;
	f--;
	}
	
	printf("L");/*print orjin*/
	x=3*b+((a-2)/2)*((a-2)/2);/*calculate the x*/
	/*this loop for print "-" as long as x*/
	for(j=0; j<x; j++) {
		printf("-");
	}
	printf(">");/*print >*/
	
	total_char=(b*e)*b+(b+e);/*calculate the using total char(return value)*/

	return total_char;
}

/*########################################################################### */
/*                 End of  HW3_Sahin_Egilmez_131044059_bonuspart.c            */
/*########################################################################### */
	
