#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include "client.h"


void client::start() {

    struct sockaddr_in serv_addr;
    char sbuff[MAX_SIZE],rbuff[MAX_SIZE];

    if((sock_desc = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        printf("ERROR\n");

    bzero((char *) &serv_addr, sizeof (serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("192.168.100.13");
    serv_addr.sin_port = htons(8888);

    if (connect(sock_desc, (struct sockaddr *) &serv_addr, sizeof (serv_addr)) < 0) {
        printf("Error conectandose al servidor\n");
        return;
    }

    printf("Cliente Conectado\n");
    while(true)
    {
        //send(sock_desc,sbuff,strlen(sbuff),0);

        if(recv(sock_desc,rbuff,MAX_SIZE,0)==0)
            printf("Error");
        else
            fputs(rbuff,stdout);

        bzero(rbuff,MAX_SIZE);//to clean buffer-->IMP otherwise previous word characters also came
    }
    close(sock_desc);
    return;
}

long client::Send(const char *msg) {
    send(sock_desc, msg, strlen(msg), 0);
}
