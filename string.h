size_t strlen(char *s);
char *strcpy(char *dest, char *src);
char *strncpy(char *dest, char *src, size_t n);
char *stpcpy(char *dest, char *src);
char *strcat(char *dest, char *src);
char *strncat(char *dest, char *src, size_t n);
int strcmp(char *s1, char *s2);
int strncmp(char *s1, char *s2, size_t n);
char *strchr1(char *s, char c);
char *strrchr1(char *s, char c);
char *strpbrk(char *s, char *accept);
size_t strspn(char *s, char *accept);
size_t strcspn(char *s, char *reject);
char *strstr(char *haystack, char *needle);
char *strdup(char *s);
char *strtok(char *s, char *delim);

