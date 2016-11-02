
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
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include"string.h"

//#include<string.h>

enum function{STRLENGTH, STRCOPY, STRNCOPY, STPCOPY, STRCONCAT, STRNCONCAT, STRCOMP, STRNCOMP, STRCHAR, STRRCHAR, STRPBRK1, STRSPN1, STRCSPN1, STRSUBSTR, STRDUPL, STRTOKEN, STRSEPR, STRCOL, STRCASECOMP, STRNCASECOMP, INDEX1, RINDEX1, MEMCOMP, MEMCHAR, MEMSETT, MEMMOV, MEMCOPY};

#define SIZE 128
char *readfile(FILE *fp, char *file, int size) {
	int i = 0;
	char ch;
	while((fscanf (fp, "%c", &ch) != -1)) {
		if(i == size-1) {
			size += 128;
			file = (char *)realloc(file, size);
		}
		file[i++] = ch;
	}
	file[i] = '\0';
	return file;	
}

int strtoint(char *s) {
	int no = 0;
	while(*s) {
		no = 10*no + *s-'0';
		s++;	
	}
	return no;
}

int main(int argc, char *argv[]) {
	if(argc != 2){
		errno = EINVAL;
		perror("usage: ./program <filename>");
		return errno;
	}
	FILE *fp;
	fp = fopen(argv[1], "r");
	if(fp == NULL) {
		perror("can't open file:");
		return errno;
	}
	int size = SIZE, choice;
	char *file, *token;
	char *str, *str1, *str2, *str3, *str4;

	str = (char *)malloc(64);		
	str1 = (char *)malloc(32);	
	str2 = (char *)malloc(32);	
	str3 = (char *)malloc(32);	
	str4 = (char *)malloc(32);
	token = (char *)malloc(4);
	file = (char *)malloc(size);
	
	file = readfile(fp, file, SIZE);
//	printf("%s\n", file);

	while( (token = strtoken(file, "\t\n")) ) {
		printf("\n"); 
//		printf("%s\n",token); 
		choice = strtoint(token);
		switch(choice) {
			case STRLENGTH:	//0
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
 				printf("strlen: %s %s\n", str1, str2);
				int len = strlength(str1);
				printf("%d\n",len);
				break;
			}
			case STRCOPY:	//1
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
 				printf("strcpy: %s %s %s\n", str1, str2, str3);
 				str = strcopy(str1,str2);
				printf("%s\n", str);
				break;
			}
			case STRNCOPY:	//2
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
 				str4 = strtoken(file, "\n\t");
 				printf("strncpy: %s %s %s %s\n", str1, str2, str3, str4);
 				str = strncopy(str1, str2, strtoint(str3));
				printf("%s\n", str);
				break;
			}
			case STPCOPY:	//3
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
 				printf("stpcpy: %s %s %s\n", str1, str2, str3);
				str = stpcopy(str1, str2);
				if(str) {
					if(*str == '\0')
						printf("empty:as stpcpy returns pointer to end of string\n");
					else
						printf("%s\n", str);
				}
				else
					printf("\n");
				break;
			}
			case STRCONCAT:	//4
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
 				printf("strcat: %s %s %s\n", str1, str2, str3);
 				str = strconcat(str1,str2);
				printf("%s\n", str);
				break;
			}
			case STRNCONCAT:	//5
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
 				str4 = strtoken(file, "\n\t");
 				printf("strncat: %s %s %s %s\n", str1, str2, str3, str4);
 				str = strnconcat(str1, str2, strtoint(str3));
				printf("%s\n", str);
				break;
			}
			case STRCOMP:	//6
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
 				printf("strcmp: %s %s %s\n", str1, str2, str3);
				int diff = strcomp(str1, str2);
				printf("%d\n", diff);
				break;
			}
			case STRNCOMP:	//7
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
				str4 = strtoken(file, "\n\t");
 				printf("strncmp: %s %s %s %s\n", str1, str2, str3, str4);
				int diff = strncomp(str1, str2, strtoint(str3));
				printf("%d\n", diff);
				break;
			}
			case STRCHAR:	//8
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
 				printf("strchr: %s %s %s\n", str1, str2, str3);
				str = strchar(str1, *str2);
				if(str)
					printf("%s\n", str);
				else
					printf("\n");
				break;
			}
			case STRRCHAR:	//9
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
				printf("strrchr: %s %s %s\n", str1, str2, str3);
				str = strrchar(str1, *str2);
				if(str)
					printf("%s\n", str);
				else
					printf("\n");
				break;
			}
			case STRPBRK1:	//10
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
				printf("strpbrk: %s %s %s\n", str1, str2, str3);
				str = strpbrk1(str1, str2);
				printf("%s\n", str);
				break;
			}
			case STRSPN1:	//11
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
				printf("strspn: %s %s %s\n", str1, str2, str3);
				int len = strspn1(str1, str2);
				printf("%d\n", len);
				break;
			}
			case STRCSPN1:	//12
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
				printf("strcspn: %s %s %s\n", str1, str2, str3);
				int len = strcspn1(str1, str2);
				printf("%d\n", len);
				break;
			}
			case STRSUBSTR:	//13
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
				printf("strstr: %s %s %s\n", str1, str2, str3);
				str = strsubstr(str1, str2);
				if(str)
					printf("%s\n", str);
				else
					printf("\n");
				break;
			}
			case STRDUPL:	//14
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				printf("strdup: %s %s\n", str1, str2);
				str = strdupl(str1);
				printf("%s\n", str);
				break;
			}
			case STRTOKEN:	//15
				break;
			case STRSEPR:	//16
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
				str4 = strtoken(file, "\n\t");
 				printf("strsep: %s %s %s %s\n", str1, str2, str3, str4);
				str = strsepr(&str1, str2);
				if(str)
					printf("initial token: %s\n", str);
				else
					printf("initial token: empty\n");

				if(str1)
					printf("updated str:   %s\n", str1); 
				else
					printf("updated str: empty\n"); 
				break;
			}
			case STRCOL:	//17
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
 				printf("strcoll: %s %s %s\n", str1, str2, str3);
				int diff = strcol(str1, str2);
				printf("%d\n", diff);
				break;
			}
			case STRCASECOMP:	//18
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
 				printf("strcasecmp: %s %s %s\n", str1, str2, str3);
				int diff = strcasecomp(str1, str2);
				printf("%d\n", diff);
				break;
			}
			case STRNCASECOMP:	//19
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
				str4 = strtoken(file, "\n\t");
 				printf("strncasecmp: %s %s %s %s\n", str1, str2, str3, str4);
				int diff = strncasecomp(str1, str2, strtoint(str3));
				printf("%d\n", diff);
				break;
			}
			case INDEX1:	//20
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
 				printf("index: %s %s %s\n", str1, str2, str3);
				str = index1(str1, *str2);
				if(str)
					printf("%s\n", str);
				else
					printf("\n");
				break;
			}
			case RINDEX1:	//21
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
				printf("rindex: %s %s %s\n", str1, str2, str3);
				str = rindex1(str1, *str2);
				if(str)
					printf("%s\n", str);
				else
					printf("\n");
				break;
			}
			case MEMCOMP:	//22
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
				str4 = strtoken(file, "\n\t");
 				printf("memcmp: %s %s %s %s\n", str1, str2, str3, str4);
				int diff = memcomp(str1, str2, strtoint(str3));
				printf("%d\n", diff);
				break;
			}
			case MEMCHAR:	//23
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
				str4 = strtoken(file, "\n\t");
 				printf("memchr: %s %s %s %s\n", str1, str2, str3, str4);
				str = memchar(str1, *str2, strtoint(str3));
				if(str)
					printf("%s\n", str);
				else
					printf("\n");
				break;
			}
			case MEMSETT:	//24
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
				str4 = strtoken(file, "\n\t");
 				printf("memset: %s %s %s %s\n", str1, str2, str3, str4);
				str = memsett(str1, *str2, strtoint(str3));
				printf("%s\n", str);
				break;
			}
			case MEMMOV:	//25
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
 				str4 = strtoken(file, "\n\t");
 				printf("memmove: %s %s %s %s\n", str1, str2, str3, str4);
 				str = memmov(str1, str2, strtoint(str3));
				printf("%s\n", str);
				break;
			}
			case MEMCOPY:	//26
			{
				str1 = strtoken(file, "\n\t");
				str2 = strtoken(file, "\n\t");
				str3 = strtoken(file, "\n\t");
 				str4 = strtoken(file, "\n\t");
 				printf("memcpy: %s %s %s %s\n", str1, str2, str3, str4);
 				str = memcopy(str1, str2, strtoint(str3));
				printf("%s\n", str);
				break;
			}
			default : 
				printf("bad input\n");
				break;	
		}
	}		
	return 0;
}
