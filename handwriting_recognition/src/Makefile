CPPFLAGS=--std=c++11 -O2
LDFLAGS=-O2

SRCS=idxreader.cpp neuralnetwork.cpp main.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

handwriting: $(OBJS)
	    $(CXX) $(LDFLAGS) -o handwriting idxreader.o neuralnetwork.o main.o $(LDLIBS) 

idxreader.o: idxreader.cpp idxreader.h
	    $(CXX) $(CPPFLAGS) -c idxreader.cpp

neuralnetwork.o: neuralnetwork.cpp neuralnetwork.h
		$(CXX) $(CPPFLAGS) -c neuralnetwork.cpp

main.o: main.cpp
	    $(CXX) $(CPPFLAGS) -c main.cpp

clean: 
		rm -f handwriting $(OBJS)
