/* Code from Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int open_socket(char *server_ip)
{
    int d_sock, c;
    if (( d_sock = socket(PF_INET, SOCK_STREAM, 0)) == -1)
        error("Can't open socket");

    struct sockaddr_in si;
    memset(&si, 0, sizeof(si));
    si.sin_family = PF_INET;
    si.sin_addr.s_addr = inet_addr(server_ip);
    si.sin_port = htons(30000);
    c = connect(d_sock, (struct sockaddr *) &si, sizeof(si));
    if (c == -1)
        error("Can't connect to the socket");

    return d_sock;
}

int say(int socket, char *s)
{
    int result = send(socket, s, strlen(s), 0);
    if (result == -1)
        error("Can't talk to the server");

    return result;
}

int main(int argc, char *argv[])
{
    if(argc < 2){
      printf("Please enter <ip address of server>.");
      return -1;
    }
    char *ip_address = argv[1];
    int d_sock, bytes_received;
    char rec[256];

    /* connect to server */
    d_sock = open_socket(ip_address);

    /* display page on stdout in 255 byte chunks */
    bytes_received = recv(d_sock, rec, 255, 0);
    while (bytes_received) {
        if (bytes_received == EOF)
            error("can't read from server");

        rec[bytes_received] = '\0';
        printf("%s", rec);
        bytes_received = recv(d_sock, rec, 255, 0);
    }
    close(d_sock);

    return 0;
}
