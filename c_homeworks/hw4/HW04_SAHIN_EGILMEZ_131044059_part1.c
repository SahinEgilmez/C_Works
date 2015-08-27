/*************************************************************
 *                                                           *
 * HW04 Q1                                                   *
 * Student Name: Şahin EĞİLMEZ                               *
 * Student ID  : 131044059                                   *
 * Date        : 15.03.2015                                  *
 * Points      : 27                                          *
 *                                                           *
 *************************************************************/
#include <stdio.h>

#define PLAINTEXTFILE "Files/Q1/PlainMessagesToSent.txt"
#define ENCODEDFILE "Files/Q1/EncodedMessages.txt"
#define CRYPTEDFILE "Files/Q1/CryptedMessages.txt"

/*************************************************************
 * Gets FILE* to write file and character to encode          *
 * uses encoding table to convert plain text to              *
 * encoded message                                           *
 *************************************************************/
void 
encode_and_write_to_file(FILE *f_out_ptr, char character);

/*************************************************************
 * Gets FILE* f_in_ptr to read from plain text file and      *
 * FILE* f_out_ptr to write message to encoded file          *
 * return number of characters read from plain text          *
 *************************************************************/
int 
encode_message(FILE *f_in_ptr, FILE *f_out_ptr);

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to encrypted file        *
 * return encoded character number                           *
 *************************************************************/

int 
crypt_message(FILE *f_in_ptr, FILE *f_out_ptr);
/*************************************************************
 * Reads plane text, creates encoded and crypted text files  *
 *************************************************************/
int 
main(int argc, char* argv[])
{
	FILE *f_plane_ptr, *f_encoded_ptr, *f_crypted_ptr;
	f_plane_ptr=fopen(PLAINTEXTFILE, "r");
	f_encoded_ptr=fopen(ENCODEDFILE, "w");
	
	/* exit program and print error if plain text file could not be opened to read */
	if(f_plane_ptr==NULL) {
		printf("Error!File could not opened to read.");
		return 1;
	}
	/* exit program and print error if encoded text file could not be opened to write */
	if(f_encoded_ptr==NULL) {
		printf("Error!File could not opened to write.");
		return 1;
	}
	
	/*call encode message function*/
	encode_message(f_plane_ptr, f_encoded_ptr);

	/* close plain and encoded files */
	fclose(f_plane_ptr);
	fclose(f_encoded_ptr);

	f_crypted_ptr=fopen(CRYPTEDFILE, "w");
	f_encoded_ptr=fopen(ENCODEDFILE, "r");

	/* exit program and print error if crypted text file could not be opened to write */
	if(f_crypted_ptr==NULL) {
		printf("Error!File could not opened to write.");
		return 1;
	}
	/* exit program and print error if encoded text file could not be opened to read */
	if(f_encoded_ptr==NULL) {
		printf("Error!File could not opened to read.");
		return 1;
	}

	/*call crypted message function*/
	crypt_message(f_encoded_ptr, f_crypted_ptr);
	
	
	fclose(f_encoded_ptr);
	fclose(f_crypted_ptr);
	/* close crypted and encoded files */

	return 0;
}

/*************************************************************
 * Gets FILE* to write file and character to encode          *
 * uses encoding table to convert plain text to              *
 * encoded message                                           *
 *************************************************************/
void 
encode_and_write_to_file(FILE *f_out_ptr, char character)
{
	
	/* Hint: Use switch case while encoding character 
	 *		 Keep number of 1s and use it in a loop to
	 *		 write to file encoded value. You are going to
	 *		 call fprintf in the loop just number of 1s times
	 *		 Do not forget adding 0 at the end of value
	 */
	
	
		
		switch(character) {
	
		case 'E':
			fprintf(f_out_ptr, "0");
			break;
		case 'I':
			fprintf(f_out_ptr, "10");
			break;
		case ' ':
			fprintf(f_out_ptr, "110");
			break;
		case 'T':
			fprintf(f_out_ptr, "1110");
			break;
		case 'C':
			fprintf(f_out_ptr, "11110");
			break;
		case 'N':
			fprintf(f_out_ptr, "111110");
			break;
		case 'A':
			fprintf(f_out_ptr, "1111110");
			break;
		case 'G':
			fprintf(f_out_ptr, "11111110");
			break;
		case 'B':
			fprintf(f_out_ptr, "111111110");
			break;
		case 'Z':
			fprintf(f_out_ptr, "1111111110");
			break;
		case 'H':
			fprintf(f_out_ptr, "11111111110");
			break;
		case 'L':
			fprintf(f_out_ptr, "111111111110");
			break;
		case 'U':
			fprintf(f_out_ptr, "1111111111110");
			break;
		case 'V':
			fprintf(f_out_ptr, "11111111111110");
			break;
		case 'R':
			fprintf(f_out_ptr, "111111111111110");
			break;
		case 'S':
			fprintf(f_out_ptr, "1111111111111110");
			break;
		case 'Y':
			fprintf(f_out_ptr, "11111111111111110");
			break;
		}
	
	
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from plain text file and      *
 * FILE* f_out_ptr to write message to encoded file          *
 * return number of characters read from plain text          *
 *************************************************************/
int 
encode_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	/* Hint: Keep reading from plain text until end of file
	 *		 while reading per character call encode_and_write_to_file
	 *		 function.
	 */
	int counter = 0;
	char a, character;
	
	
	while(a!=EOF) {
		a=fscanf(f_in_ptr, "%c", &character);
		encode_and_write_to_file(f_out_ptr, character);
		counter++;
	}
		

	return counter;
}

/*************************************************************
 * Gets FILE* f_in_ptr to read from encoded text file and    *
 * FILE* f_out_ptr to write message to encrypted file        *
 * return number of characters read from encoded text file   *
 *************************************************************/


int 
crypt_message(FILE *f_in_ptr, FILE *f_out_ptr)
{
	/* Hint: Keep reading from encoded text until end of file
	 *		 while reading per character check if it is equal 
	 *		 to 1 or 0 and according to character write file '*'
	 *		 '_'
	 *		 Do not forget adding '-' character to proper places
	 *       Check sample encrypted messages and read objective 3
	 *
	 */
	int counter = 0;
	int m=5, n=0, j=0;
	int encode;
	j=fscanf(f_in_ptr, "%1d", &encode);
	while(j!=EOF) {
		
		if(encode==1) {
			fprintf(f_out_ptr, "*");
		}
		else if(encode==0) {
			fprintf(f_out_ptr, "_");
		}
		n++;
		n=n%m;
		if(n==0) {
			fprintf(f_out_ptr, "-");
			m--;
			n=0;
			if(m==0) { m=5; }
		}
		j=fscanf(f_in_ptr, "%1d", &encode);
	}
	
	
	
	return counter;
}




