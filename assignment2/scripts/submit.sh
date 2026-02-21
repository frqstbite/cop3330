#!/usr/bin/env sh

tar -czf ../sphere.tar.gz \
    makefile              \
    sphere.cpp            \
    sphere.h
tar -tzf ../sphere.tar.gz | tree --fromfile .
echo 'Created sphere.tar.gz for submission.'
