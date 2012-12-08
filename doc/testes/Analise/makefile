# Compile/Link
GCC = gcc
OPTMIZE = -g3 -O3
LIBS = -lc

#Objetos
OBJS =  main.c funcoes.c struct.c

# Nome do aplicativo
APPNAME = 4

#valgrind
VALGRIND = valgrind --tool=memcheck --leak-check=yes --show-reachable=yes

#arquivos
INPUTFILE = $(APPNAME).txt
OUTPUTFILE = pilha$(APPNAME).txt

release: ; $(GCC) $(OPTMIZE) $(LIBS) $(OBJS) -o $(APPNAME)

clean:
	rm -rf 1 2 3 4 *.o *.dSYM

run:
	make
	./$(APPNAME) $(INPUTFILE) $(OUTPUTFILE)

test:
	make
	./$(APPNAME) $(INPUTFILETEST) $(OUTPUTFILE)

time:
	make
	time ./$(APPNAME) $(INPUTFILE) $(OUTPUTFILE)

analysis:
	make
	$(VALGRIND) ./$(APPNAME) $(INPUTFILE) $(OUTPUTFILE)
