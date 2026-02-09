# Search for source and header files inside 'solution' directory
INC_DIR ?= $(abspath solution)
SRC_DIR ?= $(abspath solution)

# This runs from inside an assignment directory
include ../assignment.mk

test:
	@echo 'Running tests for Assignment 1...'
	@$(BIN_DIR)/$(TARGET) | diff -u ./problem/driver.out -
	@echo 'Output matched!'

submit:
	@echo 'Submitting Assignment 1...'
	@tar -czf ../assignment1.tar.gz -C solution driver.cpp
	@echo 'Created assignment1.tar.gz for submission.'