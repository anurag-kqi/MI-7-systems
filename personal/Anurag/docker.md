What is Docker?
- tool to manage containers
- tool to create Virtual machine
- containerization tool
- deploy any kind of app easily on any platform
- orchestration of containers
- docker uses union file system that is a layered file system
- docker is deploy, ship and run code any where
- docker no pre-allocation of RAM
- platform indepent, work any where
- easy to install as compared to Linux
- reuse same machine / image many times

New Terms:
- container
- VM
- orchestration
- run anywhere
- deploy
- ship
- run
- images

Three phases in software distribution

1. Build
2. Deploy
3. Run

Build:
4 different are being built:
1. School management
2. Business management
3. Society management
4. Hospital management

Process of creating executable, is build process.
- 4 executable
- dev - test
Executables / packages is the end result of this phase.

Once software is ready, how will client use the software:
- can it run on your laptop?
- Deployed some where:
  - desktop / laptop software:
    apt-get install ??
    tar file, shell, execute
  - client / server deployment:
    - we can install the software in every machine
    - Data will not be synchronized
    - server: software and data
      - client software can run on different machines

School management software:
- desktop version of the software
- to make multiple people using the software, you need a client server version of the SMS:
  - need to divide software into two parts:
    - server: (only one copy of server running on a server machine)
      - hash table, persistent layer
    - client
      - CLI menu can be run in the client
      - client should be able to talk to server and make the request
      - Get the response from the server and display the results to the user
      - Mulitple copies of client can be run
- Web application is a good example of client server architecture
- browser  becomes the client, web server is on the other side
- http is client/server protocol
   - client is chrom browser
   - server is google.com
     - a large number of services it will provide (URI): Search is service
     - request details (Searching for "Shaniwarwada in Pune")
   - server:
    - receives your request
    - is it a valid request?
      - invalid request (400)
    - serve your request, it will response
    - response back, successfully handled request
    - brower needs to process this response and render the web page in the client

School management program:
1. server: Hash table, persistency layer, list of services 8 services
2. client: menu from user, it needs to make a service request call with server
   - server will either respond with error or success, if sucess then client needs to display the data to the user on CLI

10-12 people might use the scm software
20 requets per person per day, 200-400 request / day

What is your guess on number of users, 1000,000. 1000,000,0000 people. 10Billions of requests per day. 
