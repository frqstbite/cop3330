# Define variables
IN_DIR = solution
OUT_DIR = build
FILE = driver

# Link
link: compile
	g++ -o ./$(OUT_DIR)/$(FILE) ./$(OUT_DIR)/$(FILE).o

# Compile
compile: prebuild ./$(IN_DIR)/$(FILE).cpp
	g++ -c ./$(IN_DIR)/$(FILE).cpp -o ./$(OUT_DIR)/$(FILE).o

# Create build directory
prebuild:
	mkdir -p ./$(OUT_DIR)

# Clean up build artifacts
clean:
	rm -rf ./$(OUT_DIR)