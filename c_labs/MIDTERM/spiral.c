/****************************************************************************************/
/*    This program is written by Meltem Cetiner						*/
/*	It s a simple sample solution of the q4						*/
/*											*/
/* Basically the function "fill" has 5 loops						*/
/* first loop for startin point like (0,0)(1,1)(2,2)...(the center point of the matrix) */
/* and start from each starting points and fill four sides				*/
/*    second for assignment top side ---increase cell column				*/
/*    third for assignment right side --increase cell row 				*/
/*    four for assignment down side  ---decrease cell column        			*/
/*    and fifth loop for assignment left side--decrease cell row			*/
/****************************************************************************************/
#include <stdio.h>

#define MAX_SIZE 20
#define DEBUG 0


/*fill the all cell of the matrix "m" by size "size" it will  start from zero and fill the matrix in spiral*/
void fill(int m[][MAX_SIZE],int size);

/*print matrix*/
void print_mat(int m[][MAX_SIZE],int size);


int main()
{

	int m[MAX_SIZE][MAX_SIZE]; // creat matrix
	int i=0,j=0;               // counter for initializing
	
	for(i=0;i<MAX_SIZE;i++)    // initiliaze the matrix
		for(j=0;j<MAX_SIZE;j++)
	   		m[i][j]=0;
	
	fill(m,9);  //test for size 9
	print_mat(m,9);

	fill(m,10); //test for size 10
	print_mat(m,10);
       
	return 0;
}

/****************************************************************************************************************/
/* parameters: "m"       : a size*size matrix                                                  			*/
/*             "size"    : the size of the matrix                                              			*/
/*             "start_p" : the startin point for filling process it means m[start_p][start_p]  			*/
/*             "value"   : the current value for assigning , it will increase for each step    			*/
/*														*/
/*														*/
/* basic sample													*/
/* calls with m,5,0,0												*/
/* will the matrix ;												*/
/*   0    1    2    3    4 											*/
/*  15    _    _    _    5 											*/
/*  14    _    _    _    6 											*/
/*  13    _    _    _    7 											*/
/*  12   11   10    9    8 											*/
/*														*/
/*	and then												*/
/* calls with m,5,1,16											*/
/* will the matrix ;												*/
/*   0    1    2    3    4 											*/
/*  15   16   17   18    5 											*/
/*  14   23    _   19    6 											*/
/*  13   22   21   20    7 											*/
/*  12   11   10    9    8 											*/
/*														*/
/*	and then												*/
/* calls with m,5,2,24											*/
/* will the matrix ;												*/
/*   0    1    2    3    4 											*/
/*  15   16   17   18    5 											*/
/*  14   23   24   19    6 											*/
/*  13   22   21   20    7 											*/
/*  12   11   10    9    8 											*/
/*														*/
/****************************************************************************************************************/
void fill(int m[MAX_SIZE][MAX_SIZE] ,int size)
{
   int start_point,value=0;
   for(start_point=0;start_point<=(int)(size/2);start_point++)      // it will start from 0,0 and continue like 1,1 ;2,2   
   {    		    //  repeats until the point equals to the center point of the matrix
	int i=start_point,j=start_point;

	for(; i <(size-start_point); i++){                         //fill it starting from the first point in left direction
		m[j][i] = value++ ;                       //the matrix is filled like   (first row)
                if (DEBUG)				  //  ***..*
		   printf("(%d,%d):%2d ",j,i,m[j][i]);    //  --...-
                                                          //  .....-
 							  //  --...-
			
	}

	if (DEBUG) printf("\n");
        --i;    // at the end it increases the integer i one more time so we should decrease it only one
        ++j;	// and we will continue with next step so we should increase the integer j one times
	for(; j<(size-start_point) ; j++ ){			  //to continue to fill in down direction
		m[j][i] = value++ ;   			  //the matrix is filled like  (last column)
                if (DEBUG)				  //  ***..*
		   printf("(%d,%d):%2d ",j,i,m[j][i]);    //  --..-*
                                                          //  ....-.
 							  //  ....-.
 							  //  --..-*		
	}
          
	if (DEBUG) printf("\n");
	--j;  // at the end it increases the integer j one more time so we should decrease it only one
        --i;  // and we will continue with next step so we should decrease the integer i one times
	for(; i>=start_point ; i-- ){		                  //and then in right direction
		m[j][i] = value++ ;                       // the matrix is filled like (last row)
                if (DEBUG)				  //  **...*
		   printf("(%d,%d):%2d ",j,i,m[j][i]);    //  --..-*
                                                          //  ....-.
                                                          //  --..-.
 							  //  **...*	
	}

	if (DEBUG) printf("\n");
	++i,--j;
	for( ; j>start_point ; j-- ){                     // and left direction
		m[j][i] = value++ ;                       // the matrix is filled like (first column)
                if (DEBUG)				  //  **...*
		   printf("(%d,%d):%2d ",j,i,m[j][i]);    //  .-..-*
                                                          //  *.....
                                                          //  *-..-.
 							  //  **...*	
	}
    }
}


void print_mat(int m[MAX_SIZE][MAX_SIZE] ,int size)
{
	int i,j;	//counters for loops
	printf("Size of the matrix: %d\n",size); //print the size of the matrix
	
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
	   		printf(" %3d ",m[i][j]); // print the value of the matrix i,j
		}
		printf("\n"); // after a row of the matrix it has the new line
	}
}
