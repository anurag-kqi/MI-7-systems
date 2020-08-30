# the name of the target program
TARGET = sort

# other source files and the associated object files (this can be blank)
SRC	= sort.cpp
#stud_persistency.c
OBJ	= $(SRC:.cpp=.o)

# special include directories
INCLUDE = -I.

# special libraries (none for now)
LIB	=

# select the compiler and flags
CC = /usr/bin/g++
CFLAGS = -cpp

# .SUFFIXES: .c

# specify how to compile the .c files
.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $<

# if you type 'make' without arguments, this is the default
build: $(TARGET)

# specify how to compile the target
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE)  $(OBJ) $(LIB) -o $(TARGET)

# remove binaries
clean:
	rm -f $(OBJ) $(TARGET)

# remove binaries and other junk
clobber:
	make clean
	rm -f core *~
