#!/usr/bin/env sh

tar -czf assignment2/sphere.tar.gz \
    -C assignment2/submission      \
        makefile                   \
        sphere.cpp                 \
        sphere.h
tar -tzf assignment2/sphere.tar.gz | tree --fromfile .
echo 'Created sphere.tar.gz for submission.'
