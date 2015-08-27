#include <stdio.h>

/*--------PART IV--------*/

void report_runway_assignment(FILE *file,int pistid,int mypist)
{
  fprintf(file,"plane 1 will take off from the runway %d\n",pistid);
  fprintf(file,"plane 2 will take off from the runway %d\n",mypist);
}

void main()
{
  FILE *report;
  report=fopen("report.txt","w");
  int pistid,mypist;
  printf("Which runway you will take off from?\n");
  scanf("%d",&pistid);
  if(pistid==1)
    mypist=2;
  else if(pistid==2)
    mypist=1;
  else 
    printf("Wrong Pist ID");
  report_runway_assignment(report,pistid,mypist);
}
