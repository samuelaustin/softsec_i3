
#include <stdlib.h>
#include "buffer.h"
#include "syntax.h"
	
	
	void expressions() {
	int i;
	int j = (i + 1);
	(i <  j);
	(j == (i + 1));
	((j == 1) || (j == (2 + i)));
	(Not(CommaExp(1)) || 0);
	j = i++;
	
	}
	
	void characters() {
	char c = 'a';
	c = '\n';
	Field(c, Identifier("a"()));
	
	}
	
	int statements(int i, int j) {
	if((Not(CommaExp((i <  j))) || (j == i))) i = i++; else i = 0;
	while((i <  j)) i++;
	DoWhile(i++;, (i <  j))
	for(int k = 0; (k <  j); k++) i++;
	For(i = 0, (i <  j), i++, i++;)
	return (i + j);
	{ i = (i + 1);
	  j = (j - 1); }
	exit CommaExp(2);
	
	}
	
	int exp(int x, int n) {
	
	if((n == 0)) {
	  return 1; 
	} else {
		return (x * exp(x, (n - 1)));
	}
	
	}
	
	void allBufferOperations() {
	buffer * a;
	buffer * b = alloc_buf((5));
	b = alloc_buf_string(10-2, "abcdefgh");
	get_char_at_index(b, 4);
	assign_char(b, 4, 'a');
	printf((b)->ptr);
	safe_format_string((alloc_buf_string(9-2, "b: %s\n"), b))->ptr;
	b->bufsize;
	FILE * f = fopen((alloc_buf_string(3-2, "a"), alloc_buf_string(3-2, "r")));
	safe_file_read((b, f));
	deref_buf(a); 
	a = b;
	ref_buf(b);
	int q = 1;
	int w = 2;
	q = w;
	
	}
	
	void abstract_syntax(int i, int j) {
	
	if(((j == 1) || (j == (2 + i)))) {
	  printf((alloc_buf_string(4-2, "ok"))->ptr);
	}
	
	
	}
	
