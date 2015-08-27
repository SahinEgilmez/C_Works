/**		Driver of Part2		**/
#include <stdio.h>
#include "the_time.h"

int 
main(void)
{
	the_time first_time,second_time;
	
	int a,b;
	a=12;
	b=36;

	set(&first_time,a,a);
	print_time(first_time);
	
	set(&second_time,a,b);
	print_time(second_time);

	add_minute(&second_time,183);
	print_time(second_time);

	printf("absoluate different of the times is : %d mins \n",abs_dif_time(&first_time,&second_time));

	return 0;
}

