#include"HW10_Sahin_Egilmez_131044059_part2.h"

node_t* build_ll(Appointment_t appointmens[], int size, const Working_hours_t* hours)
{	
	int i,time;
	node_t *head,*temp,*node,*node2;
	head = (node_t *)malloc((sizeof(node_t)));
        head->app_id = appointmens[0].app_id;
	head->patient_id=appointmens[0].patient_id;
	head->hour=appointmens[0].hour;        
	head->next = NULL;
	node=head;
	for(i=1;i<size;i++){
		temp=(node_t*)malloc((sizeof(node_t)));
		temp->app_id=appointmens[i].app_id;
		temp->patient_id=appointmens[i].patient_id;
		temp->hour=appointmens[i].hour;
		temp->next=NULL;
		node->next=temp;
		node=temp;
	}
	
	node=head;
		
	while(head!=NULL){
		if(head->hour>hours->end || head->hour<hours->start){
			temp=head;
			head=head->next;
			free(temp);		
			
		}
		head=head->next;
	}
	head=node;
	
	node=head;
	while(node!=NULL){
		
		time=node->hour;
		node2=node->next;
		while(node2!=NULL){
			
			if(node2->hour==time){
				temp=node2;		
				node2=temp->next;
				free(temp);
			}
			node2=node2->next;
		}
		
		node=node->next;
		
	}	
	
	return	head;
}
void write_accepted_app(node_t* head, const Files_t* files)
{
	int no;
	FILE* outp;
	outp=fopen(files->accepted_appo_file_n,"w");
	if(head->name!=NULL){
		fprintf(outp,"no;id;patient_id;name;history;hour\n");
		no=1;		
		while(head!=NULL){
			fprintf(outp,"%d;%d;%d;%s;%s;%d\n",no,head->app_id,
			head->patient_id,head->name,head->history,head->hour);
			no++;
			head=head->next;
		}
	}
	else{
		fprintf(outp,"no;id;patient_id;hour\n");
		no=1;		
		while(head!=NULL){
			fprintf(outp,"%d;%d;%d;%d\n",no,head->app_id,
			head->patient_id,head->hour);
			no++;
			head=head->next;
		}
	}
	fclose(outp);
}
void add_personal_data(node_t* head, const Files_t* files)
{
	char str[200],temp[100],tag[20],temp3[30],*name;
	char *temp2;
	node_t* node;
	int i,id;
	FILE *inp;
	inp=fopen(files->patients_file_n,"r");
	fscanf(inp,"%s\n",tag);
	fscanf(inp,"%s\n",tag);
	do{
		fgets(temp,100,inp);
		temp2=strtok(temp,">");
		temp2=strtok(NULL,"<");
		sscanf(temp2,"%d",&id);
		printf("%d\n",id);
		temp2=strtok(NULL," ");
		fgets(temp,100,inp);
		temp2=strtok(temp,">");
		name=strtok(NULL,"<");
		temp2=strtok(NULL," ");
		fscanf(inp,"%s",temp3);
		strcpy(str,temp3);
		while(strcmp(temp3,"</Patient>")!=0){
			fscanf(inp,"%s",temp3);
			strcat(str,temp3);
			strcat(str," ");
		}
		strtok(str,">");
		temp2=strtok(NULL,"<");
		strcpy(str,temp2);
		
			
		
		node=head;		
		while(node!=NULL){
			if(node->patient_id==id){
				strcpy(node->name,name);
				
				node->history=(char*)malloc((sizeof(char*)));
				if(strcmp(str,"/History>")!=0)
				node->history=str;
				else
				node->history=NULL;
			#ifdef DEBUG_MODE
				printf("%s\n\n",node->history);
			#endif
			}
			else
				node->history=NULL;
		node=node->next;
		}
		fscanf(inp,"%s\n",tag);
		
	}while(strcmp(tag,"</Records>")!=0);
	
	fclose(inp);
	
}
int delete_appointments(node_t** head, const Files_t* files)
{
	int num,count;
	node_t* node,*temp; 
	FILE *inp;
	inp=fopen(files->delete_file_n,"r");
	while(fscanf(inp,"%d",&num)!=EOF){	
		printf("%d\n",num);	
		node=(*head);		
		while(node!=NULL){
			
			if(node->app_id==num){
				temp=node;		
				node=node->next;
				free(temp);
				count++;
			}
		node=node->next;
		}
	}
	
	fclose(inp);
	return count;
	
}
void free_list(node_t* head)
{	
	node_t* temp;
	while(head!=NULL){
		temp=head->next;
		free(head->name);
		free(head->history);
		free(head);
		head=temp;	
	}
	free(head);
	
}


