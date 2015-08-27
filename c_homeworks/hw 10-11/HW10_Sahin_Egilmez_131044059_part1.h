#include<stdio.h>
#include<stdlib.h>
#define START_HOUR 9
#define END_HOUR 17
#define NORMAL_MODE
#ifndef PART2
typedef struct{ int app_id;
		int patient_id;
		int hour; }Appointment_t;
typedef struct{ int start;
		int end; }Working_hours_t;
typedef struct{ const char *records_file_n;
		const char* patients_file_n;
		const char* delete_file_n;
		const char* readable_records_file_n;
		const char* accepted_appo_file_n;
		const char* parameters_file_n; }Files_t;
typedef struct  node_s{ int app_id;
		int patient_id;
		char name[50];
		char* history;
		int hour;
		struct node_s* next;}node_t;
#endif
extern Appointment_t* getRequests(const Files_t* files, int* size);
extern void write_appointments(Appointment_t appointments[], int size, const Files_t* files);
extern void get_main_arguments(int argc, char *argv[], Working_hours_t* hours, Files_t* 
files);
extern void print_parameters(const Files_t* files, const Working_hours_t* hours);
