# This entire makefile is just a build orchestrator
.PHONY: _validate
include common.mk

# Notify user to specify what assignment to build
usage:
	@echo 'Usage:'
	@echo '  make clean'
	@echo '  make [build|test|submit] ASSIGNMENT=[1|2]'

# Validate assignment selection
_validate:
    # Check that ASSIGNMENT variable is defined
    ifndef ASSIGNMENT
	@echo 'ERROR: ASSIGNMENT was not specified.'
	@$(MAKE) usage
	@exit 1
    endif

    # Validate that ASSIGNMENT is an integer within range
	@case "$(ASSIGNMENT)" in                                         \
        1|2 ) ;;                                                     \
        ''|*[!0-9]* )                                                \
            echo 'Error: ASSIGNMENT is not a valid integer.';        \
            $(MAKE) usage;                                           \
            exit 1 ;;                                                \
        * )                                                          \
            echo 'Error: ASSIGNMENT is outside valid range [1, 2].'; \
            $(MAKE) usage;                                           \
            exit 1 ;;                                                \
    esac

# Forward pipeline targets to the appropriate assignment makefile
build: _validate
	$(eval TARGET='assignment$(ASSIGNMENT)')
	@$(MAKE) -C ./assignment$(ASSIGNMENT) build
test: _validate build
	@$(MAKE) -C ./assignment$(ASSIGNMENT) test
submit: _validate test
	@$(MAKE) -C ./assignment$(ASSIGNMENT) submit