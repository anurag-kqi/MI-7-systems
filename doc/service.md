Exporting your service

Goal: 
- each of the module should have a server code integrated with their module
- each module should also write a client program, that will request the service
- Makefile now should build two executables for you, one for client and other one for server
- for now keep the menu with the server program only
- client program will have a separate menu, let's start with the search operation only
    - client program will read the input about the operation from the user
    - client will write on the socket the operation (int or text)
    - client will wait on read
- server program:
    - wait on the read
    - reads the request from the client
    - collects the records from the hash table, and write these records on the socket

