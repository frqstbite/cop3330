#!/usr/bin/env sh

tar -czf ../proj5.tar.gz   \
        makefile           \
        Block.cpp          \
        Block.h            \
        LinearLayer.cpp    \
        LinearLayer.h      \
        Module.cpp         \
        Module.h           \
        NeuralNetwork.cpp  \
        NeuralNetwork.h    \
        ReLUActivation.cpp \
        ReLUActivation.h
$READTAR '../proj5.tar.gz'
