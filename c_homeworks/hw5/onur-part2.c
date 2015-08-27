#include<stdio.h>

typedef enum {TRUE= 1,FALSE= 0} BOOL;

int find_maximum(const int a[], int n);
int second_max_array(const int array[], int n);
int sum_all_array (const int array[], int n);
int count_array(int array[], int n, int value);
BOOL search_array (int array[], int n, int value);

int main(){

	
	int smax,b,c,d,value,e,f;
	int array[]={6,8,3,3,12,8,3,8,2};
	int n=9;
	
	b=find_maximum(array,n);
	printf("Maksimum array is %d\n",b);

	smax=second_max_array(array,n);
	printf("Maksimum second array is %d\n",smax);
	
	c=sum_all_array(array,n);
	printf("Sum of all array is %d\n",c);
	
	printf("Plese enter value");
	scanf("%d",&value);

	d=count_array(array,n,value);
	printf("%d\n",d);	
	
	printf("give me a value\n");
	scanf("%d",&f);
	search_array(array,n,f);
	
	
	
	

	return 0;
}

int find_maximum(const int array[], int n) {
	
	int c,x=0;	
	for(c=0; c<n; c++){
		if(array[c] > x){
		x=array[c];
		}
	
	}
 	return x;
  
  
}

int second_max_array(const int array[], int n){
	
	int c,a,temp=0,x=0;
	a=find_maximum(array,n);
	for(c=0; c<n; c++){
		temp=x;
		if(array[c] > x){
		x=array[c];
			if(x==a){
				x=temp;
			}
		}
	}
	
	return temp;
}

int sum_all_array (const int array[], int n){
	
	int i, sum=0;

	for(i=0; i<n; i++){
		sum += array[i];
	}

		return sum;
}

int count_array(int array[], int n, int value){

	int i, count = 0;
	for(i=0; i<n; i++){
		if (array[i] == value)
		{
			++count;
		}
	}
	return (count);
}

BOOL search_array(int array[], int n, int value){

	int c;
	for(c=0; c<n; c++){
		if (value == array[c]){
	printf("%d is at %d",value,c);
	return TRUE;
		}
		
	}
	
	return FALSE;

}





