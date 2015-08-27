#define MAX_COL 50
#define MAX_ROW 200
#define NAMES_FILE_NAME "Names.txt"
#define NAMES_LOC_FILE_NAME "NamesLocations.txt"
#define LOCATIONS_FILE_NAME "Locations.txt"

#include<stdio.h>
#include<string.h>

int read_strings(const char f_name[], char str_arr[][MAX_COL]);
int read_integers(const char f_name[], int arr[]);
void print_strings(char str_arr[][MAX_COL], int size);
void print_integers(const int arr[], int size);
int get_people_in(const char location[], char names[][MAX_COL], int name_c, char locations[][MAX_COL], int loc_c, int names2loc[], char people[][MAX_COL]);
int find_first_occurance(char str[], char ch);
int find_last_occurance(char str[], char ch);
int f(int x, int y);
int get_ptr_arr(char sentences[][MAX_COL], int row_c, char* ptr_arr[]);
void print_ptr_arr(char* ptr_arr[], int row_c);
void modify_ptr_arr(char* ptr_arr[], int row_c, int index, char new_word[]);


int main(){

	char names[MAX_ROW][MAX_COL];
	char locations[MAX_ROW][MAX_COL];
	int names_locs[MAX_ROW];
	char people [MAX_ROW][MAX_COL];
	char* surnames[MAX_ROW];
	int name_count;
	int locations_count;
	int people_count;

	name_count = read_strings(NAMES_FILE_NAME, names);
	print_strings(names, name_count);
	locations_count = read_strings(LOCATIONS_FILE_NAME, locations);
	print_strings(locations, locations_count);
	read_integers(NAMES_LOC_FILE_NAME, names_locs);
	print_integers(names_locs, name_count);

	people_count = get_people_in("Istanbul", names, name_count, locations, locations_count, names_locs, people);
	print_strings(people, people_count);

	printf("first occurance: deneme, e: %d\n", find_first_occurance("deneme", 'e'));
	printf("first occurance: deneme, a: %d\n", find_first_occurance("deneme", 'a'));

	printf("last occurance: deneme, e: %d\n", find_last_occurance("deneme", 'e'));
	printf("last occurance: deneme, a: %d\n", find_last_occurance("deneme", 'a'));

	printf("f(5, 4) = %d.\n", f(5, 4));

	get_ptr_arr(names, name_count, surnames);
	print_strings(names, name_count);
	printf("\n");
	print_ptr_arr(surnames, name_count);
	modify_ptr_arr(surnames, name_count, 2, "Degirmen");
	printf("\nPointer Array Modified \n");
	print_strings(names, name_count);
	printf("\n");
	print_ptr_arr(surnames, name_count);
	return 0;	
}

int read_strings(const char f_name[], char str_arr[][MAX_COL]){
	FILE* file;
	int i = 0;
	int new_line_pos;

	file = fopen(f_name, "r");

	while(fgets(str_arr[i], MAX_ROW, file)){
		new_line_pos = strlen(str_arr[i]) - 1; 
		if(str_arr[i][new_line_pos] == '\n')
			str_arr[i][new_line_pos] = '\0';
		++i;
	}

	fclose(file);
	return i;
}

void print_strings(char str_arr[][MAX_COL], int size){
	if(size == 0)
		return;
	printf("%s\n", str_arr[0]);
	print_strings(&str_arr[1], size -1);
}

int read_integers(const char f_name[], int arr[]){
	FILE* file;
	int i = 0;

	file = fopen(f_name, "r");

	while(fscanf(file, " %d", &arr[i]) != EOF)
		++i;

	fclose(file);
	return i;
}

void print_integers(const int arr[], int size){
	int i;

	for(i=0; i<size; ++i)
		printf("%d ", arr[i]);

	printf("\n");
}

int get_index(const char str[], char str_arr[][MAX_COL], int size){
	int i;

	for(i=0; i<size; ++i)
		if(strcmp(str_arr[i], str) == 0)
			return i;
	return -1;
}

int get_people_in(const char location[], char names[][MAX_COL], int name_c, char locations[][MAX_COL], int loc_c, int names2loc[], char people[][MAX_COL]){
	int i, j=0;
	int loc_index = get_index(location, locations, loc_c);


	for(i=0; i<name_c; ++i){
		if(names2loc[i] == loc_index){
			strcpy(people[j], names[i]);
			j++;
		}
	}

	return j;
}

int find_first_occurance(char str[], char ch){
	int result;

	/*Base Case*/
	if(str[0] == ch)
		return 0;	/*Found an occurance, start the construction of index*/
	if(str[0] == '\0')
		return -1;	/*str does not include ch*/
	
	/*make recursive call*/
	result = find_first_occurance(&str[1], ch);
	if(result == -1)
		return -1;	/*ch not found yet, continue to return -1*/
	
	/*ch was found, increase index*/
	return result + 1;

}

int find_last_occurance(char str[], char ch){
	int result;
	/*Base Case*/
	if(str[0] == '\0')
		return -1; /*end of string is reached, make no more recursive calls*/

	/*make recursive call*/
	result = find_last_occurance(&str[1], ch);

	if(result == -1){
		/*not foun yet*/
		if(str[0] == ch)
			return 0; /*Found the last occurance, start the construction of index*/
		return -1;
	}
	/*the last occurance already found: do not search for other occurances*/
	/*increase the index returned by deeper calls*/
	return result + 1;
}

int f(int x, int y){
	if((x<1) || (y<1))
		return 0;
	return f(x, y-1) + f(x-1, y) + x + y;
}

int get_ptr_arr(char sentences[][MAX_COL], int row_c, char* ptr_arr[]){
	int i;
	int j = 0;

	for(i=0; i<row_c; ++i){
		j = find_first_occurance(sentences[i], ' ');
		ptr_arr[i] = &sentences[i][j+1];
	}

	return row_c;
}

void print_ptr_arr(char* ptr_arr[], int row_c){
	if(row_c == 0)
		return;

	printf("%s\n", ptr_arr[0]);
	print_ptr_arr(&ptr_arr[1], row_c -1);

}

void modify_ptr_arr(char* ptr_arr[], int row_c, int index, char new_word[]){
	strcpy(ptr_arr[index], new_word);
}
