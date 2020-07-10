TARGET = socm


# other source files and the associated object files (this can be blank)
<<<<<<< HEAD
 SRC = society.c maintenance.c  visitors.c complaints.c menu.c 
=======
 SRC = society.c maintenance.c  visitors.c complaints.c menu.c
>>>>>>> 1809af629eccceded4b723fc319562b3d6bb446d
 OBJ = $(SRC:.c=.o)


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
all: $(TARGET)

# specify how to compile the target
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE)  $(OBJ) $(LIB) -o $(TARGET)

	# remove binaries
clean:
	rm -f $(OBJ) $(TARGET)
	# echo "clean all"

	# remove binaries and other junk
clobber:
	make clean
	rm -f core *~
