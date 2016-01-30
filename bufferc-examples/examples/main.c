#include <stdlib.h>
#include <stdio.h>
#include "buffer.h"
#include "memoryleak.c"
#include "bounds.h"
#include "test_printf.h"
#include "test_types.h"

int main( int argc, const char* argv[] )
{
    within_bounds_read();
    within_bounds_assign();
    printf("This should work.");
    out_of_bounds_read();
    out_of_bounds_assign();
    printf("This should not work.");
	leak();
	printf("Should not give a buffer overflow.");
	buffer *b = alloc_buf(10);
	f(b);
    printf(inc(5) == 6);
    printf(integer_expressions());
    printf(boolean_expressions());
    printf(buffer_expressions());
    printf(print_expressions());
	return 0;
}
