/*
 * Stub version of write.
 */

#include <_ansi.h>
#include <_syslist.h>
#include <errno.h>
#undef errno
extern int errno;

int
_DEFUN (write, (file, ptr, len),
        int   file  _AND
        char *ptr   _AND
        int   len)
{
  errno = ENOSYS;
  return -1;
}


