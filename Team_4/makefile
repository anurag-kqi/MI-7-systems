CC=g++

CFLAGS=-c -wall


all: Hsm

Hsm: HSM.o patient.o doctor.o
	$(CC) HSM.o patient.o doctor.o -o Hsm

HSM.o: HSM.c
	$(CC) $(CFLAGS) HSM.c

patient.o: patient.c
	$(CC) $(CFLAGS) patient.c

doctor.o: doctor.c
	$(CC) $(CFLAGS) doctor.c

clean:
	rm -rf *o Hsm
