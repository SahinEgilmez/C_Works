/*##########################################################################  */
/*                                                                            */
/* HW08_Sahin_Egilmez_131044059_part1.c                                       */
/* 									      */
/* Created on 19/04/2015 by Sahin Egilmez                                     */
/*                                                                            */
/*Description                                                                 */
/*                                                                            */
/*C program for max sum of rectangular table                                  */
/*Inputs:                                                                     */
/*      - txt file for table                                                  */
/*Outputs:                                                                    */
/*	- Print to screen sum and right,left coordinates                      */
/*########################################################################### */
/*----------------------------------------------------------------------------*/
/*                           Includes                                         */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
/*----------------------------------------------------------------------------*/
/*                           Defines                                          */
/*----------------------------------------------------------------------------*/
#define COL_COUNT 8
#define ROW_CAP 10
typedef struct{
	int x;
	int y;
	} Point_t;
typedef struct{
	Point_t left_up;
	Point_t right_down;
	double sum;
	} Rectangle_t;
/*########################################################################### ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­*/
/*                         Function Prototypes                                */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­########################################################################### */
Point_t construct_point(int x, int y);
Rectangle_t construct_rectangle(Point_t left_up, Point_t right_down);
void print_rectangle(const Rectangle_t *rectangle);
void getArray(FILE* inFile, double table[][COL_COUNT], int* nRow);/*Reads the 
table from a file into a 2D array*/
void getSum(double table[][COL_COUNT], Rectangle_t *rectangle);/*Returns the sum 
inside a given rectangular*/
Rectangle_t maxSumConstPoint(double table[][COL_COUNT], int nRow, Point_t 
left_up);/*Finds the rectangular left uppper point of which is specified having
 the max sum inside*/
Rectangle_t maxSumRec(double table[][COL_COUNT], int nRow);/*Finds the maximum 
sum of the rectangular*/

int main() {
	double table[ROW_CAP][COL_COUNT];/*define 2D array*/
	FILE* inFile;/*define file*/
	int nRow;
	double maxSum;
	int lUY, lUX, rDY, rDX;
	Rectangle_t rectangle;
	rectangle.left_up.x=0;
	rectangle.left_up.y=0;
	inFile=fopen("Table1.txt", "r");/*open file*/

	getArray(inFile, table, &nRow);/*fill array*/
	rectangle=maxSumConstPoint(table, nRow,rectangle.left_up);/*call function
	and return rectangle*/
	print_rectangle(&rectangle);/*print rectangle*/
	rectangle=maxSumRec(table, nRow);/*call function and return rectangle*/
	print_rectangle(&rectangle);/*print rectangle*/
	fclose(inFile);/*close file*/
	return 0;
}
Point_t construct_point(int x, int y)/*construct the Point_t type elements*/
{
	Point_t point;
	point.x=x;
	point.y=y;
	return point;
}
Rectangle_t construct_rectangle(Point_t left_up, Point_t right_down)/*construct
the Rectangle_t type elements*/
{
	Rectangle_t cons_rec;
	cons_rec.left_up=left_up;
	cons_rec.right_down=right_down;
	return cons_rec;
}
void print_rectangle(const Rectangle_t *rectangle)/*takes a rectangle pointer and
prints all information about it in a reasonable format.*/
{
	printf("left_up=(y=%d,x=%d) right_down=(y=%d x=%d) sum= %lf \n",rectangle->
	left_up.y, rectangle->left_up.x,rectangle->right_down.y, 
	rectangle->right_down.x, rectangle->sum);
}

/*Reads the table from a file into a 2D array*/
void getArray(FILE* inFile, double table[][COL_COUNT], int* nRow){
	int row=0;
	int col;
	int status=EOF+1;/*Different from EOF*/

	/*one more row will be read but the values will not be recorded into the table
	therefore, it is safe to use a table having just enough capasity to hold the data*/
	while(status!=EOF){
		for(col=0; col<COL_COUNT; col++)
			status=fscanf(inFile, "%lf", &table[row][col]);
		++row;
	}

	*nRow=row-1;/*one more row read*/
}

/*Returns the sum inside a given rectangular*/
void getSum(double table[][COL_COUNT], Rectangle_t *rectangle){
	int row, col;
	double sum=0;

	for(row=rectangle->left_up.y; row<=rectangle->right_down.y; ++row)
		for(col=rectangle->left_up.x; col<=rectangle->right_down.x; ++col)
			sum+=table[row][col];

	rectangle->sum=sum;
}

/*Finds the rectangular left uppper point of which is specified having the max sum inside*/
Rectangle_t maxSumConstPoint(double table[][COL_COUNT], int nRow, Point_t 
left_up){
	int rDX;	/*x coordinate of the right down corner of the rec*/
	int rDY;	/*y coordinate of the right down corner of the rec*/
	int rightDownY,rightDownX;	
	Point_t right_down;
	Rectangle_t rectangle,temp;
	/*initialize the rectangular with the one including only one point*/
	double sum=table[left_up.x][left_up.y];
	rightDownY=left_up.y;
	rightDownX=left_up.x;

	/*Try all feasible rectangulars by changing the right down corner*/
	for(rDY=left_up.y; rDY<nRow; ++rDY){
		for(rDX=left_up.x; rDX<COL_COUNT; ++rDX){
			right_down=construct_point(rDX,rDY);
			rectangle=construct_rectangle(left_up,right_down);
			getSum(table,&rectangle);
			if(rectangle.sum>sum){
				/*a better rectangular is found, perform an update */
				sum=rectangle.sum;
				rightDownY=rDY;
				rightDownX=rDX;
			}
		}
	}
	rectangle.sum=sum;
	rectangle.right_down.y=rightDownY;
	rectangle.right_down.x=rightDownX;
	return rectangle;
}

Rectangle_t maxSumRec(double table[][COL_COUNT], int nRow){
	Rectangle_t temp;
	/*initialize the rectangular with the one including only origin point*/
	double maxSum=table[0][0];
	Point_t point;
	int leftUpY=0, leftUpX=0, rightDownY =0, rightDownX = 0;

	/*For all feasible starting points call maxSumConstPoint*/
	for(point.y=0; point.y<nRow; ++point.y){
		for(point.x=0; point.x<COL_COUNT; ++point.x){
			temp=maxSumConstPoint(table, nRow, point);
			if(temp.sum>maxSum){
				/*a better rectangular found, perform an update*/
				maxSum=temp.sum;
				leftUpY=temp.left_up.y;
				leftUpX=temp.left_up.x;
				rightDownY=temp.right_down.y;
				rightDownX=temp.right_down.x;
			}
		}
	}
	temp.sum=maxSum;
	temp.left_up.y=leftUpY;
	temp.left_up.x=leftUpX;
	temp.right_down.y=rightDownY;
	temp.right_down.x=rightDownX;
	return temp;
}
/*########################################################################### */
/*                    End of  HW08_Sahin_Egilmez_131044059_part1.c            */
/*########################################################################### */

