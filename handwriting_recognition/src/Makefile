CPPFLAGS=--std=c++11 -O2
LDFLAGS=-O2

SRCS=idxreader.cpp main.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

handwriting: $(OBJS)
	    $(CXX) $(LDFLAGS) -o handwriting idxreader.o main.o $(LDLIBS) 

idxreader.o: idxreader.cpp idxreader.h
	    $(CXX) $(CPPFLAGS) -c idxreader.cpp

main.o: main.cpp
	    $(CXX) $(CPPFLAGS) -c main.cpp

clean: 
		rm -f idxreader $(OBJS)
