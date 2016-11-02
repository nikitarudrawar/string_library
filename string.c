
/*****************************************************************************
 * Copyright (C)2016 Nikita Rudrawar nikita.rudrawar@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/


#include<stdio.h>
#include<stdlib.h>

/* 1.strlength:
 * returns the number of bytes in the string s.
 */
size_t strlength(const char *s) {
	size_t len = 0;
	while(*s) {
		len++;
		s++;
	}
	return len;
}
/* 2.strcopy:
 * Copy the string src to dest
 * returns a pointer to the start of dest
 */
char *strcopy(char *dest, const char *src) {
	char *p;
	p = dest;
	while((*dest = *src)) {
		dest++;
		src++;
	}
	return p;
}
/* 3.strncopy: 
 * Copy at most n bytes  from  string  src  to  dest  
 * returns a pointer to the start of dest.
 */
char *strncopy(char *dest, const char *src, size_t n) {
	char *p;
	p = dest;
	while((n>0) && (*dest = *src)) {
		dest++;
		src++;
		n--;
	}
	return p;
}
/* 4.stpcopy:
 * Copy  a  string from src to dest
 * returns a pointer to the end(i.e. to '\0'char) of the resulting string at dest
 */
char *stpcopy(char *dest, const char *src) {
	if(src == NULL)
		return NULL;
	while((*dest = *src)) {
		dest++;
		src++;
	}
	return dest;
}
/* 5.strconcat:
 * Append the string src to the string dest  
 * returning  a  pointer dest
 */
char *strconcat(char *dest, const char *src) {
	char *p;
	p = dest;
	while(*dest)
		dest++;
	while((*dest = *src)) {
		src++;
		dest++;
	}
	return p;
}
/* 6.strnconcat:
 * Append  at  most  n characters from the string src to the string
 * returning  a pointer to dest
 */
char *strnconcat(char *dest, const char *src, size_t n) {
	int i = 0;
	char *p;
	p = dest;
	while(*dest)
		dest++;
	while((i<n) && (*dest = *src)) {
		src++;
		dest++;
		i++;
	}
	return p;
}
/* 7.strcomp:
 * returns 0(same),+ve(s1>s2) and -ve(s1<s2)
 */
int strcomp(const char *s1, const char *s2) {
	while(*s1 && *s2){
		if(*s1 == *s2) {
			s1++; 
			s2++;
		}
		else
			return *s1-*s2;
	}
	return *s1-*s2;
} 
/* 8.strncomp:
 * compares atmost n elements
 * returns 0(same),+ve(s1>s2) and -ve(s1<s2)
 */
int strncomp(const char *s1, const char *s2, size_t n) {
	while(*s1 && *s2 && n > 0) {
		if(*s1 == *s2) {
			s1++;
			s2++;
			n--;
		}
		else
			return *s1-*s2;
	}
	if(n == 0) {
		s1--;
		s2--;
	}
	return *s1-*s2;
}
/* 9.strchar:
 * returns ptr to first occourence of char c in the string s
 */
char *strchar(const char *s, int c) {
	while(*s) {
		if(*s == (char)c)
			return (char *)s;
		s++;
	}
	return (char *)s;
}
/* 10.strrchar:
 * returns ptr to last occourence of char c in the string s
 */
char *strrchar(const char *s, int c) {
	char *p;
	p = NULL;
	while(*s) {
		if(*s == (char)c)
			p = (char *)s;
		s++;
	}
	return p;
} 
/* 11.strpbrk1:
 * return a ptr to first occurrence in s of one of the bytes in string accept
 */
char *strpbrk1(const char *s, const char *accept) {
	char *q;
	while(*s) {
		q = (char *)accept;
		while(*q) {
			if(*q == *s)
				return (char *)s;
			q++;
		}
		s++;
	}
	return (char *)s;		
}
/* 12.strspn1:
 * calculate length of the starting segment in s that consists entirely of bytes in accept
 */
size_t strspn1(const char *s, const char *accept) {
	char *q;
	int flag;
	size_t len = 0;
	while(*s) {
		q = (char *)accept;
		flag = 0;
		while(*q) {
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
/* 13.strcspn1:
 * calculate length of the initial segment of s which does not content any bytes in reject
 */
size_t strcspn1(const char *s, const char *reject) {
	char *q;
	size_t len = 0;
	while(*s) {
		q = (char *)reject;
		while(*q) {
			if(*s == *q)
				return len;
			q++;
		}
		len++;
		s++;
	}
	return len;	
}
/* 14.strsubstr:
 * find thr first occurence of substring needle in the string haystack
 * return a ptr to found substring(and all after that)
 */
char *strsubstr(const char *haystack, const char *needle) { 
	char *p, *q;
	while(*haystack) {
		p = (char *)haystack;
		q = (char *)needle;
		while(*q) { 
			if(*q == *p) {
				q++;
				p++;
			}
			else
				break;
		}
		if(*q == '\0')                 //match found
			return (char *)haystack;
		else
			haystack++;
	}
	return NULL;		 
} 
/* 15.strdupl:
 * Return a duplicate of the string s  in  memory  allocated  using malloc()
 */
char *strdupl(const char *s) {
	char *d, *r;
	d = (char *)malloc(strlength(s) + 1);
	r = d;
	while((*d = *s)) {
		s++;
		d++;
	}
	return r;
}
/* 16.strtoken:
 * Extract tokens from the string s that are delimited by one of the bytes in delim.
 * Return ptr to token found
 * A null pointer is returned if there are no tokens left to retrieve.
 * The tokens returned by strtok() are ALWAYS NONEMPTY strings.
 */
char *strtoken(char *s, const char *delim){
	int i = 0;
	char *q, *r;
	char *p;
	static char *pos = NULL;			//for remembering last string
	static int v = 0;

	if(v == 0)					//first call
		p = s;
	else
		p = pos;					//starting case

	v = 1;

	char *a;
	a = (char *)malloc(128);

	q = p;							//for checking
	if(*p == '\0')
		return NULL;
	while(*q != '\0') {
		r = (char *)delim;			//for checking
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
		else {					//matched
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
	pos = q;		
	a[i] = '\0';
	return a;
}    
   
/* 17.strsepr:
 * Extract the initial token in stringp that is delimited by one of the bytes in delim.
 * If *stringp is NULL, the strsep() function returns NULL and does nothing else
 * *stringp is updated to point past the token
 * In case no delimiter was found, the token is taken to be the entire string *stringp, and *stringp is made NULL. 
 */   
char *strsepr(char **stringp, const char *delim) {
	char *q, *r;

	char *token;
	token = *stringp;

	q = *stringp;						//for checking
	r = (char *)delim;					//for checking
	if(*stringp == NULL)
		return NULL;
	while(*q) {
		r = (char *)delim;
		while(*r) { 
			if(*q != *r)
				r++;
			else
				break;
		}
		if(*r == '\0')				//Not matched
			q++;		
		else {						//matched
			//first char is in delim
			if(*stringp == q){		
				(*stringp)++;
				return NULL;
			}
			//other than 1st char in delim				
			else {
				*q = '\0';
				if(*(q+1) == '\0')		//last char is in delim...so, stringp is over
					*stringp = NULL;
				else	
					*stringp = q + 1;
				return token; 
			}
		}		
	}
	/* out of loop so.....*q = null...end of string 
	 * token == whole string
	 * string becomes NULL;
	 */
	*stringp = NULL;	

	return token;
}    
/* 18.strcol:
 * Compare the strings s1 with s2 using the current locale.
 * smallcase > uppercase > digits----ASCII 
 * similar to strcmp
 */
int strcol(const char *s1, const char *s2) {
        while(*s1 && *s2) {
                if(*s1 == *s2) {
                        s1++;
                        s2++;
                }
                else
                        return *s1-*s2;
        }
        return *s1-*s2;
}
/* 19.strcasecomp:
 * Compare the strings s1 and s2 ignoring case.
 * returns 0(same),+ve(s1>s2) and -ve(s1<s2)
 * similar to strcmp(ignoring case)
 */
int strcasecomp(const char *s1, const char *s2) {
	while(*s1 && *s2){
		if((*s1 >= 65) && (*s1 <= 90)) {				// *s1 is uppercase char
			if((*s1 == *s2) || (*s1+32 == *s2)) {
				s1++; 
				s2++;
			}
			else
				return *s1-*s2;
		}
		else if((*s1 >= 97) && (*s1 <= 122)) {			// *s1 is lowercase char
			if((*s1 == *s2) || (*s1-32 == *s2)) {
				s1++; 
				s2++;
			}				
			else
				return *s1-*s2;
		}
		else if((*s1 == *s2)) {
				s1++; 
				s2++;
		}
		else		
			return *s1-*s2;
	}
	return *s1-*s2;
}
/* 20.strncasecomp:
 * Compare the first n characters of the strings s1 and s2 ignoring case.
 * returns 0(same),+ve(s1>s2) and -ve(s1<s2)
 * similar to strncmp(ignoring case)
 */
int strncasecomp(const char *s1, const char *s2, size_t n) {
	while((n > 0) && *s1 && *s2){
		n--;
		if((*s1 >= 65) && (*s1 <= 90)) {				// *s1 is uppercase char
			if((*s1 == *s2) || (*s1+32 == *s2)) {
				s1++; 
				s2++;
			}
			else
				return *s1-*s2;
		}
		else if((*s1 >= 97) && (*s1 <= 122)) {			// *s1 is lowercase char
			if((*s1 == *s2) || (*s1-32 == *s2)) {
				s1++; 
				s2++;
			}				
			else
				return *s1-*s2;
		}
		else if((*s1 == *s2)) {
				s1++; 
				s2++;
		}
		else		
			return *s1-*s2;
	}
	if(n == 0)
		return 0;
	return *s1-*s2;
}
/* 21.index1:
 * Return pointer to the first occurrence of the character c in s.
 * similar to strchr
 */
char *index1(const char *s, int c) {
	while(*s) {
		if(*s == (char)c)
			return (char *)s;
		s++;
	}
	return (char *)s;
}
/* 22.rindex1:
 * returns pointer to the last occurrence  of  the character c in s.
 * similar to  strrchr
 */
char *rindex1(const char *s, int c) {
	char *p;
	p = NULL;
	while(*s) {
		if(*s == (char)c)
			p = (char *)s;
		s++;
	}
	return p;
} 
/* 23.memcomp:
 * compares the first n bytes of memory area str1 and memory area str2.
 * returns 0(same),+ve(s1>s2) and -ve(s1<s2)
 * similar to strncmp
 */
int memcomp(const void *str1, const void *str2, size_t n) {
	int diff;
	char *s1, *s2;
	s1 = (char *)str1;
	s2 = (char *)str2;
	while((n > 0) && (*s1) && (*s2)) {
		diff = *s1++ - *s2++;
		if(diff != 0)
			return diff;
		n--;
	}
	s1--;
	s2--;
	return diff;
}
/* 24.memchar:
 * searches for the first occurrence of the character c (an unsigned char) in the first n bytes 
			of the string pointed to, by the argument str.
 * returns a pointer to the matching byte or NULL if the character does not occur
 * similar to strchr(n bytes)
 */
void *memchar(void *str, int c, size_t n) {
	char *s;
	s = (char *)str;
	while((n > 0) && (*s)) {
		if((*s - c) == 0){
			str = s;
			return str;
		}
		s++;
		n--;
	}
	return NULL;
}
/* 25.memsett:
 * copies the character c (an unsigned char) to the first n characters of the
 				 string pointed to, by the argument str.
 * returns a pointer to the memory area str
 */
void *memsett(void *str, int c, size_t n) {
	char *s = (char *)str;
	while((n-- > 0)  && (*s)) {
		*s = c;
		s++;
	}
	if(*s == '\0') {
		n++;
		while(n-- >0)
			*s++ = c;
		*s = '\0';
	}
	return str;
}
/* 26.memmov:
 * copies n characters from str2 to str1, but for overlapping memory blocks
 * memmove() is a safer approach than memcpy().
 * returns a pointer to the destination, which is str1.
 * similar to strncpy(for overlapping memory blocks)
 */
void *memmov(void *str1, void *str2, size_t n){
	char *dest, *src;
	int i;
	dest = (char *)str1;
	src = (char *)str2;
	if(src > dest) {
		for(i = 0; (i < n)&&(src[i] != '\0'); i++)
			dest[i] = src[i];
		if((n > i) && (src[i] == '\0'))		//if came upto '\0' then copy that also
			dest[i] = '\0';
	}
	else if(dest > src) {
		int dl = strlength(dest);
		if(n > dl)		//charcters after dest are less than char to be copied 
			n = dl;
		for(i = n-1; (i >= 0)&&(dest[i] != '\0'); i--)
			dest[i] = src[i];
	}
	else	//same
		return str1;
	return str1;
}
/* 27.memcopy:
 * copies n characters from memory area str2 to memory area str1.
 * returns a pointer to destination, which is str1.
 * similar to strncpy
 */
void *memcopy(void *str1, const void *str2, size_t n) {
	char *s1, *s2;
	s1 = (char *)str1;
	s2 = (char *)str2;
	while((n++ > 0) && (*s1++ = *s2++)) {

	}
	if(n == 0)
		*s1 = '\0';
	return str1;
}
