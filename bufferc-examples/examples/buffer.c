#include <stdlib.h>
#include <stdio.h>
#include "buffer.h"

// This is the run-time library implementing the primitive operations for
// the BufferC buffer data type.

/* STRUCT */
typedef struct _buffer {
	char* ptr;
	int bufsize;
	int refCount;
} buffer;

// Allocation, copying and dereferencing.
buffer *alloc_buf(int size) {
	buffer *buf = (buffer *)malloc(sizeof(buffer));
	buf->bufsize = size;
	buf->ptr = (char *)malloc(buf->bufsize + 1);
	buf->ptr[buf->bufsize] = '\0';
	buf->refCount = 1;
	return buf;
}

// Allocation, copying and dereferencing.
buffer *alloc_buf(int size, char* str) {
	buffer *buf = (buffer *)malloc(sizeof(buffer));
	buf->bufsize = size;
	buf->ptr = (char *)malloc(buf->bufsize + 1);
	int i;
	for(i = 0; i < size; i++)
	{
		buf->ptr[i] = str[i];
		if(str[i] == '\0')
		{
			break;
		}
	}
	buf->ptr[buf->bufsize] = '\0';
	buf->refCount = 1;
	return buf;
}

/* STRING OPERATIONS */
buffer *clone(buffer *src) {
	buffer *dst = alloc_buf(src->bufsize);
	dst = copy(dst, src);
	dst->ptr[dst->bufsize] = '\0';
	return dst;
}

buffer *copy(buffer *dst, buffer *src){
	if(dst->bufsize >= src->bufsize){
		int size = src->bufsize+1;
		int i;
		for(i = 0; i < size; i++){
			dst->ptr[i] = src->ptr[i];
		}
		return dst;
	}
	else{
		printf("Destination buffer not large enough to contain the message.");
		exit(0);
	}
}

buffer *concat(buffer* b1, buffer* b2){
	int size1 = b1->bufsize;
	int size2 = b2->bufsize;
	int i;
	buffer *res = alloc_buf(size1 + size2);
	for(i = 0; i < size1; i++){
		res->ptr[i] = b1->ptr[i];
	}
	for(i = 0; i < size2; i++){
		res->ptr[i+size1] = b2->ptr[i];
	}
	return res;
}

int buf_equal(buffer *first, buffer *second){
	if(first->bufsize == second->bufsize){
        int i;
		for(i = 0; i < first->bufsize; i++){
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
			s = s2->bufsize;
		}
		int i;
		for(i = 0; i < s; i++){
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
		b->ptr[index] = c;
	}
	else{
		printf("Out of bounds assignment error.");
		exit(0);
	}
}

char get_char_at_index(buffer *b, int index){
	if(index < b->bufsize){
		return b->ptr[index];
	}
	else{
		printf("Index was out of the bound of the buffer.");
		exit(0);
	}
}

/* PRINTING + FORMAT STRINGS */
buffer *safe_format_string(buffer *b, buffer *params[]){
	char* format = b->ptr;
	int i;
	int count = 0;
	for(i = 0; i < b->bufsize-1; i++){
		count += (str[i] == '%' && str[i+1] == 's');
	}
	if(count == params){
		sum = b->bufsize;
		int j;
		for(j = 0; j < sizeof(params); j++){
			sum += params[i]->bufsize;
		}
		char *res = (char *)malloc(sum);
		sprintf(res, format, params)
	}
	else{
		printf("Amount of parameters supplied does not match the amount of parameters in the format string.");
		exit(0);
	}
}

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
		printf("Buffer overflow detected.");
		exit(0);
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
	if(buf != NULL){
		buf->refCount = buf->refCount - 1;
		if(buf->refCount <= 0){
			free(buf->ptr);
			free(buf);
		}
	}
}

void ref_buf(buffer *buf){
	if(buf != NULL){
		buf->refCount = buf->refCount + 1;
	}
}

/* OTHER OPERATIONS */
int char_is_space(char c){
	return c == '\32' || c == '\t';
}
