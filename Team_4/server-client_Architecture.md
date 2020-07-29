
Hospital Management System:

*CLIENT-SERVER Architecture

Client-server architecture for Hospital Management System architecture of a computer network in which many clients (remote processes) request and receive service from a centralized server (host computer). Client computers provide an interface to allow a computer user to request services of the server and to display the results the server returns. Server waits for requests to arrive from clients and then respond to them. Ideally, a server provides a standardized transparent interface to clients so that clients need not be aware of the specifics of the system that is providing the service. Clients are often situated at workstations or on personal computers, while servers are located elsewhere on the network, usually on more powerful machines.
In hospital management system data processing, for example, a client computer can be running an application program for patient information while the server computer is running another program that manages the database in which the information is permanently stored. Many clients can access the servers information simultaneously, and, at the same time, a client computer can perform other tasks, such as sending e-mail. Because both client and server computers are considered intelligent devices, the client-server model is completely different from the old mainframe model, in which a centralized mainframe computer performed all.

SERVER Architecture

1. ASKING PORT NUMBER 
2. SHOW ON SERVER SIDE 
	1. HOSPITAL MANAGEMENT SYSTEM 
	2. CLIENT ADDED ENTRY TO THE SERVER : ID, NAME, AGE,BLOODGROUP, ADDRESS, CONTACT, DISEASES //DATA ADDED SERVER RECEIVED DATA FROM 		  CLIENT 
3. SERVER LISTEN AND SEND DISPLAYING DATA //DIPLAYING DATA 
4. SERVER LISTEN AND SEND DELETE THE ENTRY MESSAGE //DELETE ENTRY FROM DATA 
5. SERVER LISTEN AND SEND ID INFORMATION //OLD ID AND SEND AND ACCEPT UPDATED INFORMATION SERVER RECIVED UPDATED DATA 
6. SERVER LISTEN AND SEND ID INFORMATION //SEARCH/*server client design of Hospital management systems*/

Client Architecture 
1. ASKING IP ADDRESS AND PORT NUMBER 
2. SHOW ON CLIENT SIDE 
1. HOSPITAL MANAGEMENT SYSTEM 
	1. PATIENT DATA 
	2. DOCTER DATA 
	3. EXIT
2. ENTER YOUR CHOICE (1-3)
3. INSERT INTO 
			1.ADD ENTRY
			2.DISPLAY DATA
			3.SEARCH ENTRY
			4.UPDATE ENTRY
			5.DELETE ENTRY
			6.EXIT 
4. Enter your choice to insert (1-6): 
5. ADD PATIENT INFORMATION 
	1. Enter ID 
	2. Enter Name 
	3. Enter Age 
	4. Enter Bloodgroup 
	5. Enter Address 
	6. Enter Contact
	7. DISEASES 
7. CLIENT SEND DATA TO THE SERVER://AFTER ADDING ALL DATA
	 
6. SHOW ON CLIENT SIDE

            1.DISPLAY DATA
	          	1.ADD ENTRY
			2.DISPLAY DATA
			3.SEARCH ENTRY
			4.UPDATE ENTRY
			5.DELETE ENTRY
			6.EXIT
            2.Enter your choice to display (1-6): \\CLIENT REQUEST TO THE SERVER FOR DISPLAYING DATA
7.SHOW ON CLIENT SIDE
      		1. PATIENT DATA
			1.ADD ENTRY
			2.DISPLAY DATA
			3.SEARCH ENTRY
			4.UPDATE ENTRY
			5.DELETE ENTRY
			6.EXIT
	        2. Enter your choice to update (1-6):
                        1.Enter Patient ID for Search: \\CLIENT REQUESTED TO THE SERVER FOR SEARCH

8.SHOW ON CLIENT SIDE
	    1. PATIENT DATA
			1.ADD ENTRY
			2.DISPLAY DATA
			3.SEARCH ENTRY
			4.UPDATE ENTRY
			5.DELETE ENTRY
			6.EXIT
	    2. Enter your choice to update (1-6):
	         1.Enter Patient ID for Update: \\CLIENT REQUEST TO THE SERVER
                 2.Patient old Data!!!
                      	Patient Id -
      			Patient Name -
      			Age -
			Bloodgroup -
      			Patient Address -
      			Patient Contact -
			Disease - 

                 3. Patient New Data!!!

      				ID:
      				Enter New Name:
      				Enter New Age:
				Enter New Bloodgroup:
      				Enter New Address:
      				Enter New Contact:
				Enter New Disease/Symptms: \\CLIENT SEND UPDATED DATA TO THE SERVER


9.SHOW ON CLIENT SIDE
	    1. PATIENT DATA
			1.ADD ENTRY
			2.DISPLAY DATA
			3.SEARCH ENTRY
			4.UPDATE ENTRY
			5.DELETE ENTRY
			6.EXIT

	    2.Enter your choice to delete (1-6):

		      1.Enter Patient ID for Delete: \\CLIENT REQUEST TO THE SERVER FOR DELETE ENTRY

                      2.ID NUMBER DELETED SUCCESSFULLY



10.  SHOW ON CLIENT SIDE
       		1. PATIENT DATA
			1.ADD ENTRY
			2.DISPLAY DATA
			3.SEARCH ENTRY
			4.UPDATE ENTRY
			5.DELETE ENTRY
			6.EXIT


Server-side code will look like following: - read operation: What operation to perform - based on the operation value, server knows if it needs more data from client or not. If more data needed, read the extra data from client. - perform the operations - write the result data back to client
Client-side code will look like following: - menu taking input - write to server what operation to perform - write to server any extra data needed for the operation - wait for the data from server - display the data - wait in the menu



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
  1.Patient department
  2.Doctor department
  3.Exit
B.send(choice:1)

SERVER:
A.	Accept choice 1
B.	Ask client to enter next choice.

CLIENT:
A.submenu
  1.Insert patient data
  2.Display data
  3.search data
  4.update data
  5.Delete data
B.send(choice:1)

SERVER:
A.receive(choice:1)
B.ask client to enter data.

CLIENT:
A.entities
  1.Patient_ID:
  2.Patient_name:
  3.Patient_age:
  4.patient bloodgroup:
  5.patient address:
  6.patient contact:
  7.Disease symtmps:
B.send (entities)

SERVER:
A.receive(101,ABC,20,B+,Pune,523698,fever)
B.put these data in hashtable and in text file.
C.write the result back to client

CLIENT:
A.submenu
  1.insert data
  2.display data
  3.search data
  4.update data
  5.delete data
  6.exit
B.send(choice: 2)
  NOTE: If client wants to insert data i.e. (choice: 1) again then above process will iterate.

SERVER:
A. accept choice 
B.ask client to enter next choice.

CLIENT:
A.submenu
  1.insert data
  2.display data
  3.search data
  4.update data
  5.delete data
  6.exit
B.send(choice:2)

SERVER:
A.accept(choice:2)
B.display data to client.

CLIENT:
A.requested data
    1. 101 ABC 20 B+ Pune 12345 fever
    2. 102 XYZ 21 A+ Pune 78945 none
    3. 103 PQR 22 O+ Pune 56784 cold

B.submenu
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
B. ask client to patient id

CLIENT:
A.enter patient ID:102
B.send(Patient_ID)

SERVER:
A.accept(patient_id)
    server will search data from file and send it to client
B.send(details)

CLIENT:
A.requested data
    index      : 1
    ID	 :   102
    name      : XYZ 
    age :  21 
    bloodgroup:  A+ 
    address: Pune 
    contact:  78945
    symtmps: none
B.submenu
  1.insert
  2.display
  3.search
  4.update
  5.delete
  6.exit
c.send(choice: 4)
NOTE: If client wants to search data i.e. (choice: 3) again then above process will iterate.

SERVER:
A.accept(choice: 4) to update data 
B.ask client to enter ID to find details and update the record for that ID.

CLIENT:
A.enter ID: 102
B.send(ID)

SERVER:
A.accept(ID)
B.search for ID details once found,  send it to client.
C.ask client to enter record to update.

CLIENT:
A.requested data
    ID	 :   102
    name      : XYZ 
    age:  21 
    bloodgroup:  A+ 
    address: Pune 
    contact:  78945
    symtmps: none
B.enter new record to update:
    ID	 :   102
    name      : ASH
    age:  23 
    bloodgroup:  A+ 
    address: Pune 
    contact:  78945
    symtmps: none
C.send(new record)

SERVER:
A.accept(new record)
B.update (new record) to file and hashtable.
C.ask client to select next choice.

CLIENT:
A.submenu
  1.insert data
  2.display data
  3.search data
  4.update data
  5.delete data
  6.exit
c.send(choice: 5)
NOTE: If client wants to update data i.e. (choice: 4) again then above process will iterate.

SERVER:
A.accept(choice: 5)
B.ask client to enter ID to delete the record for that particular ID.

CLIENT:
A.enter ID: 102
B.send(ID)

SERVER:
A.accept(ID) to delete the record for that particular ID.
B.finds the record for that ID and delete the record, and updates in file.
C.ask client to enter next choice.

CLIENT:
A.menu
  1.insert data
  2.display data
  3.search data
  4.update data
  5.delete data
  6.exit
NOTE: If client wants to delete data i.e. (choice: 5) again then above process will iterate.
c.send(choice: 6)

SERVER:
A. accept choice 6
B. ask client to enter next choice.

CLIENT:
A. Main menu
  1.Patient department
  2.Doctor department
  3.Exit
B.send(choice:2)

SERVER:
A.	Accept choice 2
B.	Ask client to enter next choice.

CLIENT:
A.submenu
  1.Insert Doctor data
  2.Display data
  3.search data
  4.update data
  5.Delete data
B.send(choice:1)

SERVER:
A.receive(choice:1)
B.ask client to enter data.

CLIENT:
A.entities
  1.Patient_ID:
  2.Patient_name:
  3.patient address:
  4.patient contact:
B.send (entities)

SERVER:
A.receive(501,ABC, Pune,523698)
B.put these data in hashtable and in text file.
C.write the result back to client

CLIENT:
A.submenu
  1.insert data
  2.display data
  3.search data
  4.update data
  5.delete data
  6.exit
B.send(choice: 2)
  NOTE: If client wants to insert data i.e. (choice: 1) again then above process will iterate.

SERVER:
A.accept(choice:2)
B.display data to client.

CLIENT:
A.requested data
    1. 501 Dr. Basu   Pune 12345
    2. 502 Dr. Shinde Pune 45612
    3. 503 Dr. Jadhav Pune 56784 

B.submenu
  1.insert data
  2.display data
  3.search data
  4.update data
  5.delete data
  6.exit
c.send(choice: 3)
NOTE: If client wants to display data i.e. (choice: 2) again then above process will iterate.

SERVER:
A.accept(choice: 3) to search data
B. ask client to doctor id

CLIENT:
A.enter doctor ID: 501
B.send(Doctor_ID)

SERVER:
A.accept(doctor_id)
    server will search data from file and send it to client
B.send(details)

CLIENT:
A.requested data
    index       : 2
    ID	 :   501
    name      : Dr. Basu 
    address : Pune 
    contact :  12345
B.submenu
  1.insert
  2.display
  3.search
  4.update
  5.delete
  6.exit
c.send(choice: 4)
NOTE: If client wants to search data i.e. (choice: 3) again then above process will iterate.

SERVER:
A.accept(choice: 4) to update data 
B.ask client to enter ID to find details and update the record for that ID.

CLIENT:
A.enter ID: 502
B.send(ID)

SERVER:
A.accept(ID)
B.search for ID details once found,  send it to client.
C.ask client to enter record to update.

CLIENT:
A.requested data
    ID	 :   502
    name      :Dr. Shinde
    address: Pune 
    contact:  12345
B.enter new record to update:
    ID	 :   502
    name      : Dr. Pawar
    address: Pune 
    contact:  32145
C.send(new record)

SERVER:
A.accept(new record)
B.update (new record) to file and hashtable.
C.ask client to select next choice.

CLIENT:
A.submenu
  1.insert data
  2.display data
  3.search data
  4.update data
  5.delete data
  6.exit
c.send(choice: 5)
NOTE: If client wants to update data i.e. (choice: 4) again then above process will iterate.

SERVER:
A.accept(choice: 5)
B.ask client to enter ID to delete the record for that particular ID.

CLIENT:
A.enter ID: 502
B.send(ID)

SERVER:
A.accept(ID) to delete the record for that particular ID.
B.finds the record for that ID and delete the record, and updates in file.
C.ask client to enter next choice.

CLIENT:
A.menu
  1.insert data
  2.display data
  3.search data
  4.update data
  5.delete data
  6.exit
NOTE: If client wants to delete data i.e. (choice: 5) again then above process will iterate.
c.send(choice: 6)

SERVER:
A. accept choice 6
B. ask client to enter next choice.
CLIENT:
A.Main menu
  1. Patient Department
  2. Doctor Department
  3. Exit
B.send(choice:3)

SERVER:
A.receive(choice:3)
B.Exit from Program.

NOTE: If client's choice is 3 to exit then the client server connection is going to be disconnect.
