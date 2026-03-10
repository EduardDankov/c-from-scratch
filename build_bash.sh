#! /usr/bin/bash

# Re-create build directory
rm -rf ./build
mkdir build
mkdir build/out
mkdir build/bin

# Compile source files with headers
gcc -Ilib main.c -o build/out/main.o -c
gcc -Ilib lib/memory.c -o build/out/memory.o -c
gcc -Ilib lib/string.c -o build/out/string.o -c
gcc -Ilib lib/io.c -o build/out/io.o -c
gcc -Ilib lib/math.c -o build/out/math.o -c
gcc -Ilib lib/convert.c -o build/out/convert.o -c

# Link compiled files
gcc -o build/bin/app build/out/*
