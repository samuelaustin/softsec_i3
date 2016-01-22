#include <stdlib.h>
#include <stdio.h>
#include "buffer.h"
#include "memoryleak.c"

int main( int argc, const char* argv[] )
{
	leak();
}
