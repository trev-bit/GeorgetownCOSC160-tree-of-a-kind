DRIVER_NAME = main
SUBMIT_NAME = submit

p3: $(DRIVER_NAME).o BinarySearchTree.o SplayTree.o
	g++ -o p3 $(DRIVER_NAME).o BinarySearchTree.o SplayTree.o

$(DRIVER_NAME).o: $(DRIVER_NAME).cpp $(DRIVER_NAME).h BinarySearchTree.h SplayTree.h
	g++ -c $(DRIVER_NAME).cpp 

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h
	g++ -c BinarySearchTree.cpp

SplayTree.o: SplayTree.cpp SplayTree.h
	g++ -c SplayTree.cpp

.PHONY: submit clean

submit:
	rm -f $(SUBMIT_NAME).zip
	zip $(SUBMIT_NAME).zip Makefile $(DRIVER_NAME).cpp $(DRIVER_NAME).h BinarySearchTree.cpp BinarySearchTree.h SplayTree.cpp SplayTree.h
		
clean:
	rm -f p3 a.out *.o
