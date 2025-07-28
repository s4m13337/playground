#include<stdio.h>
#include <sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

int main(){

    char *msg = "Hello from the other side";

    // Create client socket
    int clientSock = socket(AF_INET, SOCK_STREAM, 0);

    // Create socket address structure
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(55432); // hostshort to network bytes
    if (inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to server
    if (connect(clientSock, (struct sockaddr*) &addr, sizeof(addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    } else {
        // Send message
        send(clientSock, msg, strlen(msg), 0);
    }

}
