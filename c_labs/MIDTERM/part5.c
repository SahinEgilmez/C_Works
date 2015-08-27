/*Writen by Arzu Kakisim as a sample solution for Midterm part5 CSE108   */
/*GTU, Computer Engineering, April,24th, 2015                           */

#include <stdio.h>

/*Implements multiplication  recursively*/
/*Input: Two positive integers n and m*/
/*Output: The product of n and m*/

int MultiplicationRec(int n, int m)
{
   if (n% 2 == 0)
      return MultiplicationRec(n/2, 2*m);
   else if ( n == 1)
      return m;
   else 
      return MultiplicationRec((n - 1)/2, 2*m) +m;
}

int main()
{    
     int result;
     int a=50;
     int b=65;
     
     result=MultiplicationRec(a,b);
     
     printf("Result = %d", result);
    
     return 0;
}
