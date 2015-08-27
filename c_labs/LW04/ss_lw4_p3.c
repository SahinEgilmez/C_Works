/*##########################################################*/
/*Sample Solution LW4                                       */
/*________________________                                  */
/*Author: Meltem Çetiner  on Mar 03, 2015                   */
/*                                                          */
/*##########################################################*/

#include <stdio.h>   /* defines fopen,fclose,fscanf,fprinf, and   EOF*/

#define INPUT_FILE "polynomial_variables.txt"

/* prototypes*/
void print_term(int coef, int deg, char x);
int  eval_term(int coef,int deg, int value);
int  eval_print_polynomial( int var_value  , FILE* file);
 
/*driver code*/
void main( )
{  
   int coefficient, degree, value;
   char symbol;
   FILE* input_file = fopen(INPUT_FILE , "r");    /*Input file pointer*/

   printf("\n*********************** part3 **********\n");    
   
   printf("Enter the value of variable of the term : ");
   scanf("%d",&value); 
 
   printf("=%d \n",eval_print_polynomial( value  , input_file));
   
   fclose(input_file);
}
 
/*İmplementation of the functions*/

/*
pre:  a coefficient "coef"  and degree of the equation "deg", and one character "x"
post: print the term */
void print_term(int coef, int deg, char x)
{
     printf( "%d" ,coef);
     int n ; /*loop control variables*/
     for( n =0; n <deg;n++)
         printf("*%c",x);
     printf( "\n");
}

/*
pre:  a coefficient "coef"  and degree  "deg", and the  value of variable  "var_val"  of the equation
post: evaluate the term */
int  eval_term(int coef,int deg, int var_val)
{
   int total=coef;/* the result of the term*/
   int n ; /*loop control variables*/
   for( n =0; n < deg;n++)
     total=total*var_val;  
    
   return total;
}
/**/
int  eval_print_polynomial( int var_value , FILE* file)
{
   int coef=0,        /*coefficient of the term*/
       deg=0;         /*degree of the term*/
   int flag=0;        /*shows the beginning of the term*/
   int res_term=0;    /*result of the term*/
   int res_poly=0;    /*result of the poly*/
   int check_EOF=0;    /*check the EOF*/
   check_EOF=fscanf(file, "%d",&coef);
   printf("f(%d )= ",var_value);
   while (check_EOF != EOF)
   { 
      if(flag==0)
        printf("+");
      flag=1;
      fscanf(file, "%d",&deg); 
      /*print_term(coef,deg,'X');*/
      res_term=eval_term(coef,deg,var_value);
      /*printf("res_term: %d \n",res_term);*/
      res_poly=res_poly+res_term;
      
      check_EOF=fscanf(file, "%d",&coef);
      printf("res_poly: %d \n",res_poly);
   }

   return res_poly;
    
   
}


