/*##########################################################################  */
/*                                                                            */
/* HW09_Sahin_Egilmez_131044059_part1.c                                       */
/* 									      */
/* Created on 25/04/2015 by Sahin Egilmez                                     */
/*                                                                            */
/*Description                                                                 */
/*                                                                            */
/*C program for updating of university's ınstructor and employees salary.     */
/*Inputs:                                                                     */
/*      - txt file for person info                                            */
/*Outputs:                                                                    */
/*	- Updated person info                                                 */
/*########################################################################### */
/*----------------------------------------------------------------------------*/
/*                           Includes                                         */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#define CHAR_MAX 30
typedef struct {char name[CHAR_MAX],surname[CHAR_MAX], department[CHAR_MAX];
		char class1[CHAR_MAX],class2[CHAR_MAX];
		double salary;}type_I;
typedef struct {char name[CHAR_MAX],surname[CHAR_MAX];
		double salary;
		char degree;}type_E;
typedef union { type_I person1;
		type_E person2; }p_type;
typedef struct { char type;
		p_type person_t;} combine_type;
/*########################################################################### ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­*/
/*                         Function Prototypes                                */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­########################################################################### */
combine_type salary_rise(combine_type person_info); 
void convert(char input_file[],char bin_file[]);

int main() {
	/*tested converting files*/
	convert("input1.txt","output.bin");
	
	return 0;
}

combine_type salary_rise(combine_type person_info) /*this function update to 
person's salary*/
{	/*this control for person type*/
	if(person_info.type=='I') {
		/*update ınstructor salary*/
		person_info.person_t.person1.salary+=person_info.person_t.person1.salary*0.05;
		person_info.person_t.person1.salary+=person_info.person_t.person1.salary*0.053;
	}
	else if(person_info.type=='E') {
		/*update degree a employees salary*/
		if(person_info.person_t.person2.degree=='a')
			person_info.person_t.person2.salary+=person_info.person_t.person2.salary*0.175;
		/*update degree b employees salary*/
		else if(person_info.person_t.person2.degree=='b')
			person_info.person_t.person2.salary+=person_info.person_t.person2.salary*0.12;
		/*update degree c employees salary*/
		else if(person_info.person_t.person2.degree=='c')
			person_info.person_t.person2.salary+=person_info.person_t.person2.salary*0.09;
	}
	return person_info;
}

void convert(char input_file[],char bin_file[])/*this function create to files 
and convert files(txt file->bin file)*/
{
	int a,count=0;
	char ch[CHAR_MAX],array[50],temp[20];
	char *ptr;
	combine_type person_info;
	FILE *inp,*outp;
	inp=fopen(input_file,"r");
	outp=fopen(bin_file,"wb");
	/*this loop for scan input txt file until end of file and write to .bin
	file*/
	while(fscanf(inp,"%s",ch)!=EOF){
		/*this control for person type*/
		if(strcmp(ch,"Instructor,")==0){
			person_info.type='I';
			/*each line scan and assign person_info*/
			fgets(array,50,inp);
			ptr=strtok(array," "); 
			strcpy(person_info.person_t.person1.name,ptr);
			ptr=strtok(NULL,",");
			strcpy(person_info.person_t.person1.surname,ptr);
			ptr=strtok(NULL,",");
			strcpy(person_info.person_t.person1.department,ptr);
			ptr=strtok(NULL,",");
			strcpy(person_info.person_t.person1.class1,ptr);
			ptr=strtok(NULL,",");
			strcpy(person_info.person_t.person1.class2,ptr);
			ptr=strtok(NULL," ");
			strcpy(temp,ptr);
			sscanf(temp,"%lf",&person_info.person_t.person1.salary);
			/*call function for updating salary*/
			person_info=salary_rise(person_info);
			/*write to output .bin file*/
			fwrite(&person_info,sizeof(person_info),1,outp);
			/*tested for print to screen*/
			fread(&person_info,sizeof(person_info),1,outp);
			printf("%c %s %s %2s %s %s %lf\n", person_info.type, 
person_info.person_t.person1.name, person_info.person_t.person1.surname, 
person_info.person_t.person1.department,person_info.person_t.person1.class1, 
person_info.person_t.person1.class2, person_info.person_t.person1.salary);
		}
		else if(strcmp(ch,"Employee,")==0) {
			person_info.type='E';
			/*/*each line scan and assign person_info*/
			fgets(array,50,inp);
			ptr=strtok(array," "); 
			strcpy(person_info.person_t.person2.name,ptr);
			ptr=strtok(NULL,",");
			strcpy(person_info.person_t.person2.surname,ptr);
			ptr=strtok(NULL,",");
			strcpy(temp,ptr);
			sscanf(temp,"%lf",&person_info.person_t.person2.salary);
			ptr=strtok(NULL," ");
			strcpy(temp,ptr);
			sscanf(temp,"%c",&person_info.person_t.person2.degree);
			/*call function for updating salary*/
			person_info=salary_rise(person_info);
			/*write to output .bin file*/
			fwrite(&person_info,sizeof(person_info),1,outp);
			/*tested for print to screen*/
			fread(&person_info,sizeof(person_info),1,outp);
			printf("%c %s %s %lf %c\n", person_info.type, 
person_info.person_t.person2.name,person_info.person_t.person2.surname, 
person_info.person_t.person2.salary, person_info.person_t.person2.degree);
		}
	}
	fclose(inp);
	fclose(outp);
}

/*########################################################################### */
/*                    End of  HW09_Sahin_Egilmez_131044059_part1.c            */
/*########################################################################### */

