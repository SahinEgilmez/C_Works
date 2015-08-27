#include <stdio.h>
#define SIZE 15

int find_indice(int arr[], int size, int target, int *ind_1, int *ind_2)
{
	int i, j, temp;
	*ind_1=-1;
	*ind_2=-1;
	for(i=0; i<size; ++i)
	{
		temp=arr[i];
		for(j=0; j<size; ++j)
		{
			if(i!=j && (temp+arr[j])==target)
			{
				*ind_1=i;
				*ind_2=j;
				return 1;
			}
		}
	}
	return 0;
}



void main()
{
	int arr[SIZE]={0,1,3,4,5,6,7,8,9,15,-5,0,9,10,23};
	int target;
	int a, b;
	scanf("%d", &target);
	if(find_indice(arr, SIZE, target, &a, &b))
		printf("array[%d] => %d, array[%d] => %d\n", a, arr[a], b, arr[b]);
	else
		printf("Not found!\n");
}