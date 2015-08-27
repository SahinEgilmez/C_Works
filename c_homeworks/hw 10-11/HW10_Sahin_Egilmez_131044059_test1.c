/*##########################################################################  */
/*                                                                            */
/* HW10_Sahin_Egilmez_131044059_test1.c                                      */
/* 									      */
/* Created on 23/05/2015 by Sahin Egilmez                                     */
/*                                                                            */
/*Description                                                                 */
/*                                                                            */
/*C program for testing part1.h library                                       */
/*Inputs:                                                                     */
/*      - part1.h library                                                     */
/*Outputs:                                                                    */
/*	- files and appointments array                                        */
/*########################################################################### */
/*----------------------------------------------------------------------------*/
/*                           Includes                                         */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#include"HW10_Sahin_Egilmez_131044059_part1.h"
	
int main(int argc, char *argv[])
{
	Files_t files;/*define files structure*/
	Working_hours_t hours;/*define hours structure*/
	Appointment_t *arr;/*define appointment_t type array*/
	int size,num,i;
	/*call function and fill in the structure(files and hours)*/
	get_main_arguments(argc,argv,&hours,&files);
	/*call function and fill the arr array*/
	arr=getRequests(&files,&size);
	/*call function and print files names to parameters file*/
	print_parameters(&files,&hours);
	/*call function and write all appointments to readable records file*/	
	write_appointments(arr,size,&files);

	return 0;
}
/*########################################################################### */
/*                    End of  HW10_Sahin_Egilmez_131044059_test1.c            */
/*########################################################################### */
