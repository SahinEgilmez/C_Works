#include"HW10_Sahin_Egilmez_131044059_part1.h"

	const char* default_records_file_n="Records.bin";
	const char* default_patients_file_n="Patients.xml";
	const char* default_delete_file_n="Delete.txt";
	const char* default_readable_records_file_n="Records.xml";
	const char* default_accepted_appo_file_n="Appoinments.csv";
	const char* default_parameters_file_n="Parameters.txt";
Appointment_t* getRequests(const Files_t *files, int* size)
{
	Appointment_t *arr;
	int rec_num,num,i;
	FILE *inp;
	
	inp=fopen(files->records_file_n,"rb");
	fread(&rec_num,sizeof(int),1,inp);
	arr=(Appointment_t *)calloc(rec_num,sizeof(Appointment_t));
	for(i=0;i<rec_num;i++) {
		fread(&num,sizeof(int),1,inp);
		arr[i].app_id=num;
		fread(&num,sizeof(int),1,inp);
		arr[i].patient_id=num;
		fread(&num,sizeof(int),1,inp);
		arr[i].hour=num;
	}
	#ifdef DEBUG_MODE
	printf("size=%d\n",rec_num);
	for(i=0;i<rec_num;i++){
		printf("app_id=%d\n",arr[i].app_id);
	}
	#endif
	fclose(inp);
	(*size)=rec_num;
	return arr;

}
void write_appointments(Appointment_t appointments[], int size, const Files_t* files)
{
	int i;
	FILE *outp;
	outp=fopen(files->readable_records_file_n,"w");
	fprintf(outp,"<Size>%d</Size>\n",size);
	fprintf(outp,"<Records>\n");
	for(i=0;i<size;i++){
	fprintf(outp,"	<Appointment>\n");
	fprintf(outp,"		<app_id>%d</app_id>\n",appointments[i].app_id);
	fprintf(outp,"		<patient_id>%d</patient_id>\n",appointments[i].patient_id);
	fprintf(outp,"		<hour>%d</hour>\n",appointments[i].hour);
	fprintf(outp,"	</Appointment>\n");
	}
	fprintf(outp,"</Records>");
	fclose(outp);

}
void get_main_arguments(int argc, char *argv[], Working_hours_t* hours, Files_t* 
files)
{
	int i;
	hours->start=START_HOUR;
	hours->end=END_HOUR;
	files->records_file_n=default_records_file_n;
	files->patients_file_n=default_patients_file_n;
	files->delete_file_n=default_delete_file_n;
	files->readable_records_file_n=default_readable_records_file_n;
	files->accepted_appo_file_n=default_accepted_appo_file_n;
	files->parameters_file_n=default_parameters_file_n;
	for(i=1;i<argc;i=i+2){
		if(strcmp(argv[i],"-r")==0)
			files->records_file_n=argv[i+1];
		else if(strcmp(argv[i],"-p")==0)
			files->patients_file_n=argv[i+1];
		else if(strcmp(argv[i],"-d")==0)
			files->delete_file_n=argv[i+1];
		else if(strcmp(argv[i],"-x")==0)
			files->readable_records_file_n=argv[i+1];
		else if(strcmp(argv[i],"-c")==0)
			files->accepted_appo_file_n=argv[i+1];
		else if(strcmp(argv[i],"-t")==0)
			files->parameters_file_n=argv[i+1];
		else if(strcmp(argv[i],"-s")==0)
			sscanf(argv[i+1],"%d",&hours->start);
		else if(strcmp(argv[i],"-e")==0)
			sscanf(argv[i+1],"%d",&hours->end);
	}
	#ifdef DEBUG_MODE
	printf("Records file=%s\n",files->records_file_n);
	printf("Patients file=%s\n",files->patients_file_n);
	printf("Delete file=%s\n",files->delete_file_n);
	printf("Readable records file=%s\n",files->readable_records_file_n);
	printf("Accepted appointments file=%s\n",files->accepted_appo_file_n);
	printf("Parameters file=%s\n",files->parameters_file_n);

	printf("Start hour=%d\n",hours->start);
	printf("End hour=%d\n",hours->end);
	#endif
	
}

void print_parameters(const Files_t* files, const Working_hours_t* hours)
{
	FILE *outp;
	outp=fopen(files->parameters_file_n,"w");
	fprintf(outp,"%s\n",files->records_file_n);
	fprintf(outp,"%s\n",files->patients_file_n);
	fprintf(outp,"%s\n",files->delete_file_n);
	fprintf(outp,"%s\n",files->readable_records_file_n);
	fprintf(outp,"%s\n",files->accepted_appo_file_n);
	fprintf(outp,"%s\n",files->parameters_file_n);

	fprintf(outp,"%d\n",hours->start);
	fprintf(outp,"%d\n",hours->end);
	fclose(outp);

}





