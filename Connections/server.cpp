#include "server.h"
#include <rapidjson/rapidjson.h>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include "rapidjson/writer.h"
#include "../Parsers/XMLManager.h"
#include <rapidjson/document.h>
#include <string.h>
#include <iostream>

int opt = TRUE;
int master_socket , addrlen , new_socket , client_socket[10] ,
        max_clients = 10 , activity, i , valread , sd;
int max_sd;
int num=2000;
struct sockaddr_in address;

using namespace std;
using namespace rapidjson;

void server::validate(const char * json){
    Document d;
    d.Parse(json);
    Value& type=d["type"];
    
    
    if(strcmp(type.GetString(),"SELECT")==0){
        XMLManager a;
	    cout << json;
	    a.generateTableMetadata(json);
    }
    
    else if(strcmp(type.GetString(),"JOIN")==0){
        cout << "Join" ;
    
    }
    else if(strcmp(type.GetString(),"CREATE INDEX")==0){
        cout << "Create index" ;
    
    }
    else if(strcmp(type.GetString(),"DROP TABLE")==0){
	    cout << "Drop table" ;
    }
    else if(strcmp(type.GetString(),"INSERT")==0){
	    cout << "Insert" ;
    
    }
    else if(strcmp(type.GetString(),"DELETE")==0){
    
    
    }
    else if(strcmp(type.GetString(),"UPDATE")==0){
    
    
    }
    else{

        cout << "Could not determine the requested petition" << endl;
    }

}
void server::init() {


    char buffer[1024];

    //set of socket descriptors
    fd_set readfds;

    //initialise all client_socket[] to 0 so not checked
    for (i = 0; i < max_clients; i++)
    {
        client_socket[i] = 0;
    }

    //create a master socket
    if( (master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    //set master socket to allow multiple connections ,
    //this is just a good habit, it will work without this
    if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,
                   sizeof(opt)) < 0 )
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    //type of socket created
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("192.168.100.13");//Write your IP
    address.sin_port = htons( PORT );

    //bind the socket to localhost port 8080
    if (bind(master_socket, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    printf("Escuchando en el puerto %d \n", PORT);

    //try to specify maximum of 3 pending connections for the master socket
    if (listen(master_socket, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    //accept the incoming connection
    addrlen = sizeof(address);


    puts("Esperando conexiones ...");

    while(TRUE)
    {
        //clear the socket set
        FD_ZERO(&readfds);

        //add master socket to set
        FD_SET(master_socket, &readfds);
        max_sd = master_socket;

        //add child sockets to set
        for ( i = 0 ; i < max_clients ; i++)
        {
            //socket descriptor
            sd = client_socket[i];

            //if valid socket descriptor then add to read list
            if(sd > 0)
                FD_SET( sd , &readfds);

            //highest file descriptor number, need it for the select function
            if(sd > max_sd)
                max_sd = sd;
        }

        //wait for an activity on one of the sockets , timeout is NULL ,
        //so wait indefinitely
        activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);

        if ((activity < 0) && (errno!=EINTR))
        {
            printf("select error");
        }

        //If something happened on the master socket ,
        //then its an incoming connection
        if (FD_ISSET(master_socket, &readfds))
        {
            if ((new_socket = accept(master_socket,
                                     (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
            {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            //inform user of socket number
            //Send("Hola");
            printf("Nueva conexion , socket fd %d , ip : %s , puerto : %d\n" , new_socket , inet_ntoa(address.sin_addr) , ntohs
                    (address.sin_port));

            //send new connection message
            //if( send(new_socket, "Conectado", strlen("Conectado"), 0) != strlen("Conectado") )
            //{
              //  perror("send");
            //}

            //puts("Mensaje enviado con exito");//succesfully send


            //add new socket to array of sockets
            for (i = 0; i < max_clients; i++)
            {
                //if position is empty
                if( client_socket[i] == 0 )
                {
                    client_socket[i] = new_socket;
                    printf("Añadido a la lista de sockets como %d\n" , i);
                    break;
                }
            }
        }

        //else its some IO operation on some other socket
        for (i = 0; i < max_clients; i++)
        {
            sd = client_socket[i];

            if (FD_ISSET( sd , &readfds))
            {
                //Check if it was for closing , and read the message
                if ((valread = read( sd , buffer, 1024)) == 0)
                {
                    //Somebody disconnected , get his details and print
                    getpeername(sd , (struct sockaddr*)&address , \
                        (socklen_t*)&addrlen);
                    printf("Cliente desconectado , ip %s , port %d \n" ,
                           inet_ntoa(address.sin_addr) , ntohs(address.sin_port));

                    //Close the socket and mark as 0 in list for reuse
                    run=FALSE;
                    close( sd );
                    client_socket[i] = 0;
                }

                    //Echo back the message that came in
                else
                {

                    //se eliminan dos caracteres nulos del buffer;

                    std::string m=buffer;
                    std::string n="\n";
                    std::string s(m.substr(0,valread-1));
                    const char * json= s.c_str();
                    std::cout<<valread;
                    validate(json);
                    std::cout<<json;

                    Send((s+n).c_str());





                }
            }
        }
    }
}

long server:: Send(const char * msg){
    for(int i=0;i<max_clients;i++) {
        send(client_socket[0], msg, strlen(msg), 0);
    }
}

long server::Send2(const char *msg) {
    for(int i=0;i<max_clients;i++) {
        send(client_socket[1], msg, strlen(msg), 0);
    }
}
