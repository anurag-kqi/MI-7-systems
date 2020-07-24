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

  --Shankar

   - TCP 3-way handshake is a process which is used in a TCP/IP network to make a connection between the server and client.
     It is a three-step process that   requires both the client and server to exchange synchronization and acknowledgment
     packets before the real data communication process starts.

   - TCP Three-Way Handshake Process
     - TCP traffic begins with a three-way handshake. In this TCP handshake process,
       a client needs to initiate the conversation by requesting a communication session with the Server:
         - Step 1: In the first step, the client establishes a connection with a server.
           It sends a segment with SYN and informs the server about the client should start communication,
           and with what should be its sequence number.

        - Step 2: In this step server responds to the client request with SYN-ACK signal set.
          ACK helps you to signify the response of segment that is received and SYN signifies what
          sequence number it should able to start with the segments.

        - Step 3: In this final step, the client acknowledges the response of the Server,
          and they both create a stable connection will begin the actual data transfer process.

 Q6. How TCP conection is teared down?

 Q7. What are the well known ports? And how does one find them?

 --Shankar

 how to find port
 https://www.purevpn.com/what-is-my-ip/port-number

 Port numbers range from 0 to 65535, but only port numbers 0 to 1023 are reserved for privileged services and designated as well-known ports.
 The following list of well-known port numbers specifies the port used by the server process as its contact port.

 https://en.wikipedia.org/wiki/List_of_TCP_and_UDP_port_numbers#Well-known_ports

Q8. What are the registered ports ranges?

--Shankar
- Port numbers above 1023 can be either registered or dynamic (also called private or non-reserved).
Registered ports are in the range 1024 to 49151. Dynamic ports are in the range 49152 to 65535. As mentioned,
most new port assignments are in the range from 1024 to 49151.

Registered port numbers are non–well-known ports that are used by vendors for their own server applications.
After all, not every possible application capability will be reflected in a well-known port, and software vendors
should be free to innovate. Of course, if another vendor chooses the same port number for a server process,
and they are run on the same system,there would be no way to distinguish between these two seemingly identical applications.

▪ Well-known ports— Ports in the range 0 to 1023 are assigned and controlled.
▪ Registered ports— Ports in the range 1024 to 49151 are not assigned or controlled, but can be registered to prevent duplication.
▪ Dynamic ports— Ports in the range 49152 to 65535 are not assigned, controlled, or registered. They are used for temporary or private ports.
They are also known   as private or non-reserved ports. Clients should choose ephemeral port numbers from this range, but many systems do not.

 Q9. What is dynamic / ephemeral ports?

 Q10. Given a socket, how can I find the associated port number?

 Q11. If server is busy getting  data from first client, then how will server accept the second connection?
A: For every connection, server should start a new process. 
