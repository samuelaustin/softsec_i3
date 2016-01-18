#include <stdlib.h>
#include <stdio.h>
#include "buffer.h"

// This is the run-time library implementing the primitive operations for
// the BufferC buffer data type.

/* STRUCT */
typedef struct {
	char* ptr;
	int bufsize;
	int refCount = 0;
} buffer;

// Allocation, copying and dereferencing.
buffer *alloc_buf(int size) {
	buffer *buf = (buffer *)malloc(sizeof(buffer));
	buf->bufsize = size;
	buf->ptr = (char *)malloc(buf->bufsize);
	buf->refCount = buf->refCount + 1;
	return buf;
}

buffer *copy(buffer *src) {
	buffer *dst = alloc_buf(src->bufsize);
	strncpy(dst->ptr, src->ptr, dst->bufsize);
	dst->ptr[dst->bufsize-1] = '\0';
	return dst;
}

/* PRINTING */

/* FILE OPERATIONS */

/* REFERENCE COUNTING */
void deref_buf(buffer *buf){
	buf->refCount = buf->refCount - 1;
	if(refCount = 0){
		free(buf);
	}
}


