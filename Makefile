all: test

CXX?=g++
CXXFLAGS?=--std=c++17

INCLUDES:=-I./include -I.

SHARED_OBJS:= \
	objs/common.o

MAIN_OBJS:= \
	objs/logger.o \
	objs/logtest.o

LIBS:=

objs/common.o: shared/common.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<;

objs/logger.o: src/logger.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<;

objs/logtest.o: example/logtest.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<;

test: $(SHARED_OBJS) $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ $(LIBS) -o $@;

clean:
	rm -f objs/*.o test
