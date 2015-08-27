#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 0
#define OP(a,b) ((a)>(b)) ?((a)*(a)*(a)-2*(a)*(b)) :((b)*(b)*(b)-2*(a)*(b)) 
#define PRINT(a,b,c)  printf("%d @ %d equals to %d \n", (a) , (b) , (c))


int
main(int argc , char** argv )
{
	int k;
        int flag=1;// the flag is representing whether the console arguments fits on our correct sequence 
	
	if(DEBUG)   // Lets see what s the console arguments
	{
		printf("argc : %d ;\n",argc);
		for( k=0 ; k<argc ; k++)
		{
			 printf("argv[%2d] : %s \n",k,argv[k]);
		}
	}
	
        if(argc>=3) //And if it s bigger than 3 ( ./test  x @ y)
	{
                if((argc % 2) == 1) flag=0;
		else
		{
			for( k=2 ; k<argc ; k=k+2)
			{
	        		if(strcmp((argv[k]),"@"))
				{
					flag=0;
					if(DEBUG) printf(" %d : %s \n",k,argv[k]);
				}
			}
		}

		if(flag==1)
		{
			int z=atoi(argv[1]); //argv is a char pointer so should convert to integer
			int x,y;
			for( k=1 ; (k+2)<=argc ; k=k+2)
			{                              // k==1                  k==n
				x=z;                  //x(1) =argv[1]           x(n) = z(n-2)
                                y=atoi(argv[k+2]);    //y(1) =argv[3]           y(n) = argv[n+2]
				z= OP(x,y);	      //z(1) =x(1)@y(1)         z(n) = x(n) @ y(n)
	
				if(DEBUG) PRINT(x,y,z);
	      		}			
		
			if(!DEBUG)printf("equals to %d \n",z);		
		}

		
		else
		{
			printf("wrong arguments\n");
			exit(1);		
		}
	}

	else
	{
		printf("the number of arguments is smaller than two ..\n");
		exit(1);	
	}
	return 0;
}
