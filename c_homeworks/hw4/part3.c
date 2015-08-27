/*************************************************************
 *                                                           *
 * HW04 Q3                                                   *
 * Student Name: Şahin EĞİLMEZ                               *
 * Student ID  : 131044059                                   *
 * Date        : 15.03.2015                                  *
 * Points      : 45                                          *
 *                                                           *
 *************************************************************/
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define CHARACTERFILE "Files/Q3/CharacterList.txt"
#define SAMPLEFILE "Files/Q3/Sample.txt"
#define ENCODEDFILE "Files/Q3/XUniversityEncoded.txt"
#define PLAINTEXTFILE "Files/Q3/XUniversityMessage.txt"

/*************************************************************
 * Swaps values of two integers                              *
 *************************************************************/
void 
swap_int(int *a, int *b);

/*************************************************************
 * Swaps values of two characters                            *
 *************************************************************/
void 
swap_char(char *a, char *b);

/*************************************************************
 * Sorts characters according to counts. At the end          *
 * make sure that *c1 keeps most frequent used letter, *c3   *
 * keeps least frequent used letter and *c2 keeps remained   *
 * letter                                                    *
 *************************************************************/
void
sort(char *a, int a_num, char *b, int b_num, char *c, int c_num);

/*************************************************************
 * Check whether character is big ASCII letter or not        *
 * return TRUE or FALSE                                      *
 *************************************************************/
int 
is_letter(char c);

/*************************************************************
 * Read characters from character list file and if character *
 * is letter assign characters to c1, c2 and c3.             *
 * If file has not three letters assign NULL to input char   *
 * by order. For ex. file has two letters assign proper      *
 * letters to c1 and c2 and assign NULL to c3. If file has   *
 * four letters assign c1, c2 and c3 first three letters.    *
 * Return number of letters in character list file.          *
 * Do not forget to count only proper letters with your      *
 * is_letter function. Return number of letters not chars    *
 *************************************************************/
int 
read_character_list(FILE* f_in_ptr, char *c1, char *c2, char *c3);

/*************************************************************
 * Read letters from Sample file and compute frequency of    *
 * letters. Then sort it inside this function. Call sort     *
 * function. At the end make sure that *c1 keeps most        *
 * frequent used letter, *c3 keeps least frequent used       *
 * letter and *c2 keeps remained letter                      *
 *************************************************************/
void 
count_letters(FILE *f_in_ptr, char *c1, char *c2, char *c3);

/*************************************************************
 * Read from XUniversityEncoded file to decode message and   *
 * write decoded (plain text) message to XUniversityMessage  *
 * file. Make sure c1 keeps most frequent used letter,  c3   *
 * keeps least frequent used letter and  c2 keeps remained   *
 * letter while calling function. According to frequency     *
 * you know their codes. c1: 0, c2: 10, c3: 110.             *
 *************************************************************/
void 
decode(FILE *f_in_ptr, FILE *f_out_ptr, char c1, char c2, char c3);

/*************************************************************
 * Learns XUniversity's encoding system from given files ,   *
 * decodes their encoded messages and writes as plain text to*
 * a file                                                    *
 *************************************************************/
int 
main()
{
	FILE *f_character_list_ptr, *f_sample_file_ptr, *f_encoded_ptr,
		*f_plain_text_ptr;
	int character_number;
	char c1, c2, c3;

	f_character_list_ptr=fopen(CHARACTERFILE, "r");

	/* exit program and print error if character list file could not be opened to read */
	if(f_character_list_ptr==NULL) {
		printf("Error!File could not opened to read.");
		return 1;
	}

	/* call read_character_list function and get return value *
	 * if number of letter read is not equal to three exit    *
	 * program                                                */
	character_number=read_character_list(f_character_list_ptr, &c1, &c2, &c3);
	if(character_number!=3) {
		printf("Character number is not equal to 3.");
		return 1;
	}

	/* close character list file */
	fclose(f_character_list_ptr);
	
	f_sample_file_ptr=fopen(SAMPLEFILE, "r");
	
	/* exit program and print error if sample file could not be opened to read */
	if(f_sample_file_ptr==NULL) {
		printf("Error!File could not opened to read.");
		return 1;
	}

	/* Call count_letters function and swap letters inside function *
	 * according to number of counts                                */	
	count_letters(f_sample_file_ptr, &c1, &c2, &c3);
	
	/* close sample file */
	fclose(f_sample_file_ptr);

	/*open encoded and plain text file*/	
	f_encoded_ptr=fopen(ENCODEDFILE, "r");
	f_plain_text_ptr=fopen(PLAINTEXTFILE, "w");

	/* exit program and print error if encoded file could not be opened to read */
	if(f_encoded_ptr==NULL) {
		printf("Error!File could not opened to read.");
		return 1;
	}

	/* exit program and print error if plain text file could not be opened to write */
	if(f_plain_text_ptr==NULL) {
		printf("Error!File could not opened to write.");
		return 1;
	}

	/* Call decode function */	
	decode(f_encoded_ptr,f_plain_text_ptr,c1,c2,c3);

	/* close encoded and plain text file */
	fclose(f_encoded_ptr);
	fclose(f_plain_text_ptr);

	return 0;
}

/*************************************************************
 * Swaps values of two integers                              *
 *************************************************************/
void 
swap_int(int *a, int *b)
{
	int x;
	x = *a;
	*a = *b;
	*b = x;
	
}

/*************************************************************
 * Swaps values of two characters                            *
 *************************************************************/
void 
swap_char(char *a, char *b)
{
	char y;
	y = *a;
	*a = *b;
	*b = y;
}	

/*************************************************************
 * Sorts characters according to counts. At the end          *
 * make sure that *c1 keeps most frequent used letter, *c3   *
 * keeps least frequent used letter and *c2 keeps remained   *
 * letter                                                    *
 *************************************************************/
void
sort(char *a, int a_num, char *b, int b_num, char *c, int c_num)
{	
	
		if(a_num<b_num) {
			swap_int(&a_num, &b_num);
			swap_char(b,a);
		
		}
		
		if(c_num>a_num) {
			swap_int(&c_num, &a_num);
			swap_char(a,c);
			
		}
		if(c_num>b_num) {
			swap_int(&c_num, &b_num);
			swap_char(b,c);
			
		}

}

/*************************************************************
 * Check whether character is big ASCII letter or not        *
 * return TRUE or FALSE                                      *
 *************************************************************/
int 
is_letter(char c)
{
	/* Hint: Look for difference with 'A' to understand 
	 * character is a big letter or not. Use ASCII codes to
	 * determine if it is a big letter or not          
	 */

	if(c>=65 && c<=90) 
		return TRUE; 
	else 
		return FALSE;
}

/*************************************************************
 * Read characters from character list file and if character *
 * is letter assign characters to c1, c2 and c3.             *
 * If file has not three letters assign NULL to input char   *
 * by order. For ex. file has two letters assign proper      *
 * letters to c1 and c2 and assign NULL to c3. If file has   *
 * four letters assign c1, c2 and c3 first three letters.    *
 * Return number of letters in character list file.          *
 * Do not forget to count only proper letters with your      *
 * is_letter function. Return number of letters not chars    *
 *************************************************************/
int 
read_character_list(FILE* f_in_ptr, char *c1, char *c2, char *c3)
{	
	int counter = 0;
	
	int i, a, b;
	char ch, char1, char2, char3;
	
	for(i=0; i!=EOF; i=a){
		a=fscanf(f_in_ptr, "%c",&ch);		
		b=is_letter(ch);
			if(counter==2 && b==1) {
			*c3 = ch;
			counter++;
			}
			if(counter==1 && b==1) {
			*c2 = ch;
			counter++;
			}
			if(counter==0 && b==1) {
			*c1 = ch;
			counter++;
			}
		
	}
	
	return counter;
}

/*************************************************************
 * Read letters from Sample file and compute frequency of    *
 * letters. Then sort it inside this function. Call sort     *
 * function. At the end make sure that *c1 keeps most        *
 * frequent used letter, *c3 keeps least frequent used       *
 * letter and *c2 keeps remained letter                      *
 *************************************************************/
void 
count_letters(FILE *f_in_ptr, char *c1, char *c2, char *c3)
{
	int num_c1=0, num_c2=0, num_c3=0;
	int i, a;
	char character, x,y,z;
	/* Hint: Read character by character and increment counter
	 * of proper counter of read character.
	 */
	a=fscanf(f_in_ptr, "%c", &character);
	while(a!=EOF) {
		
		if(character==*c1) {
			num_c1++;
			
		}
		else if(character==*c2) {
			num_c2++;
			
		}
		else if(character==*c3) {
			num_c3++;
			
		}
		a=fscanf(f_in_ptr, "%c", &character);
	}
	
	sort(c1,num_c1,c2,num_c2,c3,num_c3);
	
}

/*************************************************************
 * Read from XUniversityEncoded file to decode message and   *
 * write decoded (plain text) message to XUniversityMessage  *
 * file. Make sure c1 keeps most frequent used letter,  c3   *
 * keeps least frequent used letter and  c2 keeps remained   *
 * letter while calling function. According to frequency     *
 * you know their codes. c1: 0, c2: 10, c3: 110.             *
 *************************************************************/
void 
decode(FILE *f_in_ptr, FILE *f_out_ptr, char c1, char c2, char c3)
{
	int number_of_ones, j, a, number;
	/* Hint: While reading from encoded text file keep reading 
	 *		 character by character. Use ASCII difference from 0
	 *		 to determine number is 0 or 1. If we try reading it
	 *		 as integer, it overflows. Overflow is bad if you are 
	 *		 not hacker and do not want to crash system deliberately.
	 */
	while(number!=EOF) {
		for(j=1; j!=0; j=a) {
			number=fscanf(f_in_ptr, "%1d", &a);
			number_of_ones=number_of_ones+a;
		}
		if(number!=EOF) {
		if(number_of_ones==0) {
			fprintf(f_out_ptr,"%c", c1);
		}
		if(number_of_ones==1) {
			fprintf(f_out_ptr,"%c", c2);
		}
		if(number_of_ones==2) {
			fprintf(f_out_ptr,"%c", c3);
		}
		}
		number_of_ones=0;
	}
}
