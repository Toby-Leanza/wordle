CC = gcc
CFLAGS = -Wall -g

# Define the source files
SRCS_ED = ed.c jugador.c jugable.c

# Define the object files
OBJS_ED = $(SRCS_ED:.c=.o)

# Targets for building the programs
all: mainEd

mainEd: mainEd.o $(OBJS_ED)
	$(CC) -o mainEd mainEd.o $(OBJS_ED)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build files
clean:
	rm -f *.o mainEd
