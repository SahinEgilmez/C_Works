/*    This program is written by Meltem Cetiner						*/
/*	It s a simple sample solution of the q4						*/
/*											*/
/* Basically the function "fill" is a recursive function				*/
/* Each step , the starting point will be changed like (0,0)(1,1)(2,2)...until (the center point of the matrix)*/
/* the fill function calls the function "func" 						*/
/* The function "func" starts from each starting points and fill four sides		*/
/*    second for assignment top side ---increase cell column				*/
/*    third for assignment right side --increase cell row 				*/
/*    four for assignment down side  ---decrease cell column        			*/
/*    and fifth loop for assignment left side--decrease cell row			*/
/****************************************************************************************/
#include <stdio.h>

#define MAX_SIZE 20
#define DEBUG 0

/*recursively fill all cells of the matrix at each step ,It fills the four edges starting from the point with the value*/
void fill(int m[][ MAX_SIZE],int size,int point , int* value);

/*print matrix*/
void print_mat(int m[][ MAX_SIZE] , int size);


int main()
{

	int m[ MAX_SIZE][ MAX_SIZE],m2[ MAX_SIZE][ MAX_SIZE];   // creat matrix
	int i=0,j=0;            				// counter for initializing
	
	for( i = 0 ; i < MAX_SIZE ; i++)   			// initiliaze the matrix
		for( j = 0 ; j < MAX_SIZE ; j++)
	   	{	
			m[ i ][ j ] = 0;
			m2[ i][ j ] = 0;
		}
	int val=0,val2=0;
	
	//test for size 9
	fill(m,9,0,&val);  
	print_mat(m,9);
        //test for size 10
	fill(m2,10,0,&val2); 
	print_mat(m2,10);
       
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
void fill(int m[ MAX_SIZE][ MAX_SIZE],int size,int point,int* value)
{

	int i=point,j=point;

	for(;i<(size-point);i++){                         //fill it starting from the first point in left direction
		m[j][i]=(*value)++;                       //the matrix is filled like   (first row)
                if (DEBUG)				  //  ***..*
		   printf("(%d,%d):%2d ",j,i,m[j][i]);    //  --...-
                                                          //  .....-
 							  //  --...-
			
	}

	if (DEBUG) printf("\n");
        --i;    // at the end it increases the integer i one more time so we should decrease it only one
        ++j;	// and we will continue with next step so we should increase the integer j one times
	for(;j<(size-point);j++){			  //to continue to fill in down direction
		m[j][i]=(*value)++;   			  //the matrix is filled like  (last column)
                if (DEBUG)				  //  ***..*
		   printf("(%d,%d):%2d ",j,i,m[j][i]);    //  --..-*
                                                          //  ....-.
 							  //  ....-.
 							  //  --..-*		
	}
          
	if (DEBUG) printf("\n");
	--j;  // at the end it increases the integer j one more time so we should decrease it only one
        --i;  // and we will continue with next step so we should decrease the integer i one times
	for(;i>=point;i--){		                  //and then in right direction
		m[j][i]=(*value)++;                       // the matrix is filled like (last row)
                if (DEBUG)				  //  **...*
		   printf("(%d,%d):%2d ",j,i,m[j][i]);    //  --..-*
                                                          //  ....-.
                                                          //  --..-.
 							  //  **...*	
	}

	if (DEBUG) printf("\n");
		
	for(++i,--j;j>point;j--){                     // and left direction
		m[j][i]=(*value)++;                       // the matrix is filled like (first column)
                if (DEBUG)				  //  **...*
		   printf("(%d,%d):%2d ",j,i,m[j][i]);    //  .-..-*
                                                          //  ......
                                                          //  *-..-.
 							  //  **...*	
	}
  
	if( (point+1) <= (int)(size/2) )  //it calls the next startin point
		fill(m, size ,point+1, value);	// repeats until the startng point equals to the center point 
//and if the size of the matrix is even, it will choose               


	
}



/*print matrix*/
void print_mat(int m[MAX_SIZE][MAX_SIZE] ,int size)
{
	int i,j;	//counters for loops
	printf("Size of the matrix: %d\n",size); //print the size of the matrix
	
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
	   		printf(" %3d ",m[i][j]); // print the value of the matrix i,j
		}
		printf("\n"); // after a row of the matrix it prints a new line
	}
}

