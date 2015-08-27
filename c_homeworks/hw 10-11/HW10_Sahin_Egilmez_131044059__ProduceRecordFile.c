#include<stdio.h>
#include"part1.h"
int main()
{
	int num,id,i;
	Appointment_t appo;
	FILE *inp, *outp;
	inp=fopen("produce_records.txt","r");
	outp=fopen("Records.bin","wb");
	fscanf(inp,"%d",&num);
	fwrite(&num,sizeof(int),1,outp);
	for(i=0;i<num;i++){	
		fscanf(inp,"%d",&appo.app_id);
		fwrite(&appo.app_id,sizeof(int),1,outp);
		fscanf(inp,"%d",&appo.patient_id);
		fwrite(&appo.patient_id,sizeof(int),1,outp);
		fscanf(inp,"%d",&appo.hour);
		fwrite(&appo.hour,sizeof(int),1,outp);
	}
	
	fclose(outp);
	outp=fopen("Records.bin","rb");
	i=0;
	fread(&id, sizeof(int), 1, outp);
	printf("%d ",id);
	while(i<num) {
		fread(&appo.app_id,sizeof(int),1,outp);
		printf("%d ",appo.app_id);
		fread(&appo.patient_id,sizeof(int),1,outp);
		printf("%d ",appo.patient_id);
		fread(&appo.hour,sizeof(int),1,outp);
		printf("%d ",appo.hour);
		i++;
	}
	fclose(inp);
	fclose(outp);
	return 0;
}
