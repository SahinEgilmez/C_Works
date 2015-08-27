#include<stdio.h>
#include<string.h>

#define STR_SIZE 100
#define MAX_SIZE 10

/*--------PART1---------*/
int read_list(const char* file_name,char str_array[][STR_SIZE]);
void print_list(char str_array[][STR_SIZE],int size);

/*--------PART2---------*/
void sort_names(char names[][STR_SIZE],char birthdays[][STR_SIZE],int n);

/*--------PART3---------*/
void uppercase_str(char *str);

/*--------PART4---------*/
void most_used(const char birthdays[][STR_SIZE],int n,char month[]);

int main()
{
    int names_size,birthdays_size,n,i;
    char names[MAX_SIZE][STR_SIZE];
    char birthdays[MAX_SIZE][STR_SIZE];
    char month[STR_SIZE];
    
    names_size=read_list("name_list.txt",names);
    birthdays_size=read_list("birthday_list.txt",birthdays);
    
    if(names_size!=birthdays_size)
        printf("There is Something Wrong; Check Your Lists!!\n");
    else
    {
        n=names_size;
        /*------PART2--------*/
        sort_names(names,birthdays,n);
        print_list(names,n);
        printf("\n");
        
        print_list(birthdays,n);
        
        /*--------PART3--------*/
        for(i=0;i<n;i++)
        {
            uppercase_str(names[i]);
        }
        
        printf("\n");
        print_list(names,n);
        
        /*---------PART4----------*/
        most_used(birthdays,n,month);
        printf("\nMost Used Month Is %s\n",month);
    }
    return 0;
}


int read_list(const char* file_name,char str_array[][STR_SIZE])
{
    FILE *inf;
    int i;
    i=0;
    inf=fopen(file_name,"r");
    if(inf==NULL)
        printf("File Could Not Be Opened!!");
    else
    {
        while(fgets(str_array[i],STR_SIZE,inf)!=NULL)
        {
            i++;
        }
    }
    fclose(inf);
    return i;
}

void print_list(char str_array[][STR_SIZE],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%s",str_array[i]);
    }
}

void sort_names(char names[][STR_SIZE],char birthdays[][STR_SIZE],int n)
{
    int i,j;
    char temp[STR_SIZE];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(names[i],names[j])>0)
            {
                strcpy(temp,names[i]);
                strcpy(names[i],names[j]);
                strcpy(names[j],temp);
                
                strcpy(temp,birthdays[i]);
                strcpy(birthdays[i],birthdays[j]);
                strcpy(birthdays[j],temp);
            }
        }
    }
}

void uppercase_str(char *str)
{
    int i;
    i=0;
    while(str[i]!='\0')
    {
        if(str[i]==' ')
            str[i+1]=toupper(str[i+1]);
        else
            str[0]=toupper(str[0]);
        i++;
    }
}

void most_used(const char birthdays[][STR_SIZE],int n,char month[])
{
    int i,j,day,year,count,max;
    char temp[STR_SIZE],candidate[STR_SIZE];
    max=0;
    for(i=0;i<n;i++)
    {
        sscanf(birthdays[i],"%d %s %d",&day,candidate,&year);
        for(j=i+1;j<n;j++)
        {
            sscanf(birthdays[j],"%d %s %d",&day,temp,&year);
            if(strcmp(candidate,temp)==0)
                count++;
        }
        if(max<count)
        {
            max=count;
            strcpy(month,candidate);
        }
        count=0;
    }
}
