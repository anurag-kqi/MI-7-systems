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