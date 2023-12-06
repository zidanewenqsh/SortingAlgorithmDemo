# Makefile

# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -g

# Directories
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
INC_DIR := include

# Include path
CPPFLAGS := -I$(INC_DIR)

# Collect all cpp files and corresponding object files and executable files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
BINS := $(SRCS:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%)

# Default target
all: $(BINS)

# Rule to create object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

# Rule to create executable files
$(BIN_DIR)/%: $(OBJ_DIR)/%.o | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@

# Create directories
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Phony targets
.PHONY: all clean
