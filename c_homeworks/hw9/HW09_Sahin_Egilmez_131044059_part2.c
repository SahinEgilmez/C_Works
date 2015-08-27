/*##########################################################################  */
/*                                                                            */
/* HW09_Sahin_Egilmez_131044059_part2.c                                       */
/* 									      */
/* Created on 25/04/2015 by Sahin Egilmez                                     */
/*                                                                            */
/*Description                                                                 */
/*                                                                            */
/*C program for created and include the complex library                       */
/*########################################################################### */
/*----------------------------------------------------------------------------*/
/*                           Includes                                         */
/*----------------------------------------------------------------------------*/
#include<stdio.h>
#include<math.h>
#include"complex.h"

int main()
{
	complex_t com1,com2;
	/*Gets two complex numbers*/
	printf("Enter the real and imaginary parts of a complex number\n");
	printf("seperated bt a space> ");
	scan_complex(&com1);
	printf("Enter a second complex number> ");
	scan_complex(&com2);

	printf("\n");
	/*Forms and display the sum*/
	print_complex(com1);
	printf(" + ");
	print_complex(com2);
	printf(" = ");
	print_complex(add_complex(com1,com2));
	printf("\n\n");
	/*forms and display the difference*/
	print_complex(com1);
	printf(" - ");
	print_complex(com2);
	printf(" = ");
	print_complex(subtract_complex(com1,com2));
	printf("\n\n");
	/*Forms and display the multiply*/
	print_complex(com1);
	printf(" * ");
	print_complex(com2);
	printf(" = ");
	print_complex(multiply_complex(com1,com2));
	printf("\n\n");
	/*Forms and display the divide*/
	print_complex(com1);
	printf(" / ");
	print_complex(com2);
	printf(" = ");
	print_complex(divide_complex(com1,com2));
	printf("\n\n");
	/*Forms and display the absoluete value of the first number*/
	printf("\n\n");
	print_complex(com1);
	printf("| = ");
	print_complex(abs_complex(com1));
	printf("\n");

	return 0;
}
/*########################################################################### */
/*                    End of  HW09_Sahin_Egilmez_131044059_part2.c            */
/*########################################################################### */
	
