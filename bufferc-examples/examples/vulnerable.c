
#include <stdlib.h>
#include "buffer.h"
#include "vulnerable.h"
	#include "libstring.h"
	
	int bof(buffer * str) {
	buffer * dst = alloc_buf((24));
	str_copy(dst, str);
	return 1;
	
	}
	
	int main(buffer * filename) {
	buffer * str = alloc_buf((517));
	FILE * badfile = fopen((filename, alloc_buf_string(3-2, "r")));
	safe_file_read((str, badfile));
	bof(str);
	printf((alloc_buf_string(21-2, "Returned Properly\n"))->ptr);
	exit CommaExp(0);
	
	}
	
