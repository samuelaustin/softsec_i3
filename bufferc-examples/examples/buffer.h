// buffer.h

// signatures for BufferC safe buffer data type

#ifdef BUFFER

#else

#define BUFFER 1

#include <stdio.h>
#include <string.h>

// buffer data type
typedef struct _buffer buffer;
// prototypes of operations on buffer data type

buffer *alloc_buf(int size);

buffer *alloc_buf(int size, char* str);

buffer *clone(buffer *src);

buffer *copy(buffer *dst, buffer *src);

buffer *concat(buffer *b1, buffer *b2);

int buf_equal(buffer *first, buffer *second);

int buf_comp(buffer *s1, buffer *s2);

void assign_char(buffer *b, int index, char c);

char get_char_at_index(buffer *b, int index);

buffer *safe_format_string(buffer *b, buffer *string);

void print_buf(buffer *buf);

void println_buf(buffer *buf);

void safe_file_read(buffer *b, FILE *f);

void deref_buf(buffer *buf);

void ref_buf(buffer *buf);

int char_is_space(char c);

#endif
