# Overridden by exterior build script
OUT_DIR ?= build

build: link

# Link
link: compile
	g++ -o ./$(OUT_DIR)/driver ./$(OUT_DIR)/driver.o

# Compile
compile: ./solution/driver.cpp
	g++ -c ./solution/driver.cpp -o ./$(OUT_DIR)/driver.o