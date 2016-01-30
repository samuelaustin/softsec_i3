
#include <stdlib.h>
#include "buffer.h"
#include "refcount.h"
	
	
	void test1() {
	buffer * a = alloc_buf((4));
	buffer * b = alloc_buf_string(7-2, "56789");
	buffer * c;
	assign_char(a, 0, 'a');
	printf((c)->ptr);
	
	}
	
	void test2() {
	buffer * a = alloc_buf((4));
	buffer * b = alloc_buf_string(7-2, "56789");
	deref_buf(a); 
	a = b;
	ref_buf(b);
	printf((a)->ptr);
	
	}
	
	buffer * test3aux(buffer * b) {
	assign_char(b, 0, '8');
	return b;
	
	}
	
	void test3() {
	buffer * a = alloc_buf((4));
	buffer * b = test3aux(a);
	printf((a)->ptr);
	
	}
	
	buffer * initAlias() {
	buffer * a = alloc_buf((4));
	buffer * b = a;
	return b;
	
	}
	
	buffer * test3aAux() {
	buffer * b = alloc_buf((4));
	assign_char(b, 0, '8');
	return b;
	
	}
	
	void test3a() {
	buffer * b = test3aAux();
	printf((b)->ptr);
	
	}
	
	buffer * test3bAux(buffer * b) {
	deref_buf(b); 
	b = alloc_buf((8));
	return b;
	
	}
	
	void test3b() {
	buffer * a = alloc_buf((4));
	buffer * b = test3bAux(a);
	printf((a)->ptr);
	printf((b)->ptr);
	
	}
	
	void test4aux(buffer * b) {
	assign_char(b, 0, '8');
	
	}
	
	void test4() {
	buffer * a = alloc_buf((4));
	test4aux(a);
	printf((a)->ptr);
	
	}
	
	void test5aux(buffer * b) {
	assign_char(b, 0, '8');
	
	}
	
	void test5() {
	test4aux(alloc_buf((4)));
	
	}
	
	buffer * test6aux(buffer * b) {
	deref_buf(b); 
	b = alloc_buf((8));
	assign_char(b, 0, '8');
	return b;
	
	}
	
	void test6() {
	buffer * a = alloc_buf((4));
	buffer * b = test6aux(a);
	deref_buf(a); 
	a = b;
	ref_buf(b);
	printf((a)->ptr);
	alloc_buf((5));
	
	}
	
	buffer * test7Aux1(buffer * b) {
	assign_char(b, 0, '8');
	return b;
	
	}
	
	buffer * test7Aux2(buffer * b) {
	assign_char(b, 1, '9');
	return b;
	
	}
	
	void test7() {
	buffer * a = alloc_buf((4));
	buffer * b = test7Aux2(test7Aux1(a));
	printf((a)->ptr);
	
	}
	
	buffer * test8aux(buffer * b) {
	return b;
	
	}
	
	void test8() {
	buffer * a = alloc_buf((4));
	test8aux(a);
	printf((a)->ptr);
	
	}
	
	buffer * f(buffer * b, int i) {
	buffer * a = alloc_buf((i));
	deref_buf(b); 
	b = a;
	ref_buf(a);
	return b;
	
	}
	
	buffer * g(buffer * b, int i) {
	buffer * a = alloc_buf((i));
	return a;
	
	}
	
	buffer * cnst(buffer * b) {
	return alloc_buf_string(8-2, "uvwxyz");
	
	}
	
	buffer * test_cnst() {
	buffer * b = alloc_buf((4));
	buffer * a;
	deref_buf(a); 
	a = cnst(b);
	ref_buf(a);
	return a;
	
	}
	
	buffer * cpy(buffer * a) {
	return a;
	
	}
	
	buffer * test_cpy() {
	buffer * b = alloc_buf((4));
	buffer * a;
	deref_buf(a); 
	a = cpy(b);
	ref_buf(a);
	return a;
	
	}
	
	buffer * h(buffer * b, int i) {
	int j = 0;
	buffer * c = cpy(b);
	i = (i + 1);
	buffer * a = alloc_buf((i));
	deref_buf(b); 
	b = a;
	ref_buf(a);
	return c;
	
	}
	
	void m() {
	buffer * b;
	deref_buf(b); 
	b = alloc_buf((5));
	
	}
	
	void main() {
	buffer * d = h(alloc_buf_string(6-2, "abcd"), 4);
	printf((d)->ptr);
	buffer * e = cnst(alloc_buf_string(6-2, "ghij"));
	printf((e)->ptr);
	
	}
	
