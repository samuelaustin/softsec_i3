
#include <stdlib.h>
#include "buffer.h"
#include "memoryleak.h"
	
	
	void leak() {
	buffer * b;
	
	for(int i = 0; (i <  1000000); i++) {
			deref_buf(b); 
			b = alloc_buf((100));
		}
	
	printf((alloc_buf_string(9-2, "success"))->ptr);
	
	}
	
