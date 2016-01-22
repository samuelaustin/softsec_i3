
#include <stdlib.h>
#include "buffer.h"
#include "libstring.h"
	
	
	int chr_is_space(char c) {
	return ((c == '\32') || (c == '\t'));
	Return("final"())
	}
	
	buffer * str_copy(buffer * dst, buffer * src) {
	
	if((dst->bufsize >= src->bufsize)) {
	  int s = src->bufsize;
	  
	  for(int i = 0; (i <  s); i++) {
	  		dst[i] = src[i];
	  	}
	  
	  return dst; 
	} else {
		buffer * errorMsg = alloc_buf((28));
		errorMsg = "Destination buffer too small";
		str_error(errorMsg);
		return alloc_buf((0));
	}
	Return("final"())
	}
	
	buffer * str_clone(buffer * src) {
	int s = src->bufsize;
	buffer * dst = alloc_buf((s));
	
	for(int i = 0; (i <  s); i++) {
			dst[i] = src[i];
		}
	
	return dst;
	Return("final"())
	}
	
	buffer * str_concat(buffer * s1, buffer * s2) {
	int size1 = s1->bufsize;
	int size2 = s2->bufsize;
	int resSize = (size1 + size2);
	buffer * res = alloc_buf((resSize));
	
	for(int i = 0; (i <  size1); i++) {
			res[i] = s1[i];
		}
	
	
	for(int i = 0; (i <  size2); i++) {
			res[(i + size1)] = s2[i];
		}
	
	return res;
	Return("final"())
	}
	
	buffer * str_trim(buffer * s) {
	int start = 0;
	int end = (s->bufsize - 1);
	
	while(((start <  s->bufsize) && (s[start] == ' '))) {
		start = (start + 1);
	}
	
	
	while(((end >= 0) && (s[end] == ' '))) {
		end = (end - 1);
	}
	
	buffer * trimmed = alloc_buf((((end - start) + 1)));
	
	for(int i = 0; (i <  trimmed->bufsize); i++) {
			trimmed[i] = s[(i + start)];
		}
	
	return trimmed;
	Return("final"())
	}
	
	int str_equal(buffer * first, buffer * second) {
	
	if((first->bufsize == second->bufsize)) {
	  
	  for(int i = 0; (i <  first->bufsize); i++) {
	  		
	  		if((first[i] != second[i])) {
	  		  return 0;
	  		}
	  		
	  	}
	  
	  return 1;
	}
	
	return 0;
	Return("final"())
	}
	
	int str_compare(buffer * s1, buffer * s2) {
	int s = s1->bufsize;
	
	if((s2->bufsize <  s)) {
	  s = s2->bufsize;
	}
	
	
	for(int i = 0; (i <  s); i++) {
			
			if((s1[i] <  s2[i])) {
			  return -1;
			}
			
			
			if((s1[i] >  s2[i])) {
			  return 1;
			}
			
		}
	
	return 0;
	Return("final"())
	}
	
	void str_error(buffer * msg) {
	printf((msg));
	exit;
	Return("final"())
	}
	
