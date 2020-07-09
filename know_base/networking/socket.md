Topic: Socket Programming

Q1: What is the meaning of SOCK_STREAM in the socket system call?
ans:
	- SOCK_STREAM indicates it's stream type of communication.
	- Rely on TCP
	- stream socket: used for connection oriented communication, when reliability in connection is desired.

Q2: What does socket system call do?
ans:
	- The socket system call is used to obtain a socket descriptor on both the client and the server.
	- The server and client applications use various system calls to conenct which use the basic construct called socket.
	- int sockfd = socket(int domain, int type, int protocol)

Q3: What is htons()


Q4: What is bind()


Q5: What is accept()


Q6. What is connect()


Q7. What is listen()


Q8. Why there are multiple sockets in server w/s there is only one socket in the client?


Q9. How does a server manages communication with multiple clients?

