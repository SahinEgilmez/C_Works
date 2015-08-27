/************************************************/
/*	     	the_time library		*/
/************************************************/
#ifndef _THE_TIME_H_
#define _THE_TIME_H_


typedef struct 
{	
	int hour;
	int minute;
}the_time;

/****			Display time	        		*****/
extern void
print_time(the_time time1);

/****		Set hour 			*****/
extern void
set_hour(the_time* time1,int new_hour);

/****		Get hour 			*****/
extern int
get_hour(the_time time1);

/****		Set minute 			*****/
extern void
set_min(the_time* time1,int new_min);

/****		Get minute 			*****/
extern int
get_min(the_time time1);


/****			Evaluate diff btw times 		*****/
extern int 
abs_dif_time( const the_time* time1,  const the_time* time2);


/****			Addition minutes to the time	 	*****/
extern the_time 
add_minute(the_time* time1,int add_min);


#endif
