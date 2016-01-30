
#include <stdlib.h>
#include "buffer.h"
#include "libstring.h"
	
	
	int chr_is_space(char c) {
	return ((c == '\32') || (c == '\t'));
	
	}
	
	buffer * str_copy(buffer * dst, buffer * src) {
	
	if((dst->bufsize >= src->bufsize)) {
	  int s = src->bufsize;
	  
	  for(int i = 0; (i <  s); i++) {
	  		assign_char(dst, i, get_char_at_index(src, i));
	  	}
	  
	  return dst; 
	} else {
		buffer * errorMsg = alloc_buf((28));
		errorMsg = alloc_buf_string(30-2, "Destination buffer too small");
		str_error(errorMsg);
		return alloc_buf((0));
	}
	
	}
	
	buffer * str_clone(buffer * src) {
	int s = src->bufsize;
	buffer * dst = alloc_buf((s));
	
	for(int i = 0; (i <  s); i++) {
			assign_char(dst, i, get_char_at_index(src, i));
		}
	
	return dst;
	
	}
	
	buffer * str_concat(buffer * s1, buffer * s2) {
	int size1 = s1->bufsize;
	int size2 = s2->bufsize;
	int resSize = (size1 + size2);
	buffer * res = alloc_buf((resSize));
	
	for(int i = 0; (i <  size1); i++) {
			assign_char(res, i, get_char_at_index(s1, i));
		}
	
	
	for(int i = 0; (i <  size2); i++) {
			assign_char(res, (i + size1), get_char_at_index(s2, i));
		}
	
	return res;
	
	}
	
	buffer * str_trim(buffer * s) {
	int start = 0;
	int end = (s->bufsize - 1);
	
	while(((start <  s->bufsize) && (get_char_at_index(s, start) == ' '))) {
		start = (start + 1);
	}
	
	
	while(((end >= 0) && (get_char_at_index(s, end) == ' '))) {
		end = (end - 1);
	}
	
	buffer * trimmed = alloc_buf((((end - start) + 1)));
	
	for(int i = 0; (i <  trimmed->bufsize); i++) {
			assign_char(trimmed, i, get_char_at_index(s, (i + start)));
		}
	
	return trimmed;
	
	}
	
	int str_equal(buffer * first, buffer * second) {
	
	if((first->bufsize == second->bufsize)) {
	  
	  for(int i = 0; (i <  first->bufsize); i++) {
	  		
	  		if((get_char_at_index(first, i) != get_char_at_index(second, i))) {
	  		  return 0;
	  		}
	  		
	  	}
	  
	  return 1;
	}
	
	return 0;
	
	}
	
	int str_compare(buffer * s1, buffer * s2) {
	int s = s1->bufsize;
	
	if((s2->bufsize <  s)) {
	  s = s2->bufsize;
	}
	
	
	for(int i = 0; (i <  s); i++) {
			
			if((get_char_at_index(s1, i) <  get_char_at_index(s2, i))) {
			  return -1;
			}
			
			
			if((get_char_at_index(s1, i) >  get_char_at_index(s2, i))) {
			  return 1;
			}
			
		}
	
	return 0;
	
	}
	
	void str_error(buffer * msg) {
	printf((msg)->ptr);
	exit;
	
	}
	
