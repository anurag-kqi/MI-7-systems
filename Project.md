Project for MI-7

4 Teams
Each team has 4 people- L

Skills:
- linux
- C
- Python
- Golong
- VM
- K8s
- Docker
- Microservices
- CI/CD
- Unix internals

Project Idea:

Let's build a virtual community. This community will following entities:
- Schools: Team-1
- societies: Team-2
- Business: Team-3
- Hospital: Team-4
- Theaters: Team-5

Each team is going to own first entity.  

For each entity, first we need develop basic services that each entity can provide.
For example, for schools:
- start with one school
- list of students
- list of classes
- list of teachers
- Add, update, list, delete operations

First assignment, we will be maintaining all these information only in the memory, using hash tables.

Second phase: we will being to persist these information, using files.

Third phase: we will being to use some kind of databases

4th Phase: we will convert them into micro services and create docker instances for each of these Microservices

5th phase: each of these services will start talking to each other

6th Phase: start deploying these services using k8s and start scaling them up and down

Some of these services will be written in C, some in python and some in the golang. We will also be doing test automation using python and golang.

Project Tracking:
1. 30th May: Each team gives a good demo of hash table implementation. Demo has to be menu driven. Let's use doubly link list. Keys for the each element will be int, but the value should be string. Operations that you need to support are:
- add entry
- update entry for a given Key
- delete entry
- get specific entry value
- list all the entries

By 28th May, you put together a one page text document specifying your design and data structure. 
