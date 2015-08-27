/*************************************************************
 *                                                           *
 * HW04 Q2                                                   *
 * Student Name: Şahin EĞİLMEZ                               *
 * Student ID  : 131044059                                   *
 * Date        : 15.03.2015                                  *
 * Points      : 18                                          *
 *                                                           *
 *************************************************************/
#include <stdio.h>

#define PLAINTEXTFILE "Files/Q2/ReceivedMessage.txt"
#define ENCODEDFILE "Files/Q2/EncodedInput.txt"
#define CRYPTEDINPUT "Files/Q2/CryptedInput.txt"

/*************************************************************
 * Gets FILE* to write file and character to decode          *
 * uses encoding table to convert encoded message to         *
 * plain text message                                        *
 *************************************************************/
void 
decode_and_write_to_file(FILE *f_out_ptr, int number_of_ones);

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to plain text file       *
 * return number of characters read from encoded text        *
 *************************************************************/
int 
decode_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Gets FILE* f_in_ptr to read from encrypted text file and  *
 * FILE* f_out_ptr to write message to encoded file          *
 * return encrypted character number                         *
 *************************************************************/
int 
decrypt_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Reads encrypted text and creates encoded and              *
 * plain text files                                          *
 *************************************************************/
int 
main(int argc, char* argv[])
{
	FILE *f_plane_ptr, *f_encoded_ptr, *f_crypted_ptr;
	f_crypted_ptr=fopen(CRYPTEDINPUT, "r");
	f_encoded_ptr=fopen(ENCODEDFILE, "w");
	
	/* exit program and print error if encrypted text file could not be opened to read */
	if(f_crypted_ptr==NULL) {
		printf("Error!File could not opened to read.");
		return 1;
	}
	/* exit program and print error if encoded text file could not be opened to write */
	if(f_encoded_ptr==NULL) {
		printf("Error!File could not opened to write.");
		return 1;
	}
	
	/*call decrypt_message function*/
	decrypt_message(f_crypted_ptr, f_encoded_ptr);

	/* close encrypted and encoded files */
	fclose(f_encoded_ptr);
	fclose(f_crypted_ptr);
	
	/*open encoded and plain text file*/
	f_encoded_ptr=fopen(ENCODEDFILE, "r");
	f_plane_ptr=fopen(PLAINTEXTFILE, "w");	
	
	/* exit program and print error if plain text file could not be opened to write */
	if(f_plane_ptr==NULL) {
		printf("Error!File could not opened to write.");
		return 1;
	}
	/* exit program and print error if encoded text file could not be opened to read */
	if(f_encoded_ptr==NULL) {
		printf("Error!File could not opened to read.");
		return 1;
	}
	
	/*call decode message function*/
	decode_message(f_encoded_ptr, f_plane_ptr);
	
	/* close encoded and plain files */
	fclose(f_plane_ptr);
	fclose(f_encoded_ptr);
	

	return 0;
}

/*************************************************************
 * Gets FILE* to write file and character to decode          *
 * uses encoding table to convert encoded message to         *
 * plain text message                                        *
 *************************************************************/
void 
decode_and_write_to_file(FILE *f_out_ptr, int number_of_ones)
{

	/* Hint: Use switch case while encoding character 
	 *		 According to number_of_ones write character 
	 *		 to file
	 */
	
	switch(number_of_ones) {
	
		case 0:
			fprintf(f_out_ptr, "E");
			break;
		case 1:
			fprintf(f_out_ptr, "I");
			break;
		case 2:
			fprintf(f_out_ptr, " ");
			break;
		case 3:
			fprintf(f_out_ptr, "T");
			break;
		case 4:
			fprintf(f_out_ptr, "C");
			break;
		case 5:
			fprintf(f_out_ptr, "N");
			break;
		case 6:
			fprintf(f_out_ptr, "A");
			break;
		case 7:
			fprintf(f_out_ptr, "G");
			break;
		case 8:
			fprintf(f_out_ptr, "B");
			break;
		case 9:
			fprintf(f_out_ptr, "Z");
			break;
		case 10:
			fprintf(f_out_ptr, "H");
			break;
		case 11:
			fprintf(f_out_ptr, "L");
			break;
		case 12:
			fprintf(f_out_ptr, "U");
			break;
		case 13:
			fprintf(f_out_ptr, "V");
			break;
		case 14:
			fprintf(f_out_ptr, "R");
			break;
		case 15:
			fprintf(f_out_ptr, "S");
			break;
		case 16:
			fprintf(f_out_ptr, "Y");
			break;
		}
	

	
	
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to plain text file       *
 * return number of characters read from encoded text        *
 *************************************************************/

int 
decode_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	/* Hint: While reading from encoded text file keep reading 
	 *		 character by character. Use ASCII difference from 0
	 *		 to determine number is 0 or 1. If we try reading it
	 *		 as integer, it overflows. Overflow is bad if you are 
	 *		 not hacker and do not want to crash system deliberately.
	 *		 Call decode_and_write_to_file function when you detect 0.
	 *
	 */
	
	int counter = 0;
	int number_of_ones, j, a, number;
	while(number!=EOF) {
		
		for(j=1; j!=0; j=a) {
			number=fscanf(f_in_ptr, "%1d", &a);
			number_of_ones=number_of_ones+a;
		}
		if(number!=EOF) {
		decode_and_write_to_file(f_out_ptr, number_of_ones);}
		number_of_ones=0;
	
		counter++;
	}
		
		

			
	return counter;
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from encrypted text file and  *
 * FILE* f_out_ptr to write message to encoded file          *
 * return encrypted character number                         *
 *************************************************************/
int 
decrypt_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	/* Hint: While reading from encrypted text file check if character 
	 *		 equals to '*' or '_' and write to file 1 or 0
	 *
	 */
	char cyrpted;
	int counter = 0, character;
	
	while(character!=EOF) {
			character=fscanf(f_in_ptr, "%c", &cyrpted);	
		if(cyrpted=='*') {
			fprintf(f_out_ptr, "1");
			}
		else if(cyrpted=='_') {
			fprintf(f_out_ptr, "0");		
	}
	counter++;
	}
	return counter;
}
