#include "include/syscalls.h"
#include "include/strings.h"

struct sockaddr_in {
    short sin_family;
    short sin_port;
    unsigned int sin_addr;
    char padding[8];
};

short htons(short value) {
    union byteShort {
        short value;
        char bytes[2];
    };
    
    union byteShort data;
    char temp;

    data.value = value;
    temp = data.bytes[1];
    data.bytes[1] = data.bytes[0];
    data.bytes[0] = temp;
    return data.value;
}

int main() {
    fd_t serversocket = _socket(2, 1, 0);
    if(serversocket == -1) {
        print("Socket Init Error\n");
        return 1;
    }

    int option = 1;

    if(_setsockopt(serversocket, 1, 2, &option, sizeof(option))) {
        print("Socket Option Error\n");
        _close(serversocket);
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = 2;
    addr.sin_port = htons(8080);
    if(_bind(serversocket, &addr, sizeof(addr))) {
        print("Socket Bind Error\n");
        _close(serversocket);
        return 1;
    }

    if(_listen(serversocket, 64)) {
        print("Socket Listen Error\n");
        _close(serversocket);
        return 1;
    }

    while(1) {
        fd_t clientsocket = _accept(serversocket, NULL, NULL);
        if(clientsocket == -1) {
            print("Socket Accept Warn");
            continue;
        }

        char buffer[1024];

        _read(clientsocket, buffer, 1023);

        print(buffer);
        
        fprint(
            clientsocket, 
            "HTTP/1.0 200 OK\n"
            "Content-Type: text/html; charset=utf-8\n"
            "\n"
            "<!DOCTYPE html>\n"
            "<html>\n"
            "   <head>\n"
            "       <meta charset=\"utf-8\"/>\n"
            "   </head>\n"
            "   <body>\n"
            "       <h1>Hello World!</h1>\n"
            "       Welcome to My Minimalistic HTTP Server!<br>\n"
            "       It is written in C and Assembly<br>\n"
            "       Thanks for looking at my Website!<br>\n"
            "   </body>\n"
            "</html>\n"
        );

        _close(clientsocket);
    }

    _close(serversocket);

    return 0;
}
