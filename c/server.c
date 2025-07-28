#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h> // Required for htons, inet_pton

int main(){
    
    int retVal;

    // Create socket
    int servSock = socket(AF_INET, SOCK_STREAM, 0);
    if(servSock < 0){
        perror("Failed to create socket");
        return -1;
    }

    // Construction of server address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY); // hostlong to network bytes
    addr.sin_port = htons(55432); // hostshort to network bytes

    // Bind socket with address
    retVal = bind(servSock, (struct sockaddr *) &addr, sizeof(addr));
    if(retVal < 0){
        perror("Failed binding address to socket");
        return -1;
    }

    // Listen for incoming connections
    retVal = listen(servSock , 5);
    if(retVal < 0){
        perror("Failed to listen on socket");
        return -1;
    }

    // Receive and process incoming requests
    while(1){
        struct sockaddr_in clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);

        // Wait for client to connect
        int clientSock = accept(servSock, (struct sockaddr *) &clientAddr, &clientAddrLen);
        if( clientSock < 0 ){
            perror("\nFailed to connect to client");
            return -1;
        }

        printf("A client connected\n");
        //char clientName[INET_ADDRSTRLEN];
        //if (inet_ntop(AF_INET, &clientAddr.sin_addr.s_addr, clientName ,sizeof(clientName)) != NULL)
        //printf("Handling client %s/%d\n", clientName, ntohs(clientAddr.sin_port));
        //else
        //    puts("Unable to get client address");
    }
}