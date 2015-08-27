#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NORMAL_MODE
#define PART2
#define START_HOUR 9
#define END_HOUR 17
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

extern node_t* build_ll(Appointment_t appointmens[], int size, const Working_hours_t* hours);
extern void write_accepted_app(node_t* head, const Files_t* files);
extern void add_personal_data(node_t* head, const Files_t* files);
extern int delete_appointments(node_t** head, const Files_t* files);
extern void free_list(node_t* head);


