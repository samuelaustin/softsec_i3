
#include <stdlib.h>
#include "buffer.h"
#include "buffer.c"
#include "memoryleak.h"


	void leak() {
	buffer * b;
	int i;
	for(i = 0; (i <  1000000); i++) {
			deref_buf(b);
			b = alloc_buf((100));
		}

	printf("success");

	}

