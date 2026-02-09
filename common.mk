.PHONY: usage clean build test submit
export .DEFAULT_GOAL := usage # Show usage information by default

BUILD_DIR        ?= build
export BIN_DIR   ?= $(BUILD_DIR)       # Path for final executable
export DEPS_DIR  ?= $(BUILD_DIR)/.deps # Path for dependency files
export OBJS_DIR  ?= $(BUILD_DIR)/.obj  # Path for object files
export TARGET                          # Name of final executable

# Convert to absolute paths
BUILD_DIR := $(abspath $(BUILD_DIR))
BIN_DIR   := $(abspath $(BIN_DIR))
DEPS_DIR  := $(abspath $(DEPS_DIR))
OBJS_DIR  := $(abspath $(OBJS_DIR))
SRC_DIR   := $(abspath $(SRC_DIR))

# Compiler
CXX ?= g++

# Clean up build environment & artifacts
clean:
	@$(RM) -rf $(BIN_DIR) $(DEPS_DIR) $(OBJS_DIR)

# Create build environment
$(BIN_DIR) $(DEPS_DIR) $(OBJS_DIR):
	@mkdir -p $@