# Define variables
IN_DIR = solution
OUT_DIR = build
FILE = driver

# Link
$(FILE): $(FILE).o
	g++ -o ./$(OUT_DIR)/$(FILE) ./$(OUT_DIR)/$(FILE).o

# Compile
$(FILE).o: setup ./$(IN_DIR)/$(FILE).cpp
	g++ -c ./$(IN_DIR)/$(FILE).cpp -o ./$(OUT_DIR)/$(FILE).o

# Create build directory
setup:
	mkdir -p ./$(OUT_DIR)

# Clean up build artifacts
clean:
	rm -rf ./$(OUT_DIR)