
#include <stdlib.h>
#include "buffer.h"
#include "memoryleak.h"
	
	
	void leak() {
	buffer * b;
	
	for(int i = 0; (i <  1000000); i++) {
			b = alloc_buf((100));
		}
	
	Return("final"())
	}
	
