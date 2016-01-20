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
	buf->ptr = (char *)malloc(buf->bufsize + 1);
	buf->ptr[buf->bufsize] = "\0";
	buf->refCount = buf->refCount + 1;
	return buf;
}

/* STRING OPERATIONS */
buffer *clone(buffer *src) {
	buffer *dst = alloc_buf(src->bufsize);
	dst = copy(dst, src);
	dst->ptr[dst->bufsize] = "\0";
	return dst;
}

buffer *copy(buffer *dst, buffer *src){
	if(dst->bufsize >= src->bufsize){
		int size = src->bufsize+1;
		for(int i = 0; i < s; i++){
			dst->ptr[i] = src->ptr[i];
		}
		return dst;
	}
	else{
		return NULL; // TODO implement error message.
	}
}

buffer *concat(buffer* b1, buffer* b2){
	int size1 = b1->bufsize;
	int size2 = b2->bufsize;
	buffer *res = alloc_buf(size1 + size2);
	for(int i = 0; i < size1; i++){
		res->ptr[i] = b1->ptr[i];
	}
	for(int i = 0; i < size2; i++){
		res->ptr[1+size1] = b2->ptr[i];
	}
	return res;
}

/* PRINTING */
void print_buf(buffer *buf){
	printf("%s", buf->ptr);
}

void println_buf(buffer *buf){
	printf("%s\n", buf->ptr);
}
/* FILE OPERATIONS */

/* REFERENCE COUNTING */
void deref_buf(buffer *buf){
	buf->refCount = buf->refCount - 1;
	if(refCount = 0){
		free(buf);
	}
}

/* OTHER OPERATIONS */

