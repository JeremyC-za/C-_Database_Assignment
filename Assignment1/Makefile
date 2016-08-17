#Makefile
#Jeremy Coupland
#March 1st, 2015
#Assignment 1

CPP=g++
CPPFLAGS=-std=c++11
EXE_NAME=Assignment1
	
%.o: %.cpp
	$(CPP) -c -o $@ $< $(CPPFLAGS)
	
$(EXE_NAME): main.o driver.o
	$(CPP) -o $(EXE_NAME) main.o driver.o $(CPPFLAGS)  

#Clean binaries
clean:
	@rm *.o Assignment1
#Rule to run the code
run:
	./Assignment1
