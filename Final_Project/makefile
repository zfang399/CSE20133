# Make all the files for the Gomoku game
# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
SRCS = Gomoku.cpp
OBJS = ${SRCS:.cpp=.o}
PROGS = ${SRCS:.cpp=}
DEPS = Board.h Player.h
DEPOBJS = Board.o Player.o

all: $(PROGS)
.PHONY: all

$(PROGS): % : %.o $(DEPOBJS)
		$(CXX) $(CXXFLAGS) $@.o $(DEPOBJS) -o $@

%.o: %.cpp $(DEPS)
		$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
		@echo "Cleaning up"
		@rm -f $(PROGS) $(OBJS) $(DEPOBJS)