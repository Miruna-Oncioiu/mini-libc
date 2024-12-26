// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source) {
	/* TODO: Implement strcpy(). */
	char *dest = destination;
	while (*source != '\0') {
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len) {
	/* TODO: Implement strncpy(). */
	size_t i;
	char *dest = destination;
	for (i = 0; i < len; i++) {
		if (*source != '\0') {
			*dest = *source;
			source++;
			dest++;
		} else {
			*dest = '\0';
		}
	}
	return destination;
}

char *strcat(char *destination, const char *source) {
	/* TODO: Implement strcat(). */
	char *dest = destination;
	while (*dest != 0)
		dest++;
	while (*source != '\0') {
		*dest = *source;
		dest++;
		source++;
	}
	*dest = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len) {
	/* TODO: Implement strncat(). */
	size_t i;
	char *dest = destination;
	while (*dest != '\0')
		dest++;
	for (i = 0; i < len; i++) {
		if (*source != 0) {
			*dest = *source;
			source++;
			dest++;
		}
	}
	*dest = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2) {
	/* TODO: Implement strcmp(). */
	while (*str1 != '\0' || *str2 != '\0') {
		if (*str1 > *str2)
			return 1;
		else if (*str1 < *str2)
			return -1;
		str1++;
		str2++;
	}
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len) {
	/* TODO: Implement strncmp(). */
	size_t i;
	for (i = 0; i < len; i++) {
		if (*str1 > *str2)
			return 1;
		else if (*str1 < *str2)
			return -1;
		str1++;
		str2++;
	}
	return 0;
}

size_t strlen(const char *str) {
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c) {
	/* TODO: Implement strchr(). */
	char car = (char)c;
	while (*str != '\0') {
		if (*str == car)
			return (char *)str;
		str++;
	}
	return NULL;
}

char *strrchr(const char *str, int c) {
	/* TODO: Implement strrchr(). */
	char car = (char)c;
	char *last = NULL;
	while (*str != '\0') {
		if (*str == car)
			last = (char *)str;
		str++;
	}
	if (last != NULL)
		return last;
	return NULL;
}

char *strstr(const char *haystack, const char *needle) {
	/* TODO: Implement strstr(). */
	while (*haystack != '\0') {
		char *copy = (char *)haystack;
		while (*copy == *needle) {
			copy++;
			needle++;
		}
		if (*needle == '\0')
			return (char *)haystack;
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle) {
	/* TODO: Implement strrstr(). */
	char *last = NULL;
	while (*haystack != '\0') {
		char *copy = (char *)haystack;
		char *n = (char *)needle;
		while (*copy == *n) {
			copy++;
			n++;
		}
		if (*n == '\0')
			last = (char *)haystack;
		haystack++;
	}
	if (last != NULL)
		return (char *)last;
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num) {
	/* TODO: Implement memcpy(). */
	char *dest = (char *)destination;
	char *src = (char *)source;
	size_t i = 0;
	for (i = 0; i < num; i++) {
		*dest = *src;
		dest++;
		src++;
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num) {
	/* TODO: Implement memmove(). */
	char *dest = (char *)destination;
	char *src = (char *)source;
	if (dest <= src) {
		while (num != 0) {
			*dest = *src;
			dest++;
			src++;
			num--;
		}
	} else if (dest > src) {
		dest = dest + num - 1;
		src = src + num - 1;
		while (num != 0) {
			*dest = *src;
			dest--;
			src--;
			num--;
		}
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num) {
	/* TODO: Implement memcmp(). */
	size_t i = 0;
	char *pt1 = (char *)ptr1;
	char *pt2 = (char *)ptr2;
	for (i = 0; i < num; i++) {
		if (*pt1 != *pt2) {
			if (*pt1 < *pt2)
				return -1;
			else if (*pt1 > *pt2)
				return 1;
		}
	}
	return 0;
}

void *memset(void *source, int value, size_t num) {
	/* TODO: Implement memset(). */
	size_t i = 0;
	char *src = source;
	char v = value;
	for (i = 0; i < num; i++) {
		*src = v;
		src++;
	}
	return source;
}
