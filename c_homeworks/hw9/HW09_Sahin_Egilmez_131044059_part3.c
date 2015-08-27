/*##########################################################################  */
/*                                                                            */
/* HW09_Sahin_Egilmez_131044059_part3.c                                       */
/* 									      */
/* Created on 25/04/2015 by Sahin Egilmez                                     */
/*                                                                            */
/*Description                                                                 */
/*                                                                            */
/*C program for storing and search of microbiologiest's data                  */
/*Inputs:                                                                     */
/*      - txt file for data                                                   */
/*Outputs:                                                                    */
/*	- print to screen result of searching                                 */
/*########################################################################### */
/*----------------------------------------------------------------------------*/
/*                           Includes                                         */
/*----------------------------------------------------------------------------*/
#include<stdio.h>

typedef struct{ int a,b,c;}triplet_t;
typedef struct{ triplet_t triplet;
		int mpn,lower,upper;}Row;
/*########################################################################### ­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­*/
/*                         Function Prototypes                                */
/*­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­########################################################################### */
void Into_Binary(FILE *text_input, FILE *binary_output);
int Load_Mpn_table(FILE *binary_input_file,Row mpn_table[], int maxsize);
void search( Row mpn_table[], int actual_size, const triplet_t triplet_to_search);
int read_mpn(FILE *binary_input_file,Row mpn_table[],Row data,int maxsize);

int main()
{	
	int size=0,actual_size=0,i=0;
	char temp;
	Row mpn[50];
	triplet_t triplet_to_search;
	FILE *text_input, *binary_output;
	text_input=fopen("input3.txt","r");
	binary_output=fopen("output3.bin","wb");
	/*call the function and scan txt file and write to binary file*/
	Into_Binary(text_input,binary_output);
	fclose(text_input);
	fclose(binary_output);
	binary_output=fopen("output3.bin","rb");
	/*this loop for scan binary file until end of file*/
	do{
		/*call the load mnp table function and fill the mnp[] array*/
		size=Load_Mpn_table(binary_output,&mpn[i],10);
		actual_size+=size;/*find the size of array*/
		i=i+10;
	}while((size!=0));
	fclose(binary_output);
	/*take the triplet value from console*/
	printf("Please enter triplet values as NUM-NUM-NUM format.\n");
	scanf("%d%c%d%c%d",&triplet_to_search.a, &temp, &triplet_to_search.b,&temp,
&triplet_to_search.c);
	/*call search function and searching mnp array according to parameters*/
	search(mpn,actual_size,triplet_to_search);
	
	return 0;

}
/*scan txt file and write to binary file*/
void Into_Binary(FILE *text_input, FILE *binary_output)
{	Row data;
	char temp;
	/*this loop for scan txt file until end of file and write to .bin file*/
	while(fscanf(text_input," %d%c%d%c%d%d%d%d",&data.triplet.a,&temp, 
&data.triplet.b, &temp, &data.triplet.c, &data.mpn, &data.lower, &data.upper)!=EOF) {
		fwrite(&data,sizeof(data),1,binary_output);
	}
}
/*this function for scanning each row(maximum maxsize) and fill mpn table array*/
int Load_Mpn_table(FILE *binary_input_file,Row mpn_table[], int maxsize)
{	
	int a,i,count=0;
	Row data;
	for(i=0;(i<maxsize) && (fread(&data,sizeof(data),1,binary_input_file)!=0);i++) {
		mpn_table[i]=data;
		/*tested function and print to mpn table[i]*/
		printf("%d-%d-%d-%d-%d-%d\n",mpn_table[i].triplet.a,mpn_table[i].triplet.b, 
mpn_table[i].triplet.c, data.mpn, mpn_table[i].lower, mpn_table[i].upper);
		count++;
	}
	return count;/*return count value*/
}
/*this function for searching rows and print to found row*/
void search( Row mpn_table[], int actual_size, const triplet_t triplet_to_search)
{
	int i;
	for(i=0;i<actual_size;i++) {
		if(mpn_table[i].triplet.a == triplet_to_search.a && 
		   mpn_table[i].triplet.b == triplet_to_search.b &&
		   mpn_table[i].triplet.c == triplet_to_search.c) {
			printf("MPN=%d; 95%% of samples contain between %d and %d bacteria/ml.\n", 
			mpn_table[i].mpn, mpn_table[i].lower, mpn_table[i].upper);
		}
	}
} 

/*########################################################################### */
/*                    End of  HW09_Sahin_Egilmez_131044059_part3.c            */
/*########################################################################### */

