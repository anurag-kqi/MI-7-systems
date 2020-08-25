TARGET = sort

# other source files and the associated object files (this can be blank)
 SRC = bubble_sort.cpp
 OBJ = $(SRC:.cpp=.o)


# special include directories
INCLUDE = -I.

# special libraries (none for now)
LIB	=

# select the compiler and flags
CC = /usr/bin/g++
CPPFLAGS = -cpp

# .SUFFIXES: .c

# specify how to compile the .c files
.cpp.o:
	$(CC) $(CPPFLAGS) $(INCLUDE) -c $<
# if you type 'make' without arguments, this is the default
all: $(TARGET)

# specify how to compile the target
$(TARGET): $(OBJ)
	$(CC) $(CPPFLAGS) $(INCLUDE)  $(OBJ) $(LIB) -o $(TARGET)

# remove binaries
clean:
	rm -f $(OBJ) $(TARGET)
# echo "clean all"

# remove binaries and other junk
clobber:
	make clean
	rm -f core *~
