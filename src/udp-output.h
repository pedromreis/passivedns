#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define UDP_BUF_SIZE 1024

struct sockaddr_in udp_server;
char   udp_buf[UDP_BUF_SIZE];
struct hostent *udp_host;
int    socket_len, udp_socket, udp_port;

int    udp_initialize(char *host, int port);
int    udp_send(char *message);


