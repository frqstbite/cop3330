OUT_DIR = build

# Build the project for assignment 1
assignment1: prebuild
	$(MAKE) -C ./assignment1 OUT_DIR='../$(OUT_DIR)'

# Create build directory
prebuild: clean
	mkdir -p ./$(OUT_DIR)

# Clean up build artifacts
clean:
	rm -rf ./$(OUT_DIR)