all: test

CXX?=g++
CXXFLAGS?=--std=c++17

INCLUDES:=-I./include -I.

SHARED_OBJS:= \
	objs/common.o

MAIN_OBJS:= \
	objs/log.o \
	objs/logtest.o

LIBS:=

objs/common.o: shared/common.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<;

objs/log.o: src/log.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<;

objs/logtest.o: example/logtest.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<;

test: $(SHARED_OBJS) $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ $(LIBS) -o $@;

clean:
	rm -f objs/*.o test
