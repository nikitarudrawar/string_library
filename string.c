#include<stdio.h>
#include<stdlib.h>

/* 1.strlen:
 */
size_t strlen(char *s) {
	size_t len = 0;
	while(*s != '\0') {
		len++;
		s++;
	}
	return len;
}
/* 2.strcpy:
 * Copy the string src to dest
 * returns a pointer to the start of dest
 */
char *strcpy(char *dest, char *src) {
	char *p;
	p = dest;
	while((*dest = *src)) {
		dest++;
		src++;
	}
	return p;
}
/* 3.strncpy: 
 * Copy at most n bytes  from  string  src  to  dest  
 * returns a pointer to the start of dest.
 */
char *strncpy(char *dest, char *src, size_t n) {
	char *p;
	p = dest;
	while((n>0) && (*dest = *src)) {
		dest++;
		src++;
		n--;
	}
	return p;
}
/* 4.stpcpy:
 * Copy  a  string from src to dest
 * returns a pointer to the end of the resulting string at dest
 */
char *stpcpy(char *dest, char *src) {
	while((*dest = *src)) {
		dest++;
		src++;
	}
	return dest;
}
/* 5.strcat:
 * Append the string src to the string dest  
 * returning  a  pointer dest
 */
char *strcat(char *dest, char *src) {
	char *p;
	p = dest;
	while(*dest != '\0')
		dest++;
	while((*dest = *src)) {
		src++;
		dest++;
	}
	return p;
}
/* 6.strncat:
 * Append  at  most  n characters from the string src to the string
 * returning  a pointer to dest
 */
char *strncat(char *dest, char *src, size_t n) {
	int i = 0;
	char *p;
	p = dest;
	while(*dest != '\0')
		dest++;
	while((i<n) && (*dest = *src)) {
		src++;
		dest++;
		i++;
	}
	return p;
}
/* 7.strcmp:
 * returns 0(same),+ve(s1>s2) and -ve(s1<s2)
 */
int strcmp(char *s1, char *s2) {
	while(*s1 != '\0' && *s2 != '\0'){
		if(*s1 == *s2) {
			s1++; 
			s2++;
		}
		else
			return *s1-*s2;
	}
	return *s1-*s2;
} 
/* 8.strncmp:
 * compares atmost n elements
 * returns 0(same),+ve(s1>s2) and -ve(s1<s2)
 */
int strncmp(char *s1, char *s2, size_t n) {
	while(*s1 != '\0' && *s2 != '\0' && n > 0) {
		if(*s1 == *s2) {
			s1++;
			s2++;
			n--;
		}
		else
			return *s1-*s2;
	} 
	return *s1-*s2;
}
/* 9.strchr:
 * returns ptr to first occourence of char c in the string s
 */
char *strchr1(char *s, char c) {
	while(*s != '\0') {
		if(*s == c)
			return s;
		s++;
	}
	return s;
}
/* 10.strrchr:
 * returns ptr to last occourence of char c in the string s
 */
char *strrchr1(char *s, char c) {
	char *p;
	p = NULL;
	while(*s != '\0') {
		if(*s == c)
			p = s;
		s++;
	}
	return p;
} 
/* 11.strpbrk:
 * return a ptr to first occurrence in s of one of the bytes in string accept
 */
char *strpbrk(char *s, char *accept) {
	char *q;
	while(*s != '\0') {
		q = accept;
		while(*q != '\0') {
			if(*q == *s)
				return s;
			q++;
		}
		s++;
	}
	return s;		
}
/* 12.strspn:
 * calculate length of the starting segment in s that consists entirely of bytes in accept
 */
size_t strspn(char *s, char *accept) {
	char *q;
	int flag;
	size_t len = 0;
	while(*s != '\0') {
		q = accept;
		flag = 0;
		while(*q != '\0') {
			if(*s == *q)
				flag = 1;
			q++;
		}
		if(flag == 0)
			return len;
		len++;
		s++;
	}
	return len;	
}
/* 13.strcspn:
 * calculate length of the initial segment of s which does not content any bytes in reject
 */
size_t strcspn(char *s, char *reject) {
	char *q;
	size_t len = 0;
	while(*s != '\0') {
		q = reject;
		while(*q != '\0') {
			if(*s == *q)
				return len;
			q++;
		}
		len++;
		s++;
	}
	return len;	
}
/* 14.strstr:
 * find thr first occurence of substring needle in the string haystack
 * return a ptr to found substring(and all after that)
 */
char *strstr(char *haystack, char *needle) { 
	char *p, *q;
	while(*haystack != '\0') {
		p = haystack;
		q = needle;
		while(*q !='\0') { 
			if(*q == *p) {
				q++;
				p++;
			}
			else
				break;
		}
		if(*q =='\0')                 //match found
			return haystack;
		else
			haystack++;
	}
	return haystack;		 
} 
/* 15.strdup:
 * Return a duplicate of the string s  in  memory  allocated  using malloc()
 */
char *strdup(char *s) {
	char *d, *r;
	d = (char *)malloc(strlen(s) + 1);
	r = d;
	while((*d = *s)) {
		s++;
		d++;
	}
	return r;
}
/* 16.strtok:
 * Extract tokens from the string s that are delimited by one of the bytes in delim.
 * Return ptr to token found
 * A null pointer is returned if there are no tokens left to retrieve.
 * The tokens returned by strtok() are ALWAYS NONEMPTY strings.
 */
char *strtok(char *s, char *delim){
	int i = 0;
	char *q, *r;
	static char *p;
	static char *pos = NULL;	//for remembering last string

	if(pos)
		p = pos;
	else
		p = s;					//strting case
	char *a;
	a = (char *)malloc(128);

	q = p;					//for checking
	r = delim;				//for checking
	if(*p == '\0')
		return NULL;
	while(*q != '\0') {
		r = delim;
		while(*r != '\0') { 
			if(*q != *r)
				r++;
			else
				break;
		}
		if(*r == '\0'){			//Not matched
			a[i] = *q;
			i++;
			q++;
		}	
		else {				//matched
			if(p == q) {		//empty string a
				p++;
				q++;
				continue;
			}					
			else {
				a[i] = '\0';
				pos = q + 1;
				return a; 
			}
		}		
	}
	pos = pos+i;	
	a[i] = '\0';
	return a;
}    

