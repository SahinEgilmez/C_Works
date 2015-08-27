/*This header file has functions of operators to process complex number*/

typedef struct { double real,imag;
		} complex_t;

extern int scan_complex(complex_t *c);
extern void print_complex(complex_t c);
extern complex_t add_complex(complex_t c1, complex_t c2);
extern complex_t subtract_complex(complex_t c1, complex_t c2);
extern complex_t multiply_complex(complex_t c1, complex_t c2);
extern complex_t divide_complex(complex_t c1,complex_t c2);
extern complex_t abs_complex(complex_t c);
