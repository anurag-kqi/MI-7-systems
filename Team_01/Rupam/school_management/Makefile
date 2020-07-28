# the name of the target program
TARGET = client
TARGET1 = server


# other source files and the associated object files (this can be blank)
SRC	=  menu-client.c school_management.c  structure.h
SRC2    =  server.c 
#stud_persistency.c
OBJ	= $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

# special include directories
INCLUDE = -I.

# special libraries (none for now)
LIB	=

# select the compiler and flags
CC = /usr/bin/gcc
CFLAGS = -g

# .SUFFIXES: .c

# specify how to compile the .c files
.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

# if you type 'make' without arguments, this is the default
build: $(TARGET)

# specify how to compile the target
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE)  $(OBJ) $(LIB) -o $(TARGET)
$(TARGET2): $(OBJ2)
	$(CC) $(CFLAGS) $(INCLUDE)  $(OBJ2) $(LIB) -o $(TARGET2)



# remove binaries
clean:
	rm -f $(OBJ) $(TARGET)

# remove binaries and other junk
clobber:
	make clean
	rm -f core *~
