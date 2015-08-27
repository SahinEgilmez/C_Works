/*##########################################################################  */
/*                                                                            */
/* HW06_Sahin_Egilmez_131044059_part2.c                                       */
/* 									      */
/* Created on 05/04/2015 by Sahin Egilmez                                     */
/*                                                                            */
/*Description                                                                 */
/*                                                                            */
/*C program for checking the Major and Minor Vowel Harmony and                */
/*making a noun Plural”.                                                      */
/*Inputs:                                                                     */
/*      - vowels, nouns                                                       */
/*Outputs:                                                                    */
/*	- Print to screen true or false for major and minor harmony rule      */
/*	- Print to file plural nouns of the nouns.                            */
/*########################################################################### */
/*----------------------------------------------------------------------------*/
/*                           Includes                                         */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
/*----------------------------------------------------------------------------*/
/*                           Defines                                          */
/*----------------------------------------------------------------------------*/
#define NUM_NAMES 10
#define LETTER 20
typedef enum{HARD,SOFT,CONSONANT} major_type;
typedef enum{FLAT,ROUND,CONSONANT2} minor_type;
typedef enum{TRUE=1,FALSE=0} bool;
/*########################################################################### ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­*/
/*                         Function Prototypes                                */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­########################################################################### */

bool is_major_vh_word(const char* word, const char* v_hard, const char* v_soft);
/*this function checks whether the word satisfies the major vowel harmony or not and returns TRUE or FALSE.*/
major_type major(const char ch1, const char* v_hard, const char* v_soft);/*this function
takes one character and two lists of hard and soft vowels and checks whether the character is a soft vowel or a hard vowel. It returns HARD, SOFT or CONSONANT.*/
bool is_minor_vh_word( const char* word, const char* v_flat, const char* v_round);
/*this function checks whether the word satisfies the minor vowel harmony or not and returns TRUE or FALSE.*/
minor_type minor(const char ch1, const char* v_flat, const char* v_round);/*this function takes one character and two lists of flat and round vowels and checks whether the character is a soft vowel or a hard vowel. It returns FLAT, ROUND or CONSONANT.*/
major_type find_last_type(const char* word,const char* v_hard, const char* v_soft);/*
this function returns the major type (HARD or SOFT) of the last vowel.*/
char* make_plural(const char* noun , char* plural_noun,const char* v_hard, const char* v_soft );/*this function takes a string “noun” and returns its plural form in “plural_noun” (an output argument). It returns a pointer of the output argument as the return value, as well. This function makes the plural noun in accordance with the major vowel rules.*/

int main() {
	char word[NUM_NAMES][LETTER],v_hard[3],v_soft[2],v_flat[3],v_round[2];/*
	defines the strings arrays*/
	char plural_noun[NUM_NAMES],pl_noun[NUM_NAMES+3];/*defines the nouns 
	arrays*/
	char cell,a;/*defines the char*/
	int i,k=0,row=0;/*defines the integers for loop*/
	bool c, d;/*defines the bool values*/
	FILE *inp;/*defines the vowels file*/
	inp=fopen("Vowels.txt","r");/*open file*/
	/*this loop for scan the vowels until EOF*/
	while( fscanf(inp,"%c",&cell)!=EOF )
	{	/*this control change the array*/
   		if(cell=='\n') {
			row=0;
			a=cell;
              		k++;
                 }
		/*scan the hard letter array*/
                 else if(k==0)
		 {
			v_hard[row]=cell;			
			row++;
			
                  }
		/*scan the soft letter array*/
		 else if(k==1)
		 {
			v_soft[row]=cell;
			row++;
                  }
		/*scan the flat letter array*/
		 else if(k==2)
		 {
			v_flat[row]=cell;
			row++;
                  }
		/*scan the round letter array*/
		 else if(k==3)
		 {
			v_round[row]=cell;
			row++;
                  }
	}
	fclose(inp);/*close file*/
	FILE *inp2;/*define the nouns file*/
	inp2=fopen("Nouns.txt","r");/*open the file*/
	i=0;
	/*this loop scan the words array from the file*/ 
	while(fscanf(inp,"%s",word[i])!=EOF) {
	i++;
	}
	fclose(inp2);/*close the file*/ 
	printf("Reading the vowels..\n");
	printf("Reading the nouns..\n");
	printf("The maintaince harmonies\n");
	printf("		MAJOR		MINOR\n");
	/*this loop doing control  word for major and minor harmony rules*/
	for(i=0;i<9;i++) {
		printf("%s		",word[i]);
		c=is_major_vh_word(word[i],v_hard,v_soft);
		if(c==TRUE) printf("T		");
		else printf("F		");
		d=is_minor_vh_word(word[i],v_flat,v_round);
		if(d==TRUE) printf("T\n");
		else printf("F\n");
		}
	printf("Writing the plurals of the nouns...\n");
	FILE *outp;/*defines the plural nouns file*/
	outp=fopen("Plural.txt","w");/*open the file*/
	/*this loop for doing plural of the nouns*/
	for(i=0;i<9;i++){
	make_plural(word[i],plural_noun, v_hard, v_soft );
	fprintf(outp,"%s\n",plural_noun);
	}
	fclose(outp);/*close the file*/
	
	return 0;
	
}
/*this function checks whether the word satisfies the major vowel harmony or not and returns TRUE or FALSE.*/
bool is_major_vh_word(const char* word, const char* v_hard, const char* v_soft)
{
	int i,j,k,hard=0,soft=0;
	bool major_vh;
	major_type c;
	for(k=0;k<10;k++) {
		c=major(word[k], v_hard,v_soft);
		if(c==HARD){
			hard++;
		}
		if(c==SOFT){
			soft++;
		}
	}
	if((hard!=0 && soft==0)||(hard==0 && soft!=0)) {
		major_vh=TRUE;
	}
	else major_vh=FALSE;
	
	return major_vh;
}
/*this function takes one character and two lists of hard and soft vowels and checks whether the character is a soft vowel or a hard vowel. It returns HARD, SOFT or CONSONANT.*/
major_type major(const char ch1, const char* v_hard, const char* v_soft)
{	
	int j;
	major_type type=CONSONANT;
	for(j=0;j<3;j++) {
			if(ch1==v_hard[j]) {
			type=HARD;
			}
		}
	for(j=0;j<2;j++) {
			if(ch1==v_soft[j]) {
			type=SOFT;
			}
		}
	return type;
}
/*this function checks whether the word satisfies the minor vowel harmony or not and returns TRUE or FALSE.*/
bool is_minor_vh_word( const char* word, const char* v_flat, const char* v_round)
{
	int i,j,k,flat=0,round=0;
	bool minor_vh;
	minor_type c;
	for(k=0;k<10;k++) {
		c=minor(word[k], v_flat,v_round);
		if(c==FLAT){
			flat++;
		}
		if(c==ROUND){
			round++;
		}
	}
	if((flat!=0 && round==0)||(flat==0 && round!=0)) {
		minor_vh=TRUE;
	}
	else minor_vh=FALSE;
	
	return minor_vh;
}
/*this function takes one character and two lists of flat and round vowels and checks whether the character is a soft vowel or a hard vowel. It returns FLAT, ROUND or CONSONANT.*/
minor_type minor(const char ch1, const char* v_flat, const char* v_round)
{
	int j;
	minor_type type=CONSONANT2;
	for(j=0;j<3;j++) {
			if(ch1==v_flat[j]) {
			type=FLAT;
			}
		}
	for(j=0;j<2;j++) {
			if(ch1==v_round[j]) {
			type=ROUND;
			}
		}
	return type;
}
/*
this function returns the major type (HARD or SOFT) of the last vowel.*/
major_type find_last_type(const char* word,const char* v_hard, const char* v_soft) 
{	
	int i,j=0;
	i=strlen(&word[NUM_NAMES]);
	major_type c;
	while(j<1){
		c=major(word[i], v_hard,v_soft);
		if(c==HARD || c==SOFT){
			j++;
		}
		i--;
	}
	return c;
}
/*this function takes a string “noun” and returns its plural form in “plural_noun” (an output argument). It returns a pointer of the output argument as the return value, as well. This function makes the plural noun in accordance with the major vowel rules.*/
char* make_plural(const char* noun , char* plural_noun,const char* v_hard, const char* v_soft )
{	int i;
	
	major_type c;
	
	strcpy(plural_noun,noun);
	
	c=find_last_type(noun, v_hard,v_soft);
	if(c==HARD) {
		plural_noun=strcat(plural_noun, "lar");
	}
	else if(c==SOFT) {
		plural_noun=strcat(plural_noun, "ler");
	}
	return plural_noun;
}
			

/*########################################################################### */
/*                    End of  HW06_Sahin_Egilmez_131044059_part2.c            */
/*########################################################################### */

