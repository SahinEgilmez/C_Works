#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
typedef enum {False,True} Bool;

Bool is_sorted(char *arr);

/*Uncapitialize any CAPITAL letter 
	C -> c
	c -> c
	@ -> @
*/
char myToLower(char c);

int main()
{
    Bool ans;
    char arr[]={"aGjklOvz"}; /*Given A String For Testing The Function*/
    ans=is_sorted(arr);
    if(ans==True)
        printf("The String Is Alphabetically Sorted\n");
    else if(ans==False)
        printf("The String Is NOT Alphabetically Sorted\n");
    else
        printf("Something Goes Wrong In Your Function\n");
    return 0;
}

char myToLower(char c)
{
    if((c <= 'Z') && (c >= 'A'))
		return c - 'A' + 'a';
	else
		return c;
}

Bool is_sorted(char *arr)
{
    Bool result;

	/*Base Case 1: check if the end of string is reached*/    
	if(arr[1]=='\0')
	{
        result=True;
	}	

	/*Base Case 2: check if the order is broken in the current location*/
	/*alternatively use tolower/toupper in ctype.h instead of myToLower */
	else if(myToLower(arr[0]) > myToLower(arr[1]))
    {
    	result=False;
    }
	
	/*Recursive Call*/	
	else
    	result=is_sorted(&arr[1]);
    
 
    return result;
}




