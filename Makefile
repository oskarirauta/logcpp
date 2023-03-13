CXX?=g++
CXXFLAGS?=--std=c++17 -Wall
INCLUDES:=-I./include -I.

LOGGER_OBJS:= \
	objs/logger.o

EXAMPLE_OBJS:= \
	objs/logtest.o

include common/Makefile.inc

all: test
world: test

objs/logger.o: src/logger.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<;

objs/logtest.o: example/logtest.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<;

test: $(COMMON_OBJS) $(LOGGER_OBJS) $(EXAMPLE_OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@;

clean:
	rm -f objs/*.o test
