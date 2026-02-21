#!/usr/bin/env sh

tar -czf assignment3/proj3.tar.gz \
    -C assignment3/submission     \
        makefile                  \
        date.cpp                  \
        date.h
tar -tzf assignment3/proj3.tar.gz | tree --fromfile .
echo 'Created proj3.tar.gz for submission.'
