/********************************************************************/
/*	     the implementation  of the_time library		    */
/********************************************************************/

#include <stdio.h>
#include "the_time.h"


#define oneHourInMinute 60
#define oneDayInHour 24


/****			Display time	        		*****/
void
print_time(the_time time1)
{
	
	printf(" time is  %2d:%2d \n",time1.hour,time1.minute);
}

void
set(the_time* time1,int new_hour,int new_min)
{
	if(new_hour<=oneDayInHour)
		time1->hour=new_hour;
        else
	{
		printf("the hour couldnt be bigger than %d ... Enter new hour :",oneDayInHour);
		set(time1,-1,-1);
	}

	if(new_min<=oneHourInMinute)
		time1->minute=new_min;
        else
	{
		printf("the minute couldnt be bigger than %d ... Enter new minute :",oneHourInMinute);
		set( time1,-1,-1);
	}
}



/****		Get hour 			*****/
int
get_hour(the_time time1){ return time1.hour;};


/****		Get minute 			*****/
int
get_min(the_time time1){ return time1.minute;};


/****			Evaluate diff btw times 		*****/
int 
abs_dif_time( const the_time* time1, const the_time* time2)
{

    int val_first_time,val_second_time, result=0;
    val_first_time = get_hour(*time1) * oneHourInMinute + get_min(*time1);
    val_second_time = get_hour(*time2) * oneHourInMinute + get_min(*time2);
    result = ( val_first_time > val_second_time  ? ( val_first_time - val_second_time ) : (val_second_time - val_first_time ));
	return result;

}


/****			Addition minutes to the time	 	*****/
the_time 
add_minute(the_time* time1,int add_min)
{

	int val_first_time,new_min,new_hour;
	val_first_time = get_hour(*time1) * oneHourInMinute+ get_min(*time1);
	val_first_time += add_min;
	new_hour = val_first_time / oneHourInMinute;
	new_min = val_first_time % oneHourInMinute;
	set(time1,new_hour,new_min);
	return *time1;
 
}



