# This runs from inside an assignment directory
include ../common.mk

INC_DIR ?= $(abspath include) # Include directory (headers)
SRC_DIR ?= $(abspath src)     # Source directory (source files)

# Determine locations of build files
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)             # All source files
OBJS := $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJS_DIR)/%.o) # Corresponding object files
DEPS := $(SOURCES:$(SRC_DIR)/%.cpp=$(DEPS_DIR)/%.d) # Corresponding dependency files

# Compiler
CPPFLAGS += -I$(INC_DIR)

# Include dependency files
-include $(DEPS)

# Notify user how an assignment makefile works
usage:
	@echo 'Usage:'
	@echo '  make [clean|build|test|submit]'
	@echo ''
	@echo 'Targets:'
	@echo '  clean    - Clean up build artifacts'
	@echo '  build    - Build the project'
	@echo '  test     - Run tests'
	@echo '  submit   - Zip required files for submission'

# Pipeline targets
build: $(OBJS) | $(BIN_DIR)
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS) $^ -o $(BIN_DIR)/$(TARGET)

# Target that builds objects from their sources
$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJS_DIR) $(DEPS_DIR)
	@$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@ \
	-MMD -MP -MF $(DEPS_DIR)/$*.d