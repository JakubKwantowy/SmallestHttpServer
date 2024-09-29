#include "include/strings.h"
#include "include/syscalls.h"

int strlen(String str) {
    int i = 0;
    while(str[i]) i++;
    return i;
}

void fprint(fd_t fd, String str) {
    _write(fd, str, strlen(str));
}
