#! /usr/bin/bash

# Create directory for compiled files
mkdir out

# Compile source files
gcc main.c -o out/main.o -c

# Create directory for app binary
mkdir bin

# Link compiled files
gcc -o bin/app out/main.o

