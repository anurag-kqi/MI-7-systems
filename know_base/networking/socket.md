Topic: Socket Programming (Kishori)

Q1: What is the meaning of SOCK_STREAM in the socket system call? ans:
 - SOCK_STREAM indicates it's stream type of communication.
 - Rely on TCP
 - Stream socket: used for connection oriented communication, when reliability in connection is desired.

Q2: What does socket system call do? ans:
 - The socket system call is used to obtain a socket descriptor on both the client and the server.
 - The server and client applications use various system calls to conenct which use the basic construct called socket.
 - Int sockfd = socket(int domain, int type, int protocol)

Q3: What is htons()
 -The htons function takes a 16-bit number in host byte order and returns a 16-bit number in network byte order used in TCP/IP networks.
 -The htons function can be used to convert an IP port number in host byte order to the IP port number in network byte order.

Q3.1: What is host byte order and what is network byte order?
- 

Q4: What is bind()
 -When a socket has both an IP address and a port number it is said to be bound. A bound socket can receive data because it has a complete address.
 -The process of allocating a port number to a socket is called ‘binding’.
 - Bind is used only at server to bind the specific IP and port

Q5: What is accept()
 -The accept() function accepts a connection on a socket.
 -An incoming connection is acknowledged and associated with an immediately created socket.
 -The original socket is returned to the listening state.
 - Accept call blocks until client makes a connection

Q6. What is connect()
 -For stream sockets, the connect() call attempts to establish a connection between two sockets.
 -For datagram sockets, the connect() call specifies the peer for a socket.
 -It completes the binding necessary for a stream socket.
 -It attempts to make a connection to another socket.

Q7. What is listen()
 - At this point, socket is already bound to specific ip/port, but has not started accepting connection. 
 - Listen will change the socket status and now socket will start accepting connection 
 - The listen() function marks a connection-mode socket specified by the socket argument s, as accepting connections.
 - limits the number of outstanding connections in the socket's listen queue to the value specified by the backlog argument.
 - The socket is is put into 'passive' mode where incoming connection requests are acknowledged and queued pending acceptance by the process.

Q8. Why there are multiple sockets in server w/s there is only one socket in the client?
 -To handle requests from more than one client at a time server used multiple socket.
 -Client has to be make connection with only single server at a time so it use only one socket.

Q9. How does a server manages communication with multiple clients?
 -The simple way to handle multiple clients would be to spawn new thread for every new client connected to the server.
 -This method is strongly not recommended because of various disadvantages, namely:

    Threads are difficult to code, debug and sometimes they have unpredictable results.
    Overhead switching of context
    Not scalable for large number of clients
    Deadlocks can occur

 -A better way to handle multiple clients is by using select() linux command.

    Select command allows to monitor multiple file descriptors, waiting until one of the file descriptors become active.
    For example, if there is some data to be read on one of the sockets select will provide that information.
    Select works like an interrupt handler, which gets activated as soon as any file descriptor sends any data.

