/*##########################################################*/
/*Sample Solution LW4                                       */
/*________________________                                  */
/*Author: Meltem Çetiner  on Mar 03, 2015                   */
/*                                                          */
/*##########################################################*/

#include <stdio.h>   /* defines fopen,fclose,fscanf,fprinf, and   EOF*/


/* prototypes*/
void print_term(int coef, int deg, char x);
int  eval_term(int coef,int deg, int value);
int  eval_print_polynomial( int var_value  , FILE* file);
void der_term(int coef, int deg ,char x);
int  der_term_until_cons(int coef, int deg ,char x);
 
/*driver code*/
void main( )
{  
   int coefficient, degree, value;
   char symbol;
  
   printf("\n*********************** part1  & part2 **********\n");    
   
   printf("Enter the coefficient of the term : ");
   scanf("%d",&coefficient);
 
   printf("Enter the degree of the term : ");
   scanf("%d",&degree);
   
   printf("Enter the character of the term : ");
   scanf("%c %c",&symbol,&symbol);
   
   printf("Enter the value of the term : ");
   scanf("%d",&value);
 
   printf("f(%d) =",value);
   print_term(coefficient, degree, symbol);
   
   printf("         =%d\n",eval_term(coefficient, degree,value));

   printf("\n*********************** part4 **********\n");    
   
   printf("f'=");
   der_term(coefficient, degree, symbol);

   printf("\n*********************** part5 **********\n");
   der_term_until_cons(coefficient, degree, symbol);
   

   
   
}
 
/*İmplementation of functions*/

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

   int res_term=0;    /*result of the term*/
   int res_poly=0;    /*result of the poly*/
   int check_EOF=0;    /*check the EOF*/
   check_EOF=fscanf(file, "%d",&coef);
   // printf("coef: %d",coef);
   while (check_EOF != EOF)
   {
      fscanf(file, "%d",&deg);
      //printf("deg : %d",deg);
      res_term=eval_term(coef,deg,'x');
      res_poly=res_poly+res_term;
      printf("+");
      print_term(coef,deg,'X');
      fscanf(file, "%d",&coef);
      //printf("coef: %d",coef);
   }

   return res_poly;
    
   
}



/*take the derivative of a term. The program takes the two integers as a coefficient “coef” and degree of the equation “deg”, and one character for representing the value “X”*/
void der_term(int coef, int deg ,char x)
{    
     printf( "%d" ,coef*deg);
     int n ; /*loop control variables*/
     for( n =1; n < deg  ; n++)
         printf("*%c",x);
     printf("\n");
}




/*take the derivatives of a term until you get a constant number. Again , The program takes two integers as a coefficient “coef” and degree of the term “deg”, and one character for representing the variable*/
int der_term_until_cons(int coef, int deg ,char x)
{
    int c_der_deg ; /*counter of the derivative degree */
    int cascade_val=coef;
     for( c_der_deg=0; c_der_deg<=deg ;c_der_deg++)
     {    
          printf("f");
          int counter_prime;/*counter of the prime*/
          for(counter_prime=0;counter_prime<c_der_deg ;counter_prime++ )
              printf("'");
          printf("=");
          
          print_term(cascade_val,(deg-c_der_deg),x);
          printf("\n");
          cascade_val=cascade_val*(deg-c_der_deg);
         
     }

     return cascade_val;
     
}




