/*##########################################################################  */
/*                                                                            */
/* HW08_Sahin_Egilmez_131044059_part2.c                                       */
/* 									      */
/* Created on 19/04/2015 by Sahin Egilmez                                     */
/*                                                                            */
/*Description                                                                 */
/*                                                                            */
/*C program for  handle the appointments of a doctor                          */
/*Inputs:                                                                     */
/*      - txt file for people and appointments                                */
/*Outputs:                                                                    */
/*	- Print to file appointments                                          */
/*########################################################################### */
/*----------------------------------------------------------------------------*/
/*                           Includes                                         */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
/*----------------------------------------------------------------------------*/
/*                           Defines                                          */
/*----------------------------------------------------------------------------*/
#define MAX_SIZE 100
typedef enum{MALE=0,FEMALE=1} Gender_t;
typedef enum{ JANUARY=1,FEBRUARY,MARCH,APRIL,MAY,JUNE,JULY,
	      AUGUST,SEPTEMBER,OCTOBER,NOVEMBER,DECEMBER} Months_t;
typedef struct{ int first_half, second_half;} TCId_no_t;
typedef struct{ int hour,minute;} Time_t;
typedef struct{	TCId_no_t id_no;
		char name[30], surname[30]; 	
		Gender_t gender;} People_t;
typedef struct{ int year,day;
		Months_t month;
		Time_t time;} Date_t;
typedef struct{ People_t people;
		Date_t date;} Appointment_t;
/*########################################################################### ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­*/
/*                         Function Prototypes                                */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­########################################################################### */
int get_people(const char *file_name, People_t people[], int max_size);/* reads 
all people from the file and record them into the array. Returns number records 
read.*/
int get_appointments(const char *file_name, Appointment_t appointments[], int 
max_size);/* reads all appointment records from the file and record them into the
array leaving name and surname fields unassigned. Returns number records read.*/
void write_names(Appointment_t appointments[], int size_app, const People_t 
people[], int size_people);/*fills the name and surname fields of people fields
of  appointments.*/
int check_appointments(Appointment_t appointments[], int size);/* considers all 
appointment requests, deletes the rejected ones and returns the new size as the 
return value.*/
void sort_appointments(Appointment_t appointments[], int size);/*sort the array 
with respect to the date of the appointment.*/
void write_appointments(const char *file_name, Appointment_t appointments[], int 
size);/*writes all appointments to a text file.*/
void delete_app(Appointment_t appointments[], int size);/*deletes the same as 
appointments */
void change_app(Appointment_t appointments[]);/*change two appointment array 
element*/
int main() 
{	
	int number_p,number_app,i,a;/*defines return values and other int.*/
	People_t people[MAX_SIZE];/*define people array*/
	Appointment_t appointmentsreqs[MAX_SIZE];/*define appointment array*/	
	
	number_p=get_people("People.txt",people,MAX_SIZE);/*call get people 
	function and fill people array from file*/
	number_app=get_appointments("AppointmentReqs.txt",appointmentsreqs,
	MAX_SIZE);/*call get appointments function and fill appointments array
	from file*/
	write_names(appointmentsreqs,number_app,people,number_p);/*write name
	and surname to end of appointment*/
	a=check_appointments(appointmentsreqs,number_app);/*check and delete 
	rejected appointments*/
	sort_appointments(appointmentsreqs,a);/*sort appointments with respect 
	date of appointments*/
	
	write_appointments("Appointments.txt",appointmentsreqs,a);/*write to file 
        all appointments */
	return 0;
}

int get_people(const char *file_name, People_t people[], int max_size)/* reads 
all people from the file and record them into the array. Returns number records 
read.*/
{
	int i=0,a=0,count=0;
	char ch;
	FILE *inp;
	inp=fopen(file_name,"r");
	/*scan all elements from people array*/ 
	while(fscanf(inp,"%6d%5d%s %s %c",&people[i].id_no.first_half, &people[i].id_no.second_half,people[i].name, people[i].surname, &ch)!=EOF && i<=max_size) {
	/*this control for conversation char from Gender_t */	
	if(ch=='M')
		people[i].gender=MALE;
	else if(ch=='F')
		people[i].gender=FEMALE;
	i++;	
	count++;	
	}
	fclose(inp);
	return count;/* Returns number records read.*/
}

int get_appointments(const char *file_name, Appointment_t appointments[], int 
max_size)/* reads all appointment records from the file and record them into the
array leaving name and surname fields unassigned. Returns number records read.*/
{
	int i=0,a=0,count=0,month;
	FILE *inp;
	inp=fopen(file_name,"r");
	/*this loop for scan the all of appointments elements from file*/ 
	while(fscanf(inp,"%6d%5d %d %d %d %d:%d",
	&appointments[i].people.id_no.first_half, 
	&appointments[i].people.id_no.second_half, &appointments[i].date.year,
	&month, &appointments[i].date.day,&appointments[i].date.time.hour,
	&appointments[i].date.time.minute)!=EOF && i<=max_size) {
	appointments[i].date.month=month;/*for the integer->month converting*/
	i++;
	count++;
	}
	fclose(inp);
	return count;/*Returns number records read.*/
}

void write_names(Appointment_t appointments[], int size_app, const People_t 
people[], int size_people)/*fills the name and surname fields of people fields
of  appointments.*/
{
	int i,k;
	/*this loops for fills the name and surname fields*/
	for(i=0;i<=size_app;i++) {
	for(k=0;k<=size_people;k++) {
	if(appointments[i].people.id_no.first_half==people[k].id_no.first_half &&
        appointments[i].people.id_no.second_half==people[k].id_no.second_half) {
			strcpy(appointments[i].people.name,people[k].name);
			strcpy(appointments[i].people.surname,people[k].surname);
	}
	}
	}
}

int check_appointments(Appointment_t appointments[], int size)/* considers all 
appointment requests, deletes the rejected ones and returns the new size as the 
return value.*/
{
	int i,k;
	int new_size=size;
	/*this loops check the appointments whether ıt is the same*/
	for(i=0;i<size;i++) {
	for(k=i+1;k<size;k++) {
	     if(!(appointments[k].date.time.minute==0 ||
		appointments[k].date.time.minute==30)){
		delete_app(&appointments[k],size-k+1);
		size--;
		k=i;
		}
       	     else if(appointments[i].date.year==appointments[k].date.year &&
             appointments[i].date.month==appointments[k].date.month &&
             appointments[i].date.day==appointments[k].date.day &&
             appointments[i].date.time.hour==appointments[k].date.time.hour &&
	     appointments[i].date.time.minute==appointments[k].date.time.minute){
		delete_app(&appointments[k],size-k+1);
		size--;
		k=i;
		}
	}
	}
	return size;/*return new size*/
}
void sort_appointments(Appointment_t appointments[], int size)/*sort the array 
with respect to the date of the appointment.*/
{
	int i,k;
	/*this loops for bubble sorting for appointments*/
	for(i=0;i<size-1;i++){
	for(k=0;k<size-1;k++) {
	if(appointments[k].date.year>appointments[k+1].date.year)
		change_app(&appointments[k]);
	else if(appointments[k].date.month>appointments[k+1].date.month)
		change_app(&appointments[k]);
	else if(appointments[k].date.day>appointments[k+1].date.day)
		change_app(&appointments[k]);
	else if(appointments[k].date.time.hour>appointments[k+1].date.time.hour)
		change_app(&appointments[k]);
	else if(appointments[k].date.time.minute>appointments[k+1].date.time.minute);
			change_app(&appointments[k]);
	}
	}
}
void write_appointments(const char *file_name, Appointment_t appointments[], 
			int size)/*writes all appointments to a text file.*/
{
	int k;
	char ch;
	FILE *inp;
	inp=fopen(file_name,"w");
	/*this loops for writing all appointments resulting*/
	for(k=0;k<size;k++) {
	if(appointments[k].people.gender==MALE)
		ch='M';
	else if(appointments[k].people.gender==FEMALE)
		ch='F';
	fprintf(inp,"%d %d %d %d:%d %6d%5d %s %s %c\n",appointments[k].date.year, 
	appointments[k].date.month, appointments[k].date.day,
	appointments[k].date.time.hour,	appointments[k].date.time.minute,
	appointments[k].people.id_no.first_half, appointments[k].people.id_no.second_half,
	appointments[k].people.name, appointments[k].people.surname,ch); 
	}
	fclose(inp);
}
void delete_app(Appointment_t appointments[], int size)/*deletes the same as 
appoinments */
{
	int i=0,k;
	for(k=0;k<(size);k++){
	strcpy(appointments[k].people.name,appointments[k+1].people.name);
	strcpy(appointments[k].people.surname,appointments[k+1].people.surname);
        appointments[k].people.id_no.first_half=appointments[k+1].people.id_no.first_half;
	appointments[k].people.id_no.second_half=appointments[k+1].people.id_no.second_half;
	appointments[k].date.year=appointments[k+1].date.year;
        appointments[k].date.month=appointments[k+1].date.month;
        appointments[k].date.day=appointments[k+1].date.day; 
        appointments[k].date.time.hour=appointments[k+1].date.time.hour; 
        appointments[k].date.time.minute=appointments[k+1].date.time.minute;
	}
}
void change_app(Appointment_t appointments[])/*change two appointment array 
element*/
{
	int temp,k=0;
	Date_t date_temp;
	TCId_no_t tc_temp;
	char name[30],surname[30];

	strcpy(name,appointments[k].people.name);
	strcpy(appointments[k].people.name,appointments[k+1].people.name);
	strcpy(appointments[k+1].people.name,name);

	strcpy(surname,appointments[k].people.surname);
	strcpy(appointments[k].people.surname,appointments[k+1].people.surname);
	strcpy(appointments[k+1].people.surname,surname);

	tc_temp=appointments[k].people.id_no;
	appointments[k].people.id_no=appointments[k+1].people.id_no;
	appointments[k+1].people.id_no=tc_temp;

	date_temp=appointments[k].date;
	appointments[k].date=appointments[k+1].date;
	appointments[k+1].date=date_temp;
}

/*########################################################################### */
/*                    End of  HW08_Sahin_Egilmez_131044059_part2.c            */
/*########################################################################### */


