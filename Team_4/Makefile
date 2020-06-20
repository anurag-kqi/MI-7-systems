

CC=gcc

CFLAGS=-c -wall


all: Hospital

Hospital: HSM.o patient.o doctor.o
	$(CC) $(CFLAGS) HSM.o patient.o doctor.o -o Hospital

HSM.o: HSM.c
	$(CC) $(CFLAGS) HSM.c

patient.o: patient.c
	$(CC) $(CFLAGS) patient.c

doctor.o: doctor.c
	$(CC) $(CFLAGS) doctor.c

clean:
	rm -rf *o Hospital

