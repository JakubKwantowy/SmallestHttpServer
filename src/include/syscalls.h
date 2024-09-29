#ifndef SYSCALLS_H
#define SYSCALLS_H

#include "types.h"

extern size_t _read(fd_t fd, char *buf, size_t count);
extern void _write(fd_t fd, char *buf, size_t count);
extern void _close(fd_t fd);
extern fd_t _socket(int domain, int type, int protocol);
extern int _setsockopt(fd_t fd, int level, int optname, void *value, size_t len);
extern int _bind(fd_t fd, void *addr, size_t len);
extern int _listen(fd_t fd, int backlog);
extern fd_t _accept(fd_t fd, void *addr, size_t *len);

#endif
