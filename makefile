# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -g

# Source files (recursively find all .cpp files in the src directory)
SRCS = $(shell find src -name "*.cpp")
# Object files (replace src/ with obj/ and .cpp with .o)
OBJS = $(SRCS:src/%.cpp=obj/%.o)

# Executable name
TARGET = bin/2048_txt

# Ensure output directories exist
$(TARGET): $(OBJS)
	mkdir -p obj bin
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files to object files
$(OBJS): $(SRCS)
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f obj/* bin/*

# Phony targets
.PHONY: all clean