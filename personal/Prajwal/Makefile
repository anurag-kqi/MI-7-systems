
# the name of the target program
TARGET = client
TARGET1 = server


# other source files and the associated object files (this can be blank)
 SRC = client.c
 SRC1 = server.c

 OBJ = $(SRC:.c=.o)
 OBJ1 = $(SRC1:.c=.o)


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
all: $(TARGET) $(TARGET1) 

# specify how to compile the target
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE)  $(OBJ) $(LIB) -o $(TARGET)

$(TARGET1): $(OBJ1)
	$(CC) $(CFLAGS) $(INCLUDE)  $(OBJ1) $(LIB) -o $(TARGET1)
# remove binaries
clean:
	rm -f $(OBJ) $(OBJ1) $(TARGET) $(TARGET1)
# echo "clean all"

# remove binaries and other junk
clobber:
	make clean
	rm -f core *~
