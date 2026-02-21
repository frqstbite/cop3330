#!/usr/bin/env sh

tar -czf ../proj3.tar.gz \
        makefile         \
        date.cpp         \
        date.h
tar -tzf ../proj3.tar.gz | tree --fromfile .
echo 'Created proj3.tar.gz for submission.'
