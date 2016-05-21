#include "udp-output.h"


/*
struct sockaddr_in udp_server;
char   udp_buf[UDP_BUF_SIZE];
struct hostent *udp_host;
int    udp_socket, udp_port;
*/

int udp_initialize(char *host, int port){

    socket_len = sizeof(struct sockaddr_in);

    udp_host = gethostbyname(host);
    if (udp_host == NULL) {
        perror("udp-ouput module error on gethostbyname");
        return 1;
    }

    /* initialize socket */
    if ((udp_socket=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
        perror("udp-output module error on socket initialization");
        return 1;
    }

    /* initialize server addr */
    memset((char *) &udp_server, 0, sizeof(struct sockaddr_in));
    udp_server.sin_family = AF_INET;
    udp_server.sin_port = htons(port);
    udp_server.sin_addr = *((struct in_addr*) udp_host->h_addr);

    printf("udp-ouput initialized!\n");
}


int udp_send(char *message){

    /* send message */
    if (sendto(udp_socket, message, strlen(message), 0, (struct sockaddr *) &udp_server, socket_len) == -1) {
        perror("sendto()");
        return 1;
    }
}
