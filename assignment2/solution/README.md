Hi! Ashi here. There's some things you should probably know about my build
system before you dig in to my assignment submission.

**My build system is distributed across multiple makefiles.**  (provided here as `makefile`). As long
as the makefiles can find each other, you should be able to run the build,
test, and submit targets from the provided assignment-specific makefile without
issue.

The `common.mk` file contains shared configurations and rules used by all
makefiles in the repository. The `assignment.mk` file is an extension of
`common.mk` that adds configurations and rules that are only necessary in the
individual assignment makefiles.

Thank you!