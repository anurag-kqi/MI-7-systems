 
CC=gcc  #compiler
TARGET=template #target file name
 
all:	functions.h main.o read.o write.o delete.o .
	$(CC) functions.h main.c read.c write.c delete.c -o $(TARGET)
 
clean:
	rm *.o $(TARGET)
