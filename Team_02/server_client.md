/*server client design of society management systems*/

system call:
A.SERVER:
  .socket()
  .bind()
  .listen()
  .accept() //blocks until connection from client

B.CLIENT:
  .socket()
  .connect() //establish connection to server

function:
CLIENT:
A.menu
  1.insert
  2.display
  3.search
  4.update
  5.delete
  6.exit
B.send(choice:1)

SERVER:
A. accept choice 1
B.ask client to enter next choice.

CLIENT:
A.submenu
  1.society data
  2.maintenance data
  3.visitors data
  4.complaints data
B.send(choice:1)

SERVER:
A.receive(choice:1)
B.ask client to enter data.

CLIENT:
A.entities
  1.owner_name
  2.flat_num
  3.owner_contact
B.send (entities)

SERVER:
A.receive(aaa, 101, 9378456985)
B.put these data in hashtable and in text file.

CLIENT:
A.menu
  1.insert
  2.display
  3.search
  4.update
  5.delete
  6.exit
B.send(choice: 2)
  NOTE: If client wants to insert data i.e. (choice: 1) again then above process will iterate.

SERVER:
A. accept choice 2
B.ask client to enter next choice.

CLIENT:
A.submenu
  1.society data
  2.maintenance data
  3.visitors data
  4.complaints data

B.send(choice:1)

SERVER:
A.accept(choice:1)
B.display data to client.

CLIENT:
A.requested data
    1. 101 AAA 1234
    2. 102 BBB 3456
    3. 103 CCC 5678

B.menu
  1.insert
  2.display
  3.search
  4.update
  5.delete
  6.exit
c.send(choice: 3)
NOTE: If client wants to display data i.e. (choice: 2) again then above process will iterate.

SERVER:
A.accept(choice: 3) to search data
B.ask client to select next choice

CLIENT:
A.submenu
  1.society data
  2.maintenance data
  3.visitors data
  4.complaints data
B.send(choice: 1)

SERVER:
A.accept(choice: 1) to search data from society data
B.ask client to enter flat num.

CLIENT:
A.enter flat_num:102
B.send(flat_num)

SERVER:
A.accept(flat_num)
    server will search data from file and send it to client
B.send(details)

CLIENT:
A.requested data
    index           : 1
    flat_num        : 102
    owner_name      : BBB
    owner_contact   : 3456
B.menu
  1.insert
  2.display
  3.search
  4.update
  5.delete
  6.exit
c.send(choice: 4)
NOTE: If client wants to search data i.e. (choice: 3) again then above process will iterate.

SERVER:
A.accept(choice: 4)
B.ask client to select next choice from submenu.

CLIENT:
A.submenu
  1.society data
  2.maintenance data
  3.visitors data
  4.complaints data
B.send(choice: 1)

SERVER:
A.accept(choice: 1) to update data from society data
B.ask client to enter flat_num to find details and update the record for that flat_num.

CLIENT:
A.enter flat_num: 102
B.send(flat_num)

SERVER:
A.accept(flat_num)
B.search for flat_num details once found,  send it to client.
C.ask client to enter record to update.

CLIENT:
A.requested data
    flat_num        : 102
    owner_name      : BBB
    owner_contact   : 3456
B.enter new record to update:
    flat_num        : 102
    owner_name      : NEW
    owner_contact   : 9999
C.send(new record)

SERVER:
A.accept(new record)
B.update (new record) to file and hashtable.
C.ask client to select next choice.

CLIENT:
A.menu
  1.insert
  2.display
  3.search
  4.update
  5.delete
  6.exit
c.send(choice: 5)
NOTE: If client wants to update data i.e. (choice: 4) again then above process will iterate.

SERVER:
A.accept(choice: 5)
B.ask client to enter flat_num to delete the record for that particular flat_num.

CLIENT:
A.enter flat_num: 102
B.send(flat_num)

SERVER:
A.accept(flat_num) to delete the record for that particular flat_num.
B.finds the record for that flat_num and delete the record, and updates in file.
C.ask client to enter next choice.

CLIENT:
A.menu
  1.insert
  2.display
  3.search
  4.update
  5.delete
  6.exit
NOTE: If client wants to delete data i.e. (choice: 5) again then above process will iterate.
c.send(choice: 6)
NOTE: If client's choice is 6 to exit then the client server connection is going
      to be disconnect.
