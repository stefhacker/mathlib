# Variables
CXX = g++
CXXFLAGS = -std=c++11 -I$(PYTHON_INCLUDE_DIR) -I$(MATPLOTLIBCPP_DIR)
LDFLAGS = -L$(PYTHON_LIB_DIR) -lpython$(PYTHON_VERSION)
MATPLOTLIBCPP_DIR = matplotlibcpp
PYTHON_INCLUDE_DIR = /path/to/python/include
PYTHON_LIB_DIR = /path/to/python/libs
PYTHON_VERSION = 3.9 # Adjust this to your Python version

# Source and binary files
SRC = src/main.cpp
OBJ = $(SRC:.cpp=.o)
BIN = plot_example

# Default target
all: $(BIN)

# Linking
$(BIN): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Compilation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ) $(BIN)

.PHONY: all clean

