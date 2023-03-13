LOGGER_DIR?=logger
INCLUDES += -I./$(LOGGER_DIR)/include
LOGGER_OBJS:= \
	objs/logger.o

objs/logger.o: $(LOGGER_DIR)/src/logger.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<;
