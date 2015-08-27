/*##########################################################################  */
/*                                                                            */
/* HW2_Sahin_Egilmez_131044059_part2.c                                        */
/* 									      */
/* Created on 01/03/2015 by Sahin Egilmez                                     */
/*                                                                            */
/*Description                                                                 */
/*                                                                            */
/*C program that calculates letter grade of 5 students                        */
/*Inputs:                                                                     */
/*	- students name and surname                                           */
/*	- students, exam notes  					      */
/*Outputs:                                                                    */
/*	- contributions, lettergrade, credit                                  */
/*########################################################################### */
/*----------------------------------------------------------------------------*/
/*                           Includes                                         */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
/*########################################################################### ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­*/
/*                         Function Prototypes                                */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­########################################################################### */
int fgrade (double midterm1, double midterm2, double final);
double LetterGrade(int grade);
double GPA (char lettergrade);

int main()
{	
	char n1,s1,lg1;/*1st students information and lettergrade*/
	char n2,s2,lg2;/*2nd students information and lettergrade*/
	char n3, s3, lg3;/*3rd students information and lettergrade*/
	char n4, s4, lg4;/*4th students information and lettergrade*/
	char n5, s5, lg5;/*5th students information and lettergrade*/
	double note1, note2, note3, note4, note5;/*average from notes*/
	double a1,b1,f1,a2,b2,f2,a3,b3,f3,a4,b4,f4,a5,b5,f5;/*exams*/
	double c1, c2, c3, c4, c5;/*contributions*/

	/*creates the input,output files*/
	FILE *inp, *outp;
	inp=fopen("Students.txt", "r");
	outp=fopen("Grades.txt", "w");

	/*For 1st students*/
	/*read the students information and exams.*/
	fscanf(inp, "%c %c %lf %lf %lf\n", &n1, &s1, &a2, &b1, &f1);
	note1=fgrade(a1, b1, f1);/*calculates the average of the exams*/
	lg1=LetterGrade(note1);/*calculates the letter grade*/
	c1=GPA(lg1);/*calculates the contribution*/
	/*writes the resulting on the file*/
	fprintf(outp, "%c%c %3.0f %c %1.5f\n", n1, s1, note1 , lg1, c1);

	/*For 2nd students*/
	/*read the students information and exams.*/
	fscanf(inp, "%c %c %lf %lf %lf\n", &n2, &s2, &a2, &b2, &f2);
	note2=fgrade(a2, b2, f2);/*calculates the average of the exams*/
	lg2=LetterGrade(note2);/*calculates the letter grade*/
	c2=GPA(lg2);/*calculates the contribution*/
	fprintf(outp, "%c%c %3.0f %c %1.5f\n", n2, s2, note2 , lg2, c2);

	/*For 3rd students*/
	/*read the students information and exams.*/
	fscanf(inp, "%c %c %lf %lf %lf\n", &n3, &s3, &a3, &b3, &f3);
	note3=fgrade(a3, b3, f3);/*calculates the average of the exams*/
	lg3=LetterGrade(note3);/*calculates the letter grade*/
	c3=GPA(lg3);/*calculates the contribution*/
	fprintf(outp, "%c%c %3.0f %c %1.5f\n", n3, s3, note3 , lg3, c3);

	/*For 4th students*/
	/*read the students information and exams.*/
	fscanf(inp, "%c %c %lf %lf %lf\n", &n4, &s4, &a4, &b4, &f4);
	note4=fgrade(a4, b4, f4);/*calculates the average of the exams*/
	lg4=LetterGrade(note4);/*calculates the letter grade*/
	c4=GPA(lg4);/*calculates the contribution*/
	fprintf(outp, "%c%c %3.0f %c %1.5f\n", n4, s4, note4 , lg4, c4);

	/*For 5th students*/
	/*read the students information and exams.*/
	fscanf(inp, "%c %c %lf %lf %lf\n", &n5, &s5, &a5, &b5, &f5);
	note5=fgrade(a5, b5, f5);/*calculates the average of the exams*/
	lg5=LetterGrade(note5);/*calculates the letter grade*/
	c5=GPA(lg5);/*calculates the contribution*/
	fprintf(outp, "%c%c %3.0f %c %1.5f\n", n5, s5, note5 , lg5, c5);
	/*close to  files*/
	fclose(inp);
	fclose(outp);

	return 0;
}
/*this functions calculates the average of the exams*/
int fgrade(double midterm1, double midterm2, double final) 
{
	int grade;
	grade=(midterm1*0.3)+(midterm2*0.3)+(final*0.4);
	return grade;
}
/*this functions calculate the letter grade */
double LetterGrade(int grade)
{	
	char lettergrade,A,B,C,D,F;

	if(grade>=85)
	lettergrade='A';
	else if(grade>=70)
	lettergrade='B';
	else if(grade>=65)
	lettergrade='C';
	else if(grade>=40)
	lettergrade='D';
	else 
	lettergrade='F';
	
	return lettergrade;
}
/*this function calculates the contribution, print it on the screen*/
double GPA (char lettergrade)
{	double contribution;
	
	switch (lettergrade) {
	case 'A':
		contribution=4*3/20.0;
		printf("Lettergrade=A, credit=4; contribution=%f\n",
contribution);
		break;
	case 'B':
		contribution=3*3/20.0;
		printf("Lettergrade=B, credit=3; contribution=%f\n",
contribution);
		break;
	case 'C':
		contribution=2*3/20.0;
		printf("Lettergrade=C, credit=2; contribution=%f\n",
contribution);
		break;
	case 'D':
		contribution=1*3/20.0;
		printf("Lettergrade=D, credit=1; contribution=%f\n",
contribution);
		break;
	case 'F':
		contribution=0;
		printf("Lettergrade=F, credit=0; contribution=%f\n",
contribution);
}
	return contribution;

}

/*########################################################################### */
/*                  End of  HW2_Sahin_Egilmez_131044059_part2.c               */
/*########################################################################### */








