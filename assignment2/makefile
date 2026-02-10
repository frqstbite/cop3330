# Search for source and header files inside 'solution' directory
INC_DIR ?= $(abspath solution)
SRC_DIR ?= $(abspath solution)

# I believe the assignment said the final executable should be named 'sphere'
override TARGET := sphere

# This runs from inside an assignment directory
include ../assignment.mk

build: ./problem/driver.cpp

test:
	@echo 'Running tests for Assignment 2...'
	@$(BIN_DIR)/$(TARGET) | diff -u ./problem/sphere.out -
	@echo 'Output matched!'

submit:
	@echo 'Submitting Assignment 2...'
	@tar -czf ../assignment2.tar.gz                               \
		-C ..                                                     \
			common.mk                                             \
			assignment.mk                                         \
			makefile                                              \
			assignment2/{makefile,solution/{sphere.cpp,sphere.h}} \
		-C assignment2/solution                                   \
			README.md
	@tar -tzf ../assignment2.tar.gz | tree --fromfile .
	@echo 'Created assignment2.tar.gz for submission.'