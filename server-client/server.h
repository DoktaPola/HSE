#ifndef SERVER_CLIENT_SERVER_H
#define SERVER_CLIENT_SERVER_H

/* Client structure */
typedef struct {
    struct sockaddr_in address; // address
    int sockfd; // socket file descriptor
    int uid;  // user id - unique for each client
    char name[32];
} client_t;

void str_overwrite_stdout();

void str_trim_lf(char *arr, int length);

void print_client_addr(struct sockaddr_in addr);

void queue_add(client_t *cl);

void queue_remove(int uid);

void send_message(char *mess, int uid);

void *handle_client(void *arg);

#endif //SERVER_CLIENT_SERVER_H
