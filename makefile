# Compile/Link
GCC = gcc
OPTMIZE = -g3 -O3
LIBS = -lc

#Objetos
OBJS =  src/main.c src/funcoes.c

# Nome do aplicativo
APPNAME = tp3

#valgrind
VALGRIND = valgrind --tool=memcheck --leak-check=yes --show-reachable=yes

#arquivos
INPUTFILE = input.txt
OUTPUTFILE = output.txt

release: ; $(GCC) $(OPTMIZE) $(LIBS) $(OBJS) -o $(APPNAME)

clean:
	rm -f $(APPNAME1) $(APPNAME2) $(OUTPUTFILE1) $(OUTPUTFILE2) *.o

run:
	make
	./$(APPNAME) $(INPUTFILE) $(OUTPUTFILE)


test:
	make
	./$(APPNAME1) $(INPUTFILETEST) $(OUTPUTFILE)
	

time:
	make
	time ./$(APPNAME1) $(INPUTFILE) $(OUTPUTFILE1)

analysis:
	make
	$(VALGRIND) ./$(APPNAME1) $(INPUTFILE) $(OUTPUTFILE1)
