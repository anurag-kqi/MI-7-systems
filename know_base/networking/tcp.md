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
- 

Q3. What is TCP and how it is different from UDP?
 -TCP is a connection-oriented protocol while UDP is a connectionless protocol.
 -TCP is reliable as it guarantees delivery of data to the destination router while The delivery of data to the destination cannot be guaranteed in UDP.
 -TCP provides extensive error checking mechanisms while UDP has only the basic error checking mechanism using checksums.
 -In TCP packets arrive in-order at the receiver while there is no sequencing of data in UDP.
 -TCP is comparatively slower than UDP.

 Q4. How does one transfer data using TCP?
 - server (socket, bind, listen, accept, read/write)
 - client (socket, connect, read/write)
