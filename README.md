# COP3330

This repository contains the code behind my COP3330 assignments. The course
syllabus is available online [here][syllabus].

## Project Structure

Each assignment has its own project directory and README file with details on
the expectations for the final program. The `submission` directory contains all
files that are necessary for the assignment to function. If any of these files
are provided as part of the assignment, they should not be submitted for it.

The `scripts` directory should contain the following special scripts. Each one
is executed within the assignment's `submission` directory.

- `test.sh`: Runs after the executable is built. Should exit with a non-zero
  exit code if tests fail.
- `submit.sh`: Zips all necessary files for submission into a compressed
  tarball and outputs it in the assignment directory.
- `clean.sh`: Should clean up any artifacts left over from the build process.

## License

This repository is not released under a license. You do not have permission to
copy, use, or redistribute this repository or its contents.

[syllabus]: https://gaosh.github.io/courses/cop_3330_spring26
