#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip.h>

int main() {
    printf(
        "AF_INET: %d\n"
        "SOCK_STREAM: %d\n"
        "SOL_SOCKET: %d\n"
        "SO_REUSEADDR: %d\n"
        ,
        AF_INET, SOCK_STREAM, SOL_SOCKET, SO_REUSEADDR
    );

    return 0;
}