# This entire makefile is just a build orchestrator
.PHONY: _validate _usage build test submit clean

# Notify user to specify what assignment to build
_usage:
	@echo 'Usage:'
	@echo '  make [build|test|submit|clean] ASSIGNMENT=[1|2|3]'

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
        1|2|3 ) ;;                                                     \
        ''|*[!0-9]* )                                                \
            echo 'ERROR: ASSIGNMENT is not a valid integer.';        \
            $(MAKE) usage;                                           \
            exit 1 ;;                                                \
        * )                                                          \
            echo 'ERROR: ASSIGNMENT is outside valid range [1, 3].'; \
            $(MAKE) usage;                                           \
            exit 1 ;;                                                \
    esac

build: _validate
	@echo 'Building assignment $(ASSIGNMENT)...'
	@$(MAKE) -C assignment$(ASSIGNMENT)/submission
	@echo 'Built assignment $(ASSIGNMENT) to assignment$(ASSIGNMENT)/submission'

test: _validate build
	@echo 'Running tests for assignment $(ASSIGNMENT)...'
	@cd assignment$(ASSIGNMENT)/submission; ../scripts/test.sh
	@echo 'Tests passed!'

submit: _validate test clean
	@echo 'Submitting assignment $(ASSIGNMENT)...'
	@cd assignment$(ASSIGNMENT)/submission; ../scripts/submit.sh

clean: _validate
	@cd assignment$(ASSIGNMENT)/submission; ../scripts/clean.sh
	@cd assignment$(ASSIGNMENT); rm -f *.tar{,.gz}
	@echo 'Cleaned up assignment $(ASSIGNMENT) build artifacts.'
