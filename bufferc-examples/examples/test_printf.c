
#include <stdlib.h>
#include "buffer.h"
#include "test_printf.h"
	
	
	void f(buffer * h) {
	safe_format_string((alloc_buf_string(4-2, "%s"), h))->ptr;
	safe_format_string((alloc_buf_string(6-2, "%s%s"), h, h))->ptr;
	safe_format_string((alloc_buf_string(4-2, "%s"), h, 5))->ptr;
	safe_format_string((alloc_buf_string(4-2, "%s"), h, 5))->ptr;
	
	}
	
	void main(int i) {
	
	}
	
