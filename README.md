# COP3330

This repository contains the code, scriptwriting, and video projects behind my
COP3330 assignments. The course syllabus is available online [here][syllabus].

## Project Structure

The [Motion Canvas][motioncanvas] project used to composite the videos
submitted alongside the code is in the `videos/` directory. Each assignment has
a corresponding [project][motioncanvas-project] that renders into that
assignment's video. For more information, refer to the Motion Canvas
[documentation][motioncanvas-docs].

Audio is recorded and edited using Audacity [Audacity][audacity]. The `.aup3`
file for each assignment's audio is located in the `audio/` directory. The
macro used to clean up background noise is included in the repository as
`audio/Vocal Cleanup.txt`. The final exported `.wav` files are included in the
`videos/assets/` directory.

Additionally, each assignment has its own project directory and README file
with details on the expectations for the final program. The project directories
follow a common structure described below.

### Code

Any project files that are provided with the assignment will be located under
the `problem/` directory for immediate reference. The attempted solution will
be under the `solution/` directory, from which the `makefile` for the
assignment will build.

### Script

After the program has been sufficiently tested, a script is written to
`script.md` to communicate the key points in the video. Code snippets are
included to supplement the visuals added in post when necessary.

## License

This repository is not released under a license. You do not have permission to
copy, use, or redistribute this repository or its contents.

[syllabus]: https://gaosh.github.io/courses/cop_3330_spring26
[motioncanvas]: https://motioncanvas.io
[motioncanvas-project]: https://motioncanvas.io/docs/configuration#project
[motioncanvas-docs]: https://motioncanvas.io/docs
[audacity]: https://www.audacityteam.org
