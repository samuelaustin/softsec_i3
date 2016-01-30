
#include <stdlib.h>
#include "buffer.h"
#include "primitives.h"
	
	
	buffer * strcpy(buffer * dst, buffer * src) {
	
	for(int i = 0; ((i <  dst->bufsize) && (i <  src->bufsize)); i++) {
			assign_char(dst, i, get_char_at_index(src, i));
		}
	
	return dst;
	
	}
	
	buffer * main(buffer * name, buffer * filename) {
	buffer * msg = alloc_buf_string(15-2, "hello %s (%s)");
	safe_format_string((msg, name, filename, 1))->ptr;
	buffer * msg_cpy;
	strcpy(msg_cpy, msg);
	assign_char(msg_cpy, 1, 'a');
	FILE * file = fopen((filename, alloc_buf_string(3-2, "r")));
	buffer * content = alloc_buf((1024));
	safe_file_read((content, file));
	printf((alloc_buf_string(8-2, "file: "))->ptr);
	printf((content)->ptr);
	printf((alloc_buf_string(4-2, "\n"))->ptr);
	exit CommaExp(2);
	
	}
	
