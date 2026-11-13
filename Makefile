CC     = gcc
CFLAGS = -Wall -Wextra -std=c99

contacts: main.c fonction.c entete.h
	$(CC) $(CFLAGS) -o $@ main.c fonction.c

clean:
	rm -f contacts contacts.exe
