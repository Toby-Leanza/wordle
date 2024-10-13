CC = gcc
CFLAGS = -Wall

# Define the source files
SRCS_ED = ed.c jugador.c jugable.c
SRCS_ED2 = ed2.c jugador.c jugable.c

# Define the object files
OBJS_ED = $(SRCS_ED:.c=.o)
OBJS_ED2 = $(SRCS_ED2:.c=.o)

# Targets for building the programs
all: mainEd mainEd2

mainEd: mainEd.o $(OBJS_ED)
	$(CC) -o mainEd mainEd.o $(OBJS_ED)

mainEd2: mainEd2.o $(OBJS_ED2)
	$(CC) -o mainEd2 mainEd2.o $(OBJS_ED2)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build files
clean:
	rm -f *.o mainEd mainEd2