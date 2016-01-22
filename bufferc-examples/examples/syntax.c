
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
	deref_buf(j); 
	j = i++;
	ref_buf(i++);
	Return("final"())
	}
	
	void characters() {
	char c = 'a';
	deref_buf(c); 
	c = '\n';
	ref_buf('\n');
	Field(c, Identifier("a"()));
	Return("final"())
	}
	
	int statements(int i, int j) {
	if((Not(CommaExp((i <  j))) || (j == i))) deref_buf(i); 
	              i = i++;
	              ref_buf(i++); else deref_buf(i); 
	                              i = 0;
	                              ref_buf(0);
	while((i <  j)) i++;
	DoWhile(i++;, (i <  j))
	for(int k = 0; (k <  j); k++) i++;
	For(deref_buf(i); 
	    i = 0;
	    ref_buf(0), (i <  j), i++, i++;)
	return (i + j);
	{ deref_buf(i); 
	  i = (i + 1);
	  ref_buf((i + 1));
	  deref_buf(j); 
	  j = (j - 1);
	  ref_buf((j - 1)); }
	exit CommaExp(2);
	Return("final"())
	}
	
	int exp(int x, int n) {
	
	if((n == 0)) {
	  return 1; 
	} else {
		return (x * exp(x, (n - 1)));
	}
	Return("final"())
	}
	
	void allBufferOperations() {
	buffer * a;
	buffer * b = alloc_buf((5));
	b = "abcdefgh";
	get_char_at_index(b, 4);
	assign_char(b, 4, 'a');
	printf((b));
	printf(("b: %s\n", b));
	b->bufsize;
	FILE * f = fopen(("a", "r"));
	safe_file_read((b, f));
	deref_buf(a); 
	a = b;
	ref_buf(b);
	int q = 1;
	int w = 2;
	deref_buf(q); 
	q = w;
	ref_buf(w);
	Return("final"())
	}
	
	void abstract_syntax(int i, int j) {
	
	if(((j == 1) || (j == (2 + i)))) {
	  printf(("ok"));
	}
	
	Return("final"())
	}
	
