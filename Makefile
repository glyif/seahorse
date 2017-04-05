all: seahorse

seahorse: seahorse.c
	gcc -Wall -pedantic -Wextra seahorse.c handle_file.c -o seahorse
