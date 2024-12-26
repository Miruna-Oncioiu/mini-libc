// SPDX-License-Identifier: BSD-3-Clause

#include <errno.h>
#include <internal/syscall.h>
#include <sys/mman.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd,
		   off_t offset) {
	/* TODO: Implement mmap(). */
	long result = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	if ((flags == MAP_ANONYMOUS && fd < 0)) {
		errno = EINVAL;
		return MAP_FAILED;
	} else if (flags != MAP_ANONYMOUS && fd > -1) {
		errno = EBADF;
		return MAP_FAILED;
	} else if (result == -1) {
		errno = ENOMEM;
		return MAP_FAILED;
	}
	return (void *)result;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags) {
	/* TODO: Implement mremap(). */
	long result = syscall(__NR_mremap, old_address, old_size, new_size, flags);
	if (result == -1) {
		errno = ENOMEM;
		return MAP_FAILED;
	}
	return (void *)result;
}

int munmap(void *addr, size_t length) {
	/* TODO: Implement munmap(). */
	int result = syscall(__NR_munmap, addr, length);
	if (result == -1) {
		errno = EINVAL;
		return -1;
	}
	return result;
}
