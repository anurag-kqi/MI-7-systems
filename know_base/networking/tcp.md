This KB is for TCP/IP protocol

Q1. What is UPD?
 -User Datagram Protocol (UDP) is a Transport Layer protocol. U
 -It is unreliable and connectionless protocol.
 -There is no need to establish connection prior to data transfer.
 -UDP use for the realtime services like computer gaming, voice or video communication, live conferences.
 -Since high performance is needed,
 -UDP permits packets to be dropped instead of processing delayed packets.
 -There is no error checking in UDP, so it also save bandwidth.
 -User Datagram Protocol (UDP) is more efficient in terms of both latency and bandwidth.

Q2. How does one transfer the data using UDP?
 ---Harshada
 -UDP is used to transfer large files accrose the internet.
 -UDP break the large file into individual packets.
 -these packets are transfered from source to destination
 -after reciving all packets at destination, packages are reconstructed and the
  file is back to its original state.

Q3. What is TCP and how it is different from UDP?
 -TCP is a connection-oriented protocol while UDP is a connectionless protocol.
 -TCP is reliable as it guarantees delivery of data to the destination router while The delivery of data to the destination cannot be guaranteed in UDP.
 -TCP provides extensive error checking mechanisms while UDP has only the basic error checking mechanism using checksums.
 -In TCP packets arrive in-order at the receiver while there is no sequencing of data in UDP.
 -TCP is comparatively slower than UDP.
 -TCP has acknowledgement for all the data while UDP does not have acknowledgement for any data.

 Q4. How does one transfer data using TCP?
 - server (socket, bind, listen, accept, read/write)
 - client (socket, connect, read/write)

 Q5. What is TCP 3way hand shake protocol?
  ---Aishwarya
  - TCP 3way is a process which is used in TCP/IP network.
  - This process is used to establish a connection between client and server.
  - This is a three step process.
    1. SYN - used to establish a connection.
    2. ACK - used to confirm that SYN received msg or not.
    3. SYN-ACK - SYN means the message from local side and ACK is the packet.
  - It requires both client and server which can used to exchange the synchronization and 
    acknowledgement packets.

 Q6. How TCP coonection is teared down?

 Q7. What are the well known ports? And how does one find them?

 Q8. What are the registered ports ranges?

 Q9. What is dynamic / ephemeral ports?

 Q10. Given a socket, how can I find the associated port number?
