CXX?=g++
CXXFLAGS?=--std=c++17 -Wall
INCLUDES:=-I./include -I.

LOGGER_EXAMPLE_OBJS:= \
	objs/main.o

LOGGER_DIR:=.
include common/Makefile.inc
include Makefile.inc

all: logger
world: logger

objs/main.o: main.cpp
	echo "objs: $(LOGGER_OBJS)"
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<;

logger: $(COMMON_OBJS) $(LOGGER_OBJS) $(LOGGER_EXAMPLE_OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@;

clean:
	rm -f objs/*.o logger
