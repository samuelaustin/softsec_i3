
#include <stdlib.h>
#include "buffer.h"
#include "stringtest.h"
	#include "libstring.h"
	
	int main() {
	buffer * b1 = alloc_buf_string(11-2, "123434524");
	buffer * b2;
	str_copy(b2, b1);
	b2 = alloc_buf_string(8-2, "qwerty");
	safe_format_string((alloc_buf_string(16-2, "b1 value: %s\n"), b1))->ptr;
	safe_format_string((alloc_buf_string(20-2, "b2 value: %s\n, b2")))->ptr;
	safe_format_string((alloc_buf_string(13-2, "b1+b2: %s\n"), str_concat(b1, b2)))->ptr;
	
	if(str_equal(b1, b2)) {
	  printf((alloc_buf_string(16-2, "equal(b1,b2)\n"))->ptr); 
	} else {
		printf((alloc_buf_string(20-2, "not equal(b1,b2)\n"))->ptr);
	}
	
	if(str_equal(b1, b1)) {
	  printf((alloc_buf_string(16-2, "equal(b1,b1)\n"))->ptr); 
	} else {
		printf((alloc_buf_string(20-2, "not equal(b1,b1)\n"))->ptr);
	}
	
	if(str_equal(b1, str_concat(b1, b1))) {
	  printf((alloc_buf_string(25-2, "equal(b1, add(b1,b1))\n"))->ptr); 
	} else {
		printf((alloc_buf_string(29-2, "not equal(b1, add(b1,b1))\n"))->ptr);
	}
	buffer * b3 = alloc_buf_string(6-2, "1234");
	
	if(str_equal(b1, b3)) {
	  printf((alloc_buf_string(17-2, "equal(b1, b3)\n"))->ptr); 
	} else {
		printf((alloc_buf_string(21-2, "not equal(b1, b3)\n"))->ptr);
	}
	return 0;
	
	}
	
