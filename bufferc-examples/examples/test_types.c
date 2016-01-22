
#include <stdlib.h>
#include "buffer.h"
#include "test_types.h"
	
	
	int inc(int x) {
	return (x + 1);
	Return("final"())
	}
	
	int integer_expressions() {
	int x;
	int y = 2;
	(x + y);
	(x - y);
	(x - 3);
	(x * 2);
	(((x * y) + 4) - 3);
	x++;
	int z = 1;
	deref_buf(z); 
	z = ((z && 0) || 1);
	ref_buf(((z && 0) || 1));
	Return("final"())
	}
	
	int boolean_expressions() {
	int x;
	int z = 1;
	deref_buf(z); 
	z = ((z && 0) || 1);
	ref_buf(((z && 0) || 1));
	deref_buf(z); 
	z = (1 <  x);
	ref_buf((1 <  x));
	Return("final"())
	}
	
	int buffer_expressions() {
	buffer * b = alloc_buf((3));
	int x = b->bufsize;
	char c = b[1];
	int i = b[3];
	char d = x[3];
	b[2] = 'c';
	b[2] = 4;
	b = "adlkjfa";
	deref_buf(b); 
	b = 4;
	ref_buf(4);
	deref_buf(x); 
	x = 5;
	ref_buf(5);
	deref_buf(x); 
	x = b;
	ref_buf(b);
	Return("final"())
	}
	
	int print_expressions() {
	printf(("a"));
	Return("final"())
	}
	
