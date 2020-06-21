
# the name of the target program
TARGET = hms

# other source files and the associated object files (this can be blank)
SRC	= HSM.c patient.c doctor.c
OBJ	= $(SRC:.c=.o)

# special include directories
INCLUDE = -I.

# special libraries (none for now)
LIB	=

# select the compiler and flags
CC = /usr/bin/gcc
CFLAGS = -g

# .SUFFIXES: .c



# remove binaries
clean:
	rm -f $(OBJ) $(TARGET)

# remove binaries and other junk
clobber:
	make clean
	rm -f core *~


