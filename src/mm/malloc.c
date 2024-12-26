// SPDX-License-Identifier: BSD-3-Clause

#include <internal/essentials.h>
#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

void *malloc(size_t size) {
	/* TODO: Implement malloc(). */
	void *p = mmap(NULL, size, PROT_READ | PROT_WRITE,
					 MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	// Adaug blocul in mem_list
	if (mem_list_add(p, size) != 0) {
		munmap(p, size);
		return NULL;
	}
	return p;
}

void *calloc(size_t nmemb, size_t size) {
	/* TODO: Implement calloc(). */
	size_t total = nmemb * size;
	void *p = mmap(NULL, total, PROT_READ | PROT_WRITE,
					 MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	memset(p, 0, total);
	return p;
}

void free(void *ptr) {
	/* TODO: Implement free(). */
    struct mem_list *item = mem_list_find(ptr);
    munmap(ptr, item->len);
    mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size) {
	/* TODO: Implement realloc(). */
	size_t old_size = 0;
	void *new_ptr = malloc(size);
	if (ptr && old_size > 0) {
		if (old_size < size)
			memcpy(new_ptr, ptr, old_size);
		else
			memcpy(new_ptr, ptr, size);
	}
	return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size) {
	/* TODO: Implement reallocarray(). */
	size_t total = nmemb * size;
	return realloc(ptr, total);
}
