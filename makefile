# Compile/Link
GCC = gcc
OPTMIZE = -g3 -O3
LIBS = -lc

#Objetos
OBJS1 =  src/tp2pd.c src/funcoes.c
OBJS2 =  src/tp2g.c src/funcoes.c

# Nome do aplicativo
APPNAME1 = tp2pd
APPNAME2 = tp2g

#valgrind
VALGRIND = valgrind --tool=memcheck --leak-check=yes --show-reachable=yes

#arquivos
INPUTFILE = input.txt
INPUTFILETEST = doc/test/luam/input
OUTPUTFILE1 = output1.txt
OUTPUTFILE2 = output2.txt
OUTPUTFILETEST = doc/test/output.txt

release: ; $(GCC) $(OPTMIZE) $(LIBS) $(OBJS1) -o $(APPNAME1)
	$(GCC) $(OPTMIZE) $(LIBS) $(OBJS2) -o $(APPNAME2)

clean:
	rm -f $(APPNAME1) $(APPNAME2) $(OUTPUTFILE1) $(OUTPUTFILE2) *.o

run:
	make
	./$(APPNAME1) $(INPUTFILE) $(OUTPUTFILE1)
	./$(APPNAME1) $(INPUTFILE) $(OUTPUTFILE2)

test:
	make
	./$(APPNAME1) $(INPUTFILETEST) $(OUTPUTFILE1)
	./$(APPNAME2) $(INPUTFILETEST) $(OUTPUTFILE2)
	

time:
	make
	time ./$(APPNAME1) $(INPUTFILE) $(OUTPUTFILE1)

analysis:
	make
	$(VALGRIND) ./$(APPNAME1) $(INPUTFILE) $(OUTPUTFILE1)
