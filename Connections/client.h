
#ifndef QUERYEXECUTOR_CLIENT_H
#define QUERYEXECUTOR_CLIENT_H


class client {
    int MAX_SIZE=50;
    int sock_desc;
public:
    void start();
    long Send(const char*  msg);
};


#endif //QUERYEXECUTOR_CLIENT_H
