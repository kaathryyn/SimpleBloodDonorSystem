#makefile for generating main.out

CC = gcc
CFLAGS = -Wall -Werror -ansi -lm

#Execute in terminal - make main.out
main.out: main.o encryption.o fileSys.o general.o patientEval.o splashScreen.o
	$(CC) $(CFLAGS) -o main.out main.o encryption.o fileSys.o general.o patientEval.o splashScreen.o

main.o: main.c main.h
	$(CC) $(CFLAGS) -c -o main.o main.c

encryption.o: encryption.c encryption.h
	$(CC) $(CFLAGS) -c -o encryption.o encryption.c

fileSys.o: fileSys.c main.h
	$(CC) $(CFLAGS) -c -o fileSys.o fileSys.c

general.o: general.c general.h
	$(CC) $(CFLAGS) -c -o general.o general.c

patientEval.o: patientEval.c main.h
	$(CC) $(CFLAGS) -c -o patientEval.o patientEval.c

splashScreen.o: splashScreen.c splashScreen.h
	$(CC) $(CFLAGS) -c  -o splashScreen.o splashScreen.c

#Execute in terminal - make clean
clean:
	rm main.o encryption.o fileSys.o general.o patientEval.o splashScreen.o main.out
