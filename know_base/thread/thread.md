Q1. Given that you can multiple processes, why do you need threads?
- our requirement is to support multiple clients, that means multiple connectionles.
- we know how to create multiple clients, using fork and exec
- but fork will not work to create multiple connections, why?
    - on the server side, you have a single hash table
    - you want all the indepent clients to modify the same state on the server
    - but you want multiple client connection:
        server:
            - socket
            - bind
            - listen
            - accept, gives a new socket for each client connection
                - on this socket you do read/write, mostly waiting for a msg from client on read
        - first client is connected by the server on the accept call
        - but now server is not waiting in the accept call, it is waiting for the message on the read from the first client
        - you want server to do multiple things in parallel
            - server to read the requests from first client
            - server should also be waiting in the accept call to accept new connections
Q2. What is a thread?
- is a mechanism to allow multiple parallel activities in the process

Q3. What are good use cases for the threads, give some example of benefits of using threads?

Q4. Are there any advantages of multi threading / multi processing in a sysmtem with only 1 processor (uni-processor system)?

Q5. Building with pthread_thread gives error?
- Need to link your program with -l pthread
    - pthread is not part of standard libc, need to link with this library

Q6. Write some sample thread create program, put some while loop, and print time stamps?

Q7. Take an input as argument and create that many threads in parallel?

Q8. How many threads of execution are there in a program with 2 calls of pthread_create?

Q9. Let's try to understand the problem of interleaved execution.
- There are two threads, operating on the same memory location (variable).
- initial value = 0
- Thread1 is read, modifies (5), writes
- Thread2 is read, modifies (10), writes
- ScenariRead2, o1:
    - Lk1, Read1, modify1, write1, Unlk1, Lk2, Read2, modify2, write2, unlk2: count = 15
    - Read1, Modify1, Read2, write1, modify2, write2: count = 15
    - Read1, Read2, Modify1, write1, modify2, write2: count = 10
    - Read1, Read2, Modify1, modify2, write2, write1: count = 5
