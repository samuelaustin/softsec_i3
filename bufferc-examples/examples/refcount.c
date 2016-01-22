
#include <stdlib.h>
#include "buffer.h"
#include "refcount.h"
	
	
	void test1() {
	buffer * a = alloc_buf((4));
	buffer * b = "56789";
	buffer * c;
	assign_char(a, 0, 'a');
	printf((c));
	Return("final"())
	}
	
	void test2() {
	buffer * a = alloc_buf((4));
	buffer * b = "56789";
	deref_buf(a); 
	a = b;
	ref_buf(b);
	printf((a));
	Return("final"())
	}
	
	buffer * test3aux(buffer * b) {
	assign_char(b, 0, '8');
	return b;
	Return("final"())
	}
	
	void test3() {
	buffer * a = alloc_buf((4));
	buffer * b = test3aux(a);
	printf((a));
	Return("final"())
	}
	
	buffer * initAlias() {
	buffer * a = alloc_buf((4));
	buffer * b = a;
	Return("final"())
	}
	
	buffer * test3aAux() {
	buffer * b = alloc_buf((4));
	assign_char(b, 0, '8');
	return b;
	Return("final"())
	}
	
	void test3a() {
	buffer * b = test3aAux();
	printf((b));
	Return("final"())
	}
	
	buffer * test3bAux(buffer * b) {
	b = alloc_buf((8));
	return b;
	Return("final"())
	}
	
	void test3b() {
	buffer * a = alloc_buf((4));
	buffer * b = test3bAux(a);
	printf((a));
	printf((b));
	Return("final"())
	}
	
	void test4aux(buffer * b) {
	assign_char(b, 0, '8');
	Return("final"())
	}
	
	void test4() {
	buffer * a = alloc_buf((4));
	test4aux(a);
	printf((a));
	Return("final"())
	}
	
	void test5aux(buffer * b) {
	assign_char(b, 0, '8');
	Return("final"())
	}
	
	void test5() {
	test4aux(alloc_buf((4)));
	Return("final"())
	}
	
	buffer * test6aux(buffer * b) {
	b = alloc_buf((8));
	assign_char(b, 0, '8');
	return b;
	Return("final"())
	}
	
	void test6() {
	buffer * a = alloc_buf((4));
	buffer * b = test6aux(a);
	deref_buf(a); 
	a = b;
	ref_buf(b);
	printf((a));
	alloc_buf((5));
	Return("final"())
	}
	
	buffer * test7Aux1(buffer * b) {
	assign_char(b, 0, '8');
	return b;
	Return("final"())
	}
	
	buffer * test7Aux2(buffer * b) {
	assign_char(b, 1, '9');
	return b;
	Return("final"())
	}
	
	void test7() {
	buffer * a = alloc_buf((4));
	buffer * b = test7Aux2(test7Aux1(a));
	printf((a));
	Return("final"())
	}
	
	buffer * test8aux(buffer * b) {
	return b;
	Return("final"())
	}
	
	void test8() {
	buffer * a = alloc_buf((4));
	test8aux(a);
	printf((a));
	Return("final"())
	}
	
	buffer * f(buffer * b, int i) {
	buffer * a = alloc_buf((i));
	deref_buf(b); 
	b = a;
	ref_buf(a);
	return b;
	Return("final"())
	}
	
	buffer * g(buffer * b, int i) {
	buffer * a = alloc_buf((i));
	return a;
	Return("final"())
	}
	
	buffer * cnst(buffer * b) {
	return "uvwxyz";
	Return("final"())
	}
	
	buffer * test_cnst() {
	buffer * b = alloc_buf((4));
	buffer * a;
	deref_buf(a); 
	a = cnst(b);
	ref_buf(cnst(b));
	Return("final"())
	}
	
	buffer * cpy(buffer * a) {
	return a;
	Return("final"())
	}
	
	buffer * test_cpy() {
	buffer * b = alloc_buf((4));
	buffer * a;
	deref_buf(a); 
	a = cpy(b);
	ref_buf(cpy(b));
	Return("final"())
	}
	
	buffer * h(buffer * b, int i) {
	int j = 0;
	buffer * c = cpy(b);
	deref_buf(i); 
	i = (i + 1);
	ref_buf((i + 1));
	buffer * a = alloc_buf((i));
	deref_buf(b); 
	b = a;
	ref_buf(a);
	return c;
	Return("final"())
	}
	
	void m() {
	buffer * b;
	b = alloc_buf((5));
	Return("final"())
	}
	
	void main() {
	buffer * d = h("abcd", 4);
	printf((d));
	buffer * e = cnst("ghij");
	printf((e));
	Return("final"())
	}
	
