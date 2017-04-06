CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic
LIBS=
EXENAME=seahorse

CFILES=\
	delete_args.c\
	handle_c_file.c\
	handle_h_file.c\
	is_file.c\
	c_line_helper.c\
	generate_author.c\
	handle_c_line.c\

GLOBAL_HEADERS=\
	header.h

# Make goals
all: $(GLOBAL_HEADERS) $(CFILES) main.c
	$(CC) $(CFLAGS) $(CFILES) main.c -o $(EXENAME) $(LIBS)

debug: $(GLOBAL_HEADERS) $(CFILES) main.c
	$(CC) $(CFLAGS) $(OFILES) main.c -o $(EXENAME) $(LIBS) -g

clean:
	rm -f $(EXENAME)
