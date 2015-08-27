/*##########################################################################  */
/*                                                                            */
/* HW10_Sahin_Egilmez_131044059_test2.c                                      */
/* 									      */
/* Created on 23/05/2015 by Sahin Egilmez                                     */
/*                                                                            */
/*Description                                                                 */
/*                                                                            */
/*C program for testing part1.h library                                       */
/*Inputs:                                                                     */
/*      - part1.h and part2.h library                                                     */
/*Outputs:                                                                    */
/*	- files and appointments array                                        */
/*########################################################################### */
/*----------------------------------------------------------------------------*/
/*                           Includes                                         */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#include"HW10_Sahin_Egilmez_131044059_part2.h"
#include"HW10_Sahin_Egilmez_131044059_part1.h"
int main(int argc, char *argv[])
{
	Files_t files;
	Working_hours_t hours;
	Appointment_t *arr;
	node_t* node,*temp;
	int size,num,i;
	get_main_arguments(argc,argv,&hours,&files);
	arr=getRequests(&files,&size);
	
	print_parameters(&files,&hours);
	write_appointments(arr,size,&files);
	
	node=build_ll(arr,size,&hours);
	temp=node;	
	#ifndef DEBUG_MODE
	while(node!=NULL){
		printf("hour=%d\n",node->hour);
		node=node->next;
	}
	#endif
	
	node=temp;
	add_personal_data(node,&files);	
	node=temp;
	
	delete_appointments(&node,&files);
			
	write_accepted_app(node,&files);
	free_list(node);
	return 0;
}

/*########################################################################### */
/*                    End of  HW10_Sahin_Egilmez_131044059_test2.c            */
/*########################################################################### */
