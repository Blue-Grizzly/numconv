#!/bin/bash

# This script is used to build and run the application.

gcc src/*.c src/*.h -Wall -o build/v2

./build/v2
