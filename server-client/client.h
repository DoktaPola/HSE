#ifndef SERVER_CLIENT_CLIENT_H
#define SERVER_CLIENT_CLIENT_H

void str_overwrite_stdout();

void str_trim_lf(char *arr, int length);

void catch_ctrl_c_and_exit(int sig);

void send_msg_handler();

void recv_msg_handler();

#endif //SERVER_CLIENT_CLIENT_H
