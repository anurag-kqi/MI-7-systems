School Management System :

*CLIENT-SERVER Architecture

Client-server architecture for school Management system architecture of a computer network
in which many clients (remote processors) request and receive service from a centralized
server (host computer). Client computers provide an interface to allow a computer user to
request services of the server and to display the results the server returns. Servers wait
for requests to arrive from clients and then respond to them.
Ideally, a server provides a standardized transparent interface to clients so that clients
need not be aware of the specifics of the system (i.e., the hardware and software) that
is providing the service. Clients are often situated at workstations or on personal computers,
while servers are located elsewhere on the network, usually on more powerful machines.
This computing model is especially effective when clients and the server each have distinct
tasks that they routinely perform. In school management syetem data processing, for example,
a client computer can be running an application program for student information while the
server computer is running another program that manages the database in which the information
is permanently stored.Many clients can access the server’s information simultaneously, and, at
the same time, a client computer can perform other tasks, such as sending e-mail. Because both
client and server computers are considered intelligent devices, the client-server model is
completely different from the old “mainframe” model, in which a centralized mainframe computer
performed all.


SERVER Architecture
      1.ASKING PORT NUMBER
      2.SHOW ON SERVER SIDE
          1.SCHOOL MANAGEMENT SYSTEM
          2.CLIENT ADDED ENTRY TO THE SERVER        : ID, NAME. CLASS. ADDRESS, CONTACT       //DATA ADDED
            SERVER RECEIVED DATA FROM CLIENT
          3.SERVER LISTEN AND SEND DISPLAYING DATA            //DIPLAYING DATA
          4.SERVER LISTEN AND SEND DELETE THE ENTRY MESSAGE   //DELETE ENTRY FROM DATA
          5.SERVER LISTEN AND SEND ID INFORMATION             //OLD ID AND SEND AND ACCEPT UPDATED INFORMATION
            SERVER RECIVED UPDATED DATA
          6.SERVER LISTEN AND SEND ID INFORMATION             //SEARCH


Client Architecture
   1.ASKING IP ADDRESS AND PORT NUMBER
   2.SHOW ON CLIENT SIDE
   		1. SCHOOL MANAGEMENT SYSTEM
			   1.ADD ENTRY
			   2.DISPLAY DATA
			   3.DELETE ENTRY
			   4.UPDATE ENTRY
			   5.SEARCH
	        2.ENTER YOUR CHOICE
	        3.INSERT INTO
			  1.STUDENT DATA
			  2.TEACHER DATA
			  3.EXIT
		4.Enter your choice to inseRT(1-3) :
    	        5.ADD STUDENT INFORMATION
			   1. Enter ID
			   2. Enter Name
			   3. Enter Class
			   4. Enter Address
			   5. Enter Contact
	  CLIENT SEND DATA TO THE SERVER

	//AFTER ADDING ALL DATA

		 6.SHOW ON CLIENT SIDE
	            1.SCHOOL MANAGEMENT SYSTEM
    		 	    1.ADD ENTRY
    			    2.DISPLAY DATA
    			    3.DELETE ENTRY
    			    4.UPDATE ENTRY
    			    5.SEARCH

                     2.DISPLAY DATA
		          1.STUDENT DATA
			  2.TEACHER DATA
			  3.EXIT
	             3.Enter your choice to display(1-3) :
    	CLIENT REQUEST TO THE SERVER FOR DISPLAYING DATA

                   7.SHOW ON CLIENT SIDE
    			1. SCHOOL MANAGEMENT SYSTEM
    			   1.ADD ENTRY
    			   2.DISPLAY DATA
    			   3.DELETE ENTRY
    			   4.UPDATE ENTRY
    			   5.SEARCH

	                2.DELETE DATA
		           1.STUDENT DATA
	         	   2.TEACHER DATA
			   3.EXIT
		        3.Enter your choice to delete(1-3) :

			   1.Enter Student iD for Delete :
          CLIENT REQUEST TO THE SERVER FOR DELETE ENTRY
        
	                  2.ID NUMBER DELETED SUCCESSFULLY

		   8.SHOW ON CLIENT SIDE
    			1. SCHOOL MANAGEMENT SYSTEM
    			   1.ADD ENTRY
    			   2.DISPLAY DATA
    			   3.DELETE ENTRY
    			   4.UPDATE ENTRY
    			   5.SEARCH

		       2.UPDATE DATA
		             1.STUDENT DATA
	                     2.TEACHER DATA
			     3.EXIT
		       3.Enter your choice to update(1-3) :
		         1.Enter Student ID for Update :
           CLIENT REQUEST TO THE SERVER
                        2.Student old Data !!!
                          Student Id -
          				Student Name -
          				Student Class -
          				Student Address -
          				Student Contact -

                        3. Student New Data !!!

          				Enter Same ID :
          				Enter New Name :
          				Enter New Class :
          				Enter New Address :
          				Enter New Contact :
				 CLIENT SEND UPDATED DATA TO THE SERVER

                   9.SHOW ON CLIENT SIDE
          		1. SCHOOL MANAGEMENT SYSTEM
          			   1.ADD ENTRY
          			   2.DISPLAY DATA
          			   3.DELETE ENTRY
          			   4.UPDATE ENTRY
          			   5.SEARCH

          		2.UPDATE DATA
		               1.STUDENT DATA
	           	     2.TEACHER DATA
			             3.EXIT
		          3.Enter your choice to update(1-3) :
                            1.Enter Student ID for Search :
          CLIENT REQUESTED TO THE SERVER FOR SEARCH

                    10.  SHOW ON CLIENT SIDE
           		  1. SCHOOL MANAGEMENT SYSTEM
           			   1.ADD ENTRY
           			   2.DISPLAY DATA
           			   3.DELETE ENTRY
           			   4.UPDATE ENTRY
           			   5.SEARCH
