FLAGS=`root-config --libs --cflags`

all: cmc

cmc: bin/cmc

test: bin/test

bin/cmc: bin lib lib/CmcMaker.o main.cxx
	@echo "Compiling..."
	g++ main.cxx lib/CmcMaker.o $(FLAGS) -o bin/cmc
	@echo "Done!"

bin/test: bin lib lib/CmcMaker.o test.cxx
	@echo "Compiling..."
	g++ test.cxx lib/CmcMaker.o $(FLAGS) -o bin/test
	@echo "Done!"

lib/CmcMaker.o:
	g++ src/CmcMaker.cxx  $(FLAGS) -c -o lib/CmcMaker.o

lib:
	@mkdir lib

bin:
	@mkdir bin

help:
	@echo "##USAGE##"
	@echo "make            -> Compile CMC program (main.cxx)."
	@echo "make test       -> Compile a simple test program of CMC (test.cxx)."
	@echo "make help       -> Show the help information."
	@echo "make clean      -> Clean the libraries and binary files."

clean:
	@echo "Cleaning..."
	@rm -rf bin lib
	@echo "Done!"