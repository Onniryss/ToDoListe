INCLUDEDIR = include
SRCDIR = src
BINDIR = bin
LDFLAGS = -lc
EXEC = $(BINDIR)/main
CFLAGS = -Wall -pedantic -g


clean :
	rm -f $(BINDIR)/*
	rm -f $(SRCDIR)/*.o

all: $(EXEC)


$(EXEC) : $(SRCDIR)/main.o $(SRCDIR)/tache.o $(SRCDIR)/listeChaineeTache.o $(SRCDIR)/todo.o $(SRCDIR)/ihm.o
	gcc -o $@ $^ $(LDFLAGS)

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	gcc -o $@ -c $< $(CFLAGS) -I$(INCLUDEDIR)
