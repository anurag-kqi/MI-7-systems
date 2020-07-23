/*server client design of society management systems*/

system call:
A.server:
  .socket()
  .bind()
  .listen()
  .accept()

B.client:
  .socket()
  .connect()

function:
client:

A.menu
  1.insert
  2.display
  3.search
  4.update
  5.delete
  6.exit

B.choice:1

server:
A. accept choice 1

B.ask client to enter next choice.

client:
A.submenu
  1.society data
  2.maintenance data
  3.visitors data
  4.complaints data

B.send(choice:1)

server:
A.receive(choice:1)
B.ask client to enter data.

client:
A.entities
  1.owner_name
  2.flat_num
  3.owner_contact
send (entities)

server:
A.receive(aaa, 101, 9378456985)
B.put these data in hashtable and in text file.

client:
A.menu
  1.insert
  2.display
  3.search
  4.update
  5.delete
  6.exit

B.choice:2
  .If client wants to insert data again then above process will itterate.

server:
A. accept choice 2
B.ask client to enter next choice.

client:
A.submenu
  1.society data
  2.maintenance data
  3.visitors data
  4.complaints data

B.send(choice:1)

server:
A.accept(choice:1)
B.display hashtable data to client.

client:

















server:

A.
