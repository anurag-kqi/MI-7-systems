Networking:
modules:
 - school
 - society
 - business
 - hospital
 - people

All modules implements few types of objects:
 - student
 - teacher
 - doctor
 - business
 ...

Opertions that can be performed on these objects are:
 - insert
 - update
 - delete
 - search

Right now, you can request these operations only from CLI driven menu.

Objective is to provide these services over the network, so that other modules can consume these services.

Q. How does two program talk to each other?
- with the same process, you make function calls to get service
- but these functions are not available outside the process
- Using APIs, we can get service
- TCP/IP using socket communication
    - How to identify whom to talk (phone number equivalent)
    - Setting up the connection
    - Transfer of the information
- Communication between multi processses on the same node
- comm between processes across multiple nodes

Resources:
- Socket programming: https://blough.ece.gatech.edu/4110/NetworkProgrammingIntro.pdf

Phase 2:
Q1: Need to now support multiple client connecting to same server
- Need to modify the server side code so that now server can accept multiple connections

- listen is going to set the connection to listen on the server socket, no change there
- put the accept in a while loop
- each accept will return a newsockfd
- create a new pthread to work on that newsockfd
- main process will continue to wait on the acccept
- pseudo code will look like following:

//server function for the pthread is going to work on only and only One
//client connection
- server_func(void *arg) {
    socketfd = (int)arg;
    .. read on that socketd...
    ... when read gives error, call pthread_exit

}

    //main process default thread is just waiting for new client connections
    //For each client connection, it is starting a new pthread
        while (1) {
            newsockfd = accept(sockfd, ...)
            if (newsockfd) < 0 .. error handling
            err = pthread_create(... , server_func, (void *)newsockfd);
            if (err < 0) error handling
        }
        printf("server should never reach here");


```
