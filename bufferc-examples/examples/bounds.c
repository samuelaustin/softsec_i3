
#include <stdlib.h>
#include "buffer.h"
#include "bounds.h"
	
	
	void within_bounds_read() {
	buffer * test = alloc_buf((5));
	
	for(int i = 0; (i <  test->bufsize); i++) {
			buffer * p = alloc_buf((1));
			assign_char(p, 0, get_char_at_index(test, i));
			printf((p)->ptr);
		}
	
	
	}
	
	void out_of_bounds_read() {
	int s = 5;
	buffer * test = alloc_buf((s));
	
	for(int i = 0; (i <  (2 * s)); i++) {
			buffer * p = alloc_buf((1));
			assign_char(p, 0, get_char_at_index(test, i));
			printf((p)->ptr);
		}
	
	
	}
	
	void within_bounds_assign() {
	int s = 5;
	buffer * test = alloc_buf((s));
	assign_char(test, (s - 1), 't');
	
	}
	
	void out_of_bounds_assign() {
	int s = 5;
	buffer * test = alloc_buf((s));
	assign_char(test, (2 * s), 't');
	
	}
	
