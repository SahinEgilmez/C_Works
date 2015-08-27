/*This file implamantiaton file of complex.h library*/

#include<stdio.h>
#include<math.h>
#include"complex.h"

/*scan the complex numbers*/
int scan_complex(complex_t *c) 
{
	int status;
	
	status = scanf("%lf%lf", &c->real,&c->imag);
	if(status==2)
		status=1;
	else if(status!=EOF)
		status=0;
	
	return status;
}
/*print to screnn complex numbers*/
void print_complex(complex_t c)
{
	double a,b;
	char sign;
	
	a=c.real;
	b=c.imag;

	printf("(");

	if(fabs(a)<.005 && fabs(b) <.005) 
		printf("%.2f",0.0);
	else if(fabs(b)<.005)
		printf("%.2f",a);
	else if(fabs(a)<.005)
		printf("%.2fi",b);
	else {
		if(b<0)
			sign='-';
		else 
			sign='+';
		printf("%.2f %c %.2fi",a,sign,fabs(b));
	}
	
	printf(")");
}
/*returns sum of comlex numbers*/
complex_t add_complex(complex_t c1, complex_t c2)
{
	complex_t csum;
	
	csum.real= c1.real+ c2.real;
	csum.imag= c1.imag+ c2.imag;
	
	return csum;
}
/*returns difference of complex numbers*/
complex_t subtract_complex(complex_t c1, complex_t c2)
{
	complex_t cdiff;
	cdiff.real=c1.real - c2.real;
	cdiff.imag=c1.imag - c2.imag;

	return cdiff;
}
/*returns multiply of complex numbers*/
complex_t multiply_complex(complex_t c1, complex_t c2)
{
	complex_t cmulti;
	cmulti.real=(c1.real*c2.real)-(c1.imag*c2.imag);
	cmulti.imag=(c1.real*c2.imag)+(c1.imag*c2.real);

	return cmulti;
}
/*returns divide of complex numbers*/
complex_t divide_complex(complex_t c1,complex_t c2)
{
	complex_t cdiv;
	
	cdiv.real=((c1.real*c2.real)+(c1.imag*c2.imag))/((c2.real*c2.real)+(c2.imag*c2.imag));
	cdiv.imag=((c1.imag*c2.real)-(c1.real*c2.imag))/((c2.real*c2.real)+(c2.imag*c2.imag));

	return cdiv;
}
/*returns absoulate value of comlex number*/
complex_t abs_complex(complex_t c)
{
	complex_t cabs;
	
	cabs.real= sqrt(c.real*c.real + c.imag*c.imag);
	cabs.imag=0;

	return cabs;
}























