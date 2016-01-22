
#include <stdlib.h>
#include "buffer.h"
#include "vulnerable.h"
	#include "libstring.h"
	
	int bof(buffer * str) {
	buffer * dst = alloc_buf((24));
	str_copy(dst, str);
	return 1;
	Return("final"())
	}
	int main(int argc, char **argv)
