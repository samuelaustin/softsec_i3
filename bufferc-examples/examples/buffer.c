#include <stdlib.h>
#include <stdio.h>
#include "buffer.h"

// This is the run-time library implementing the primitive operations for
// the BufferC buffer data type.

/* STRUCT */
typedef struct _buffer {
	char* ptr;
	int bufsize;
	// refCount initialized on 0.
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
		for(int i = 0; i < size; i++){
			dst->ptr[i] = src->ptr[i];
		}
		return dst;
	}
	else{
		error("Destination buffer not large enough to contain the message.");
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
		res->ptr[i+size1] = b2->ptr[i];
	}
	return res;
}

int buf_equal(buffer *first, buffer *second){
	if(first->bufsize == second->bufsize){
		for(int i = 0; i < first->bufsize; i++){
			if(first->ptr[i] != second->ptr[i]){
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

int buf_comp(buffer *s1, buffer *s2){
	if(buf_equal(s1, s2)){
		return 0;
	}
	else{
		int s = s1->bufsize;
		if(s2->bufsize < s){
			s = s2->bufsize
		}
		for(int i = 0; i < s; i++){
			if(s1->ptr[i] < s2->ptr[i]){
				return -1;
			}
			else {
				return 1;
			}
		}
	}
}


/* CHARACTER ASSIGNMENT */
void assign_char(buffer *b, int index, char c){
	if(index < b->bufsize){
		b->ptr[i] = c;
	}
	else{
		error("Out of bounds assignment error.");
	}
}

char get_char_at_index(buffer *b, int index){
	if(index < b->bufsize){
		return b[index];
	}
	else{
		error("Index was out of the bound of the buffer.");
	}
}

/* PRINTING */
void print_buf(buffer *buf){
	printf("%s", buf->ptr);
}

void println_buf(buffer *buf){
	printf("%s\n", buf->ptr);
}

/* FILE OPERATIONS */
void safe_file_read(buffer *b, FILE* f){
	fseek(f, SEEK_SET, 0);
	int amtData = amt_chars_in_file(f);
	if(amtData > b->bufsize){
		error("Buffer overflow detected.");
	}
	else{
		fread(b->ptr, 1, amtData, stdin);
	}
}

int amt_chars_in_file(FILE *f){
	int count = 0;  /* number of characters seen */
	/* character or EOF flag from input */
	int ch;

	if (f == NULL) {
	    printf("File undefined.");
	    exit(8);
	}

	while (1) {
	    ch = fgetc(f);
	    if (ch == EOF)
	        break;
	    ++count;
	}
	fclose(f);
	return count;
}

/* REFERENCE COUNTING */
void deref_buf(buffer *buf){
	if(ref != NULL){
		buf->refCount = buf->refCount - 1;
		if(refCount <= 0){
			free(buf->ptr);
			free(buf);
		}
	}
}

void ref_buf(buffer *buf){
	if(ref != NULL){
		buf->refCount = buf->refCount + 1;
	}
}

/* OTHER OPERATIONS */
int char_is_space(char c){
	return c == '\32' || c == '\t';
}
