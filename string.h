
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

#ifndef STRING_H__
#define STRING_H__

size_t strlength(const char *s);
char *strcopy(char *dest, const char *src);
char *strncopy(char *dest, const char *src, size_t n);
char *stpcopy(char *dest, const char *src);
char *strconcat(char *dest, const char *src);
char *strnconcat(char *dest, const char *src, size_t n);
int strcomp(const char *s1, const char *s2);
int strncomp(const char *s1, const char *s2, size_t n);
char *strchar(const char *s, char c);
char *strrchar(const char *s, char c);
char *strpbrk1(const char *s, const char *accept);
size_t strspn1(const char *s, const char *accept);
size_t strcspn1(const char *s, const char *reject);
char *strsubstr(const char *haystack, const char *needle);
char *strdupl(const char *s);
char *strtoken(char *s, const char *delim);
char *strsepr(char **stringp, const char *delim);
int strcol(const char *s1, const char *s2);
int strcasecomp(const char *s1, const char *s2);
int strncasecomp(const char *s1, const char *s2, size_t n);
char *index1(const char *s, int c);
char *rindex1(const char *s, int c);
int memcomp(const void *str1, const void *str2, size_t n);
void *memchar(const void *str, int c, size_t n);
void *memsett(void *str, int c, size_t n);
void *memmov(void *str1, void *str2, size_t n);
void *memcopy(void *str1, const void *str2, size_t n);

size_t strxfrm(char *dest, const char *src, size_t n);
char *strfry(char *string);
char *strerror(int errnum);

#endif
