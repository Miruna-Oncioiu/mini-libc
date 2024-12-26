#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <internal/syscall.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    if (req->tv_nsec < 0 || req->tv_nsec >= 1000000000) {
        errno = EINVAL;
        return -1;
    }
    int ret = syscall(35, req, rem);
    if (ret == -1) {
        if (errno == EINTR) {
            return -1;
        }
    }
    return 0;
}
