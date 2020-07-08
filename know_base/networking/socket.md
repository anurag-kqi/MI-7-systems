Topic: Socket Programming
Q1: What is the meaning of SOCK_STREAM in the socket system call?
ans:(Prajwal):
	- SOCK_STREAM indicates it's stream type of communication.
	- Rely on TCP
	- stream socket: used for connection oriented communication, when reliability in connection is desired.

Q2: What does socket system call do?
ans:(Prajwal):
	- The socket system call is used to obtain a socket descriptor on both the client and the server.
	- The server and client applications use various system calls to conenct which use the basic construct called socket.
	- int sockfd = socket(int domain, int type, int protocol)

Q3: What is htons()
