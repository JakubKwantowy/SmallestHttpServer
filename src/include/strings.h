#include "types.h"

typedef char *String;
typedef char StringBuffer[];

extern int strlen(String str);
extern void fprint(fd_t fd, String str);

#define print(str) fprint(1, (str))
