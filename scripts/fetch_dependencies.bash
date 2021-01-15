#!/bin/bash


DLL_FILES=$(ldd bin/Corrupt.exe | cut -d " " -f 3 | grep mingw | uniq -u)

cp $DLL_FILES bin/

