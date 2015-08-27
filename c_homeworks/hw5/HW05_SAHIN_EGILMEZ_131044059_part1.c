/*##########################################################################  */
/*                                                                            */
/* HW05_Sahin_Egilmez_131044059_part1.c                                       */
/* 									      */
/* Created on 21/03/2015 by Sahin Egilmez                                     */
/*                                                                            */
/*Description                                                                 */
/*                                                                            */
/*C program for  car crash simulation                                         */
/*Inputs:                                                                     */
/*      - Two cars and their speeds and weights                               */
/*Outputs:                                                                    */
/*	- Print to screen diagram of cars before crash                        */
/*	- Print to screen diagram of cars after crash                         */
/*########################################################################### */
/*----------------------------------------------------------------------------*/
/*                           Includes                                         */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
/*----------------------------------------------------------------------------*/
/*                           Defines                                          */
/*----------------------------------------------------------------------------*/
#define ROAD_LENGHT 50
typedef enum {PLAY,CRASH,END} object_state;
/*########################################################################### ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­*/
/*                         Function Prototypes                                */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­########################################################################### */
/*this function determine positions of cars                                   */
void make_move(char *object1, double *position1, double *speed1, int weight1,
	       char *object2, double *position2, double *speed2, int weight2, 
	       object_state *game_state);
/*this function calculate the car crash time                                  */
double car_crash_time(double position1, double position2,
		      double speed1, double speed2);
/*this function print to screen all states.                                   */
void print_game_state(char object1, double position1,
		      char object2, double position2, 
		      object_state game_state);

int main()
{	
	object_state game_state=PLAY;/*defines the game state*/	
	char object1,object2;/*defines the characters of cars*/
	double position1=0,position2=ROAD_LENGHT;/*defines positions of cars*/
	double speed1,speed2,weight1,weight2;/*defines speeds, weights of cars*/
	double crash_time;/*defines the crash time*/
	/*enter the characters of cars,speeds and weights on keyboard*/
	scanf("%c %c %lf %lf %lf %lf",&object1,&object2,&speed1,&speed2,&weight1,&weight2);
	/*this loop for working the program before crash*/
	while(game_state==PLAY) {
		/*call the print function*/
		print_game_state(object1,position1,object2,position2,game_state);
		/*call the move function*/
		make_move(&object1,&position1,&speed1,weight1,&object2,&position2,&speed2, weight2,&game_state);
		
	}
	/*crash time calculating and assign position1*/
	crash_time=car_crash_time(position1,position2,speed1,speed2);
	position1=crash_time;
	/*this loop for working the program after crash*/
	while(game_state==CRASH){
		/*call the print function*/
		print_game_state(object1,position1,object2,position2,game_state);
		/*call the move function*/
		make_move(&object1,&position1,&speed1,weight1,&object2,&position2,&speed2, weight2,&game_state);
	}

	return 0;
}
/*this function determine positions of cars                                   */
void make_move(char *object1, double *position1, double *speed1, int weight1,char *object2, double *position2, double *speed2, int weight2, object_state *game_state)
{	
	
	double speed3,crash_time;/*defines the temporary value*/
	/*this statement for calculate the position1 after crash*/
	if(*game_state==CRASH) {
		*position1=(*position1+(*speed1));
	}
	/*this statement for calculate the positions before crash*/
	if(((*speed1-*speed2)<=(*position2-*position1)) && *game_state==PLAY) {
	*position1=(*position1+*speed1);
	*position2=(*position2+*speed2);
	}
	/*this statement for calculate speed and car characters when crash*/
	else if(*game_state==PLAY) {
	*object1='X';
	*object2='X';
	*game_state=CRASH;
	speed3=(((*speed1)*(weight1))+((*speed2)*(weight2)))/(weight1+weight2);
	*speed1=speed3;	
	}
	/*this statement for end of the program*/
	if(*position1<0 || *position1>=ROAD_LENGHT-1) {
		*game_state=END;
	}
	
}
/*this function calculate the car crash time                                  */
double car_crash_time(double position1, double position2, double speed1, double speed2)
{
	double position3,rate,crash_lenght;/*defines the function elements*/
	/*this statement for speed1>speed2 stuation*/
	/*this statement calculate the position after crash*/
	if(speed1>(-speed2)) {
	rate=(speed1/(-speed2));
	crash_lenght=rate*((position2-position1)/(rate+1));
	position3=position1+crash_lenght;
	}
	/*this statement for speed2>speed1 stuation*/
	/*this statement calculate the position after crash*/
	else {
	rate=((-speed2)/speed1);
	crash_lenght=rate*((position2-position1)/(rate+1));
	position3=position2-crash_lenght+1;
	}
	
	return position3;
	
}

/*this function print to screen all states.                                   */
void print_game_state(char object1, double position1, char object2, double position2, object_state game_state)
{	
	int a[ROAD_LENGHT],m,n,f;/*defines the array and function elementd*/
	int number=1;/*defines the number*/
	double i,j,k;/*defines the function elements*/
	/*this statement for control before last stuation*/
	if(position1>=0 && position1<ROAD_LENGHT) {
		/*this loop for print to screen '_' until position1.*/
		for(i=0;i<position1;i++) {
			printf("_");
		}
		printf("%c",object1);/*print to screen car1 characters*/
		 /*this statement for before crash*/
		if(game_state==PLAY) {
			/*this loop for print to screen '_' until position2*/
			for(j=position1;j<(position2-2);j++) {
				printf("_");
			}
	
			printf("%c",object2);/*print to screen car2 characters*/
			/*this loop for print to scree '_2 until ROAD_LENGHT*/
			for(k=position2;k<ROAD_LENGHT;k++) {
				printf("_");
			}
		}
		else {
			/*this loop for print to scree '_2 until ROAD_LENGHT*/
			for(f=position1+0.99;f<ROAD_LENGHT-1;++f) {
				printf("_");
			}
		}
	}
	/*this statement for last diagram*/
	else if(position1>=ROAD_LENGHT) {
		for(k=1; k<ROAD_LENGHT;++k) {
			printf("_");
		}
		printf("%c",object1);
		}
	else {
		printf("%c",object1);
		for(k=1; k<ROAD_LENGHT;k++) {
			printf("_");
		}
	}
	
	
	printf("\n");
	/*after this part print position using array*/
	a[ROAD_LENGHT];
	for(m=0;m<ROAD_LENGHT;++m) {
		a[m]=number;
		number++;
		if(number==10) {
			number=0;
		}
	}
	for(n=0;n<ROAD_LENGHT;++n) {
		printf("%d",a[n]);
	}
	
	printf("\n");
	
}
/*########################################################################### */
/*                    End of  HW05_Sahin_Egilmez_131044059_part1.c            */
/*########################################################################### */

















