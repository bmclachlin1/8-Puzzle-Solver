#Makefile for CPSC 3620 SlidingTiles Programming Project
CXX = g++
CXX_FLAGS = -std=c++11

TARGET = solver

.PHONY: all
all:
	$(CXX) $(CXX_FLAGS) -o $(TARGET) ./*.cpp

%.o: %.cpp
	$(CXX) $(CXX_FLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *.o $(TARGET) *~
