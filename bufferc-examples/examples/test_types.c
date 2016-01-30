
#include <stdlib.h>
#include "buffer.h"
#include "test_types.h"
	
	
	int inc(int x) {
	return (x + 1);
	
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
	z = ((z && 0) || 1);
	
	}
	
	int boolean_expressions() {
	int x;
	int z = 1;
	z = ((z && 0) || 1);
	z = (1 <  x);
	
	}
	
	int buffer_expressions() {
	buffer * b = alloc_buf((3));
	int x = b->bufsize;
	char c = get_char_at_index(b, 1);
	int i = get_char_at_index(b, 3);
	char d = get_char_at_index(x, 3);
	assign_char(b, 2, 'c');
	assign_char(b, 2, 4);
	b = alloc_buf_string(9-2, "adlkjfa");
	b = 4;
	x = 5;
	x = b;
	
	}
	
	int print_expressions() {
	printf((alloc_buf_string(3-2, "a"))->ptr);
	
	}
	
