#include<stdio.h>
#define TRUE 1
#define FALSE 0

/*----- PART I-------*/

void ReadAndPrint(FILE *input_file)
{
  int day,v,t;
  fscanf(input_file,"%d %d %d",&day,&v,&t);
  printf("%dth of the month:\t Wind has a %d km/h velocity and it is %d C",day,v,t);
}


/*--------PART II--------------*/


int is_windless(int v)
{
  if (v<20)
    return TRUE;
  else
    return FALSE; 
}
 
int is_windy(int v)
{
  if (v>=21 && v<50)
    return TRUE;
  else
    return FALSE; 
}

int is_stormy(int v)
{
  if (v>=51)
    return TRUE;
  else
    return FALSE; 
}

int is_cold(int temp)
{
  if (temp<10)
    return TRUE;
  else
    return FALSE; 
}

int is_warm(int temp)
{
  if (temp>=11 && temp<25)
    return TRUE;
  else
    return FALSE; 
}

int is_hot(int temp)
{
  if (temp>26 && temp<40)
    return TRUE;
  else
    return FALSE; 
}

/*-------PART III--------*/

int is_safe_to_fly(int v,int temp)
{
  if(is_cold(temp) && is_stormy(v))
    return TRUE;
  else
    return FALSE;
}

void main()
{
 FILE *input;
 input=fopen("input.txt","r");
 int v,temp,day;
 fscanf(input,"%d %d %d",&day,&v,&temp);

 if(is_windless(v))
   printf("%dth of the month: is Windless and ",day);

 else if(is_windy(v))
   printf("%dth of the month: is Windy and ",day);
 
 else if(is_stormy(v))
   printf("%dth of the month: is a Stormy and ",day);

 else 
   printf("Error in Reading File\n");

 if(is_cold(temp))
   printf("Cold day\n");
 
 else if(is_warm(temp))
   printf("Warm day\n");
 
 else if(is_hot(temp))
   printf("Hot day\n");
 
 else 
   printf("Error in Reading File!\n");
 
 if(is_safe_to_fly)
   printf("Safe For Flight\n");
 else
   printf("Dangerous For Flight\n");
}
