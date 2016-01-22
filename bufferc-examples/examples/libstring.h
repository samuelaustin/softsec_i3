
#include <stdlib.h>
#include "buffer.h" 
	
	int chr_is_space(char c);
	
	buffer * str_copy(buffer * dst, buffer * src);
	
	buffer * str_clone(buffer * src);
	
	buffer * str_concat(buffer * s1, buffer * s2);
	
	buffer * str_trim(buffer * s);
	
	int str_equal(buffer * first, buffer * second);
	
	int str_compare(buffer * s1, buffer * s2);
	
	void str_error(buffer * msg);
	
