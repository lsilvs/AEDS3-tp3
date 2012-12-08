# Compile/Link
GCC = gcc
OPTMIZE = -g3 -O3
LIBS = -lc

#Objetos
OBJS =  src/main.c src/funcoes.c src/struct.c

# Nome do aplicativo
APPNAME = tp3

#valgrind
VALGRIND = valgrind --tool=memcheck --leak-check=yes --show-reachable=yes

#arquivos
INPUTFILE = analises.txt
OUTPUTFILE = output.txt

release: ; $(GCC) $(OPTMIZE) $(LIBS) $(OBJS) -o $(APPNAME)

clean:
	rm -rf $(APPNAME) $(OUTPUTFILE) *.o *.dSYM

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
