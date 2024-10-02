#! /usr/bin/bash

# Re-create directory for compiled files
rm -rf ./out
mkdir out

# Compile source files with headers
gcc -Ilib main.c -o out/main.o -c
gcc -Ilib lib/memory.c -o out/memory.o -c
gcc -Ilib lib/string.c -o out/string.o -c

# Re-create directory for app binary
rm -rf ./bin
mkdir bin

# Link compiled files
gcc -o bin/app out/*

