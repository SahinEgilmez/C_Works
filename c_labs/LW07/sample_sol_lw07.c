
/*##########################################################*/
/*Sample Solution LW7                                       */
/*________________________                                  */
/*Author: Meltem Çetiner  on March 28, 2015                   */
/*                                                          */
/*##########################################################*/

#include <stdio.h>   /* defines fopen,fclose,fscanf,fprinf, and   EOF*/

#define SIZE 9
#define MAX_SIZE 100
#define DEBUG 0
typedef enum { false, true } bool;

/* prototypes*/

void print_puzzle( char m[][SIZE],int n);
void fill_puzzle_matrix(char m[][SIZE],int* n);/*int  fill_puzzle_matrix( char m[][SIZE]) is ok too*/
bool is_same_word( char m[][SIZE],int n, char word[],int x,int y,char d);
void mark_puzzle(char m[][SIZE],int n,int x,int y,char d,int lenght);
int len_str( char* word);
void is_found( char m[][SIZE],int n, char word[],int* params);
 
/*driver code*/
void main( )
{  
   char puzzle[MAX_SIZE][SIZE];
     
   printf("\n*********************** part1  & part2 **********\n");    
   int lines=0;
   fill_puzzle_matrix(puzzle,&lines);
   printf("Printing the puzzle ...\n");
   print_puzzle(puzzle,lines);
   printf("\n************************** part3 ********************\n");    
   bool b ;
   b= is_same_word(puzzle,lines,"LOVE",2,1,'a');
   if(b)
   {
	printf("there is LOVE starting on puzzle (2,1) across.. \n");
    }
    else
        printf("LOVE is not found..\n");
    

    printf("\n************************** part4 ********************\n");    
    if(b)
    {
	mark_puzzle(puzzle,lines,2,1,'a',4);
	print_puzzle(puzzle,lines);
    }

    printf("\n************************** part5 ********************\n");    
    char choose='y';
    while(choose == 'y'){
    
    	char wordd[SIZE];
    	int xPoint, yPoint;
    	char dir,space;
        printf("Enter the word:");
        scanf(" %s",wordd);
        printf("Enter the starting point of the word ,and the direction [across:a, down: d]on puzzle matrix:");
    	scanf(" %d %d %c",&xPoint,&yPoint,&dir);
    	
        b= is_same_word(puzzle,lines,wordd,xPoint,yPoint,dir);
	if(b)
	{
                printf("\nThe word is found and replace with '*'character.\n");
		mark_puzzle(puzzle,lines,xPoint,yPoint,dir,len_str(wordd));
	} 
        printf("The word is not found in puzzle.");
        print_puzzle(puzzle,lines);
        printf("\nDo you want to continue ? [yes(y) or no(n)] : ");
	scanf(" %c",&choose) ; 
         
    }

    printf("\n************************** part6_BONUS **************\n");    
    
    char word[SIZE];
    printf("Enter the word:");
    scanf("%s",word);
    int* par;
    is_found(puzzle,lines,word,par);
}
 
/*İmplementation of functions*/

/*
pre:  a coefficient "coef"  and degree of the equation "deg", and one character "x"
post: print the term */

void print_puzzle( char m[][SIZE],int n)
{
	int count_x,count_y;
	printf("\n---------Puzzle------ :\n");
	for(count_x=0;count_x<n; count_x++)
	{
		for(count_y=0;count_y<SIZE; count_y++)
		{
			printf("%c ", m[count_x][count_y]);
		}
		printf("\n");
	}
	printf("\n");
}


/*The function that reads the matrix elements from the file called “puzzle.txt”.
Open and close the file in this function.*/
void fill_puzzle_matrix( char m[][SIZE],int* n)
{
        FILE* fp = fopen("puzzle.txt","r"); // read mode
 
 	if( fp == NULL )
   	{
   	   printf("Error while opening the file.\n");
     	}

        printf("Filling the puzzle ...\n");
        int column=0,row=0;
        char cell;	
        if(DEBUG)  printf("[%d %d]=%c ",column,row,'s');
		
        while( fscanf(fp,"%c",&cell)!=EOF )
	{
   		if(cell=='\n')
	        {
		       if(fscanf(fp,"%c",&cell)!=EOF)
			{
				row++;
                        	column=0;
				m[row][column++]=cell;
              		}	
		       		
		       else 
				break;
                 }
                 else
		 {
			m[row][column++]=cell;
                  }
	}
	fclose(fp);
        *n=++row;
}
 

/*returns the number of char the word has*/
int len_str( char* word)
{	
	int counter=0;
	while(word[counter]!='\0')
	{
		counter++;
	}
	return counter;
}


/*The function that checks whether the word is in the puzzle or not. The function
takes puzzle matrix m, the size of the matrix n, the string word, the location on x axis,
location on y axis and the direction d ('a' represents across and 'd' represents down) as
input parameters. The function should return a value of type bool.*/
bool is_same_word( char m[][SIZE],int n, char word[],int x,int y,char d)
{
    int count;
    int length= len_str(word);
   	
    
    bool flag=false;		
    
    if(d=='d')
    { 
         if((x+length)>SIZE)
        	return flag;
        		 
         for(count=0;count<length;count++)
         {
            if( m[x+count][y]!=word[count])
                return flag;
		 
         }
         if(count==length)
           { 
                flag=true; 
		return flag;
            }
    }
    else if(d=='a')
    {  
	 if((y+length)>SIZE)
		 return flag;
         for(count=0;count<length;count++)
         {   
	     	if( m[x][count+y]!= word[count])
		    return flag;
   	}
        if(count==length)
         { 
                flag=true;
		return flag;
         }
    }
    else
        {  printf("You enter wrong direction"); return flag;}
    
   
}


/*The function that replaces the characters of the word with the character '*'. The
function takes puzzle matrix m, the size of the matrix n, the location on x axis,
location on y axis, the direction d ('a' represents across and 'd' represents down) and
number of characters lenght as input parameters. It replaces lenght characters
starting from location (x,y) on the direction d with the character ‘*’.*/
void mark_puzzle(char m[][SIZE],int n ,int x,int y,char d,int length)
{
    int count;
    
    if(d=='d')
    {  
         for(count=x;count<(x+length);count++)
               m[count][y]='*';
        
    }
    else if(d=='a')
    {  
         for(count=y;count<(y+length);count++)
               m[x][count]='*';
         
    } 
    
}


/*ThE function that checks whether the word is in the puzzle or not.The function
takes puzzle matrix m, the size of the matrix n, the string word as input parameters.
The difference of this part from the Part3 is that the function should founds the
location point and direction ,and returns them as an integer array : x, y, d (0 represents
across and 1 represents down) respectively.*/
void is_found( char m[][SIZE],int n, char word[],int* params)
{
  int len=len_str(word);
  bool b=false,flag=false;
  int x,y;
  for(x=0;x<n && b==false;x++)
  {  
	for(y=0;y<=(SIZE-len) && b==false;y++)
        {
		if(DEBUG) printf("\nThe check point %d %d .. ",x,y);        
		b=is_same_word(m,n,word,x,y,'a');
	        if(b)
	      	{ 
			if(DEBUG) printf("\nThe check point(1) %d %d .. ",x,y);        
		 	*params=x;
	       		*(params+1)=y;
	       		*(params+2)=0;
	       	}
	}
  }
  if(b==false )
  {
	for(x=0;x<=(n-len) && b==false;x++)
  	{  
		for(y=0;y<=(SIZE) && b==false;y++)
        	{
			if(DEBUG) printf("\nThe check point %d %d .. ",x,y);        
			b=is_same_word(m,n,word,x,y,'d');
		        if(b)
		      	{ 
				if(DEBUG) printf("\nThe check point(2) %d %d .. ",x,y);        
			 	*params=x;
		       		*(params+1)=y;
		       		*(params+2)=1;
				
		       	}
		}
  	}
  }
  if(b==false)  printf("....!!!!!!!!!!!!!!!!The word is not found.........");
   else 
    {      if(*(params+2)==1)
                printf("\n--------The word is found on %d %d starting point and down direction.. \n",*params,*(params+1));
            else
		printf("\n--------The word is found on %d %d starting point and across direction..\n ",*params,*(params+1));
           
     }   
   
}
