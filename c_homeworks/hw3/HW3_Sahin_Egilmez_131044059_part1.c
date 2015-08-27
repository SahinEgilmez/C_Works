/*##########################################################################  */
/*                                                                            */
/* HW3_Sahin_Egilmez_131044059_part1.c                                        */
/* 									      */
/* Created on 07/03/2015 by Sahin Egilmez                                     */
/*                                                                            */
/*Description                                                                 */
/*                                                                            */
/*C program for “Guessing An Integer Number” game.                            */
/*Inputs:                                                                     */
/*      - Player's option for play(P/p) or exit(E/e)                          */
/*	- Random number between 1 to 10                                       */
/*	- Player's guess              					      */
/*Outputs:                                                                    */
/*	- Screen feedback for guess                                           */
/*	- Questions for playing again                                         */
/*########################################################################### */
/*----------------------------------------------------------------------------*/
/*                           Includes                                         */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*----------------------------------------------------------------------------*/
/*                            Defines                                         */
/*----------------------------------------------------------------------------*/
#define SENTINELPLAY  'P'
#define SENTINELPLAY1 'p'
#define SENTINELEXIT  'E'
#define SENTINELEXIT1 'e'
/*########################################################################### ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­*/
/*                         Function Prototypes                                */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­########################################################################### */
int RNG();/*this functions calculates the number.                             */
int CalculateTheDifference(int guess, int number);/*this functions calculates the number                                                                        */
void WarnThePlayer();/*this functions to print a warning in order to guide the 
player.                                                                       */

int Play(char option);/*this functions for player's option.If player choose 'P' 
or 'p',it mean play.If player choose 'E' or 'e', it mean exit                 */

int main()
{	
	int number, guess, difference, option;/*defines integers*/
	char play_exit;/*defines players choose*/
	/*print to screen questions for play or exit?*/
	printf(" “P” or “p” for play and “E” or “e” to exit\n");
	option=Play(play_exit);/*players choice*/
	/*this loop for play game if players choice is 'p',*/
	while(option==1) {
		number=RNG();/*create the random number*/
		/*this loop for continue if players choice is wrong.*/
		while(number!=guess) {
			printf("Please guess between 1 and 10 ");/*wants guess*/
			scanf("%d", &guess);/*take the guess*/
			/*calculate the difference*/
			difference=CalculateTheDifference(guess,number);
			/*print to screen the feedback*/
			WarnThePlayer(difference,number);
		}
		/*print to screen questions for playing again?*/
		printf(" Do you want to play again?(“P” or “p” for play and “E” or 			“e” to exit)\n");
		scanf("%c", &play_exit);/*take the players choice*/
		option=Play(play_exit);/*define the choice*/
	}
	return 0;
}

/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­############################################################################*/
/*                         Function Implementations                           */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­############################################################################*/

/*this functions calculates the number*/
int RNG(void)
{	int number;
	srand(time(NULL));
	number=rand()%10+1;
	return number;
}

/*this functions calculates the difference*/
int CalculateTheDifference(int guess, int number)
{
	int x;
	if(number>=guess) 
	x=number-guess;
	else
	x=guess-number ;
	
	return x;

}

/*this functions to print a warning in order to guide the player.*/
void WarnThePlayer(int x, int number)
{	

	if(number>10 || number<1)
	printf("Wrong guess! Please enter number between 1 and 10.\n");
	else if(x>=5)
	printf("You are too far from the number\n");
	else if(x>=3)
	printf("You are far from the number\n");
	else if(x>=1) 
	printf("You are close to the number\n");
	else
	printf("Congrulations, true guess.\n");
}
/*this functions for player's option.If player choose 'P' or 'p',it mean play.*/ 
/*If player choose 'E' or 'e', it mean exit.                                  */
int Play(char option)
{	scanf("%c", &option);
	
	if(option=='P'||option=='p') { return 1; }
	if(option=='E'||option=='e') { return 0; }
		
}

/*########################################################################### */
/*                    End of  HW3_Sahin_Egilmez_131044059_part1.c             */
/*########################################################################### */



















