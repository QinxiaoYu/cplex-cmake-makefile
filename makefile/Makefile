# Compiler options
CC=g++
CFLAGS=-W -Wall -ansi -pedantic -std=c++11

# Project files
EXEC=main
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.c=.o)

# Cplex configuration
SYSTEM     = x86-64_osx
LIBFORMAT  = static_pic
CPLEXDIR=/Users/realopt/Applications/IBM/ILOG/CPLEX_Studio127/cplex/
CONCERTDIR =/Users/realopt/Applications/IBM/ILOG/CPLEX_Studio127/concert/
CPLEXBINDIR   = $(CPLEXDIR)/bin/$(SYSTEM)
CPLEXLIBDIR   = $(CPLEXDIR)/lib/$(SYSTEM)/$(LIBFORMAT)
CONCERTLIBDIR = $(CONCERTDIR)/lib/$(SYSTEM)/$(LIBFORMAT)
CPLEXBINDIR   = $(CPLEXDIR)bin/$(SYSTEM)
CPLEXLIBDIR   = $(CPLEXDIR)lib/$(SYSTEM)/$(LIBFORMAT)
CONCERTLIBDIR = $(CONCERTDIR)lib/$(SYSTEM)/$(LIBFORMAT)
CCLNFLAGS = -L$(CPLEXLIBDIR) -lilocplex -lcplex -L$(CONCERTLIBDIR) -lconcert -lm -lpthread
CONCERTINCDIR = $(CONCERTDIR)include
CPLEXINCDIR   = $(CPLEXDIR)include
CCFLAGS = $(CFLAGS) -DIL_STD -I$(CPLEXINCDIR) -I$(CONCERTINCDIR) -w

default: $(EXEC)

main: $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $^ $(CCLNFLAGS)

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

clean:
	rm -rf *.o