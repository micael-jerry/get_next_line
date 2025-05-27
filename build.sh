#!/bin/bash

MANDATORY_DIR="mandatory"
BONUS_DIR="bonus"
OUTPUT="get_next_line.out"
MAIN_FILE="main.c"

if [ "$1" == "-m" ]; then
    SRC_DIR="$MANDATORY_DIR"
elif [ "$1" == "-b" ]; then
    SRC_DIR="$BONUS_DIR"
else
    echo "Usage: $0 -m | -b"
    exit 1
fi

SRC_FILES=$(find "$SRC_DIR" -name "*.c")
if [ ! -f "$MAIN_FILE" ]; then
    echo "Error: $MAIN_FILE not found in current directory."
    exit 1
fi

gcc -Wall -Wextra -Werror $SRC_FILES $MAIN_FILE -o $OUTPUT

if [ $? -eq 0 ]; then
    echo "Build successful: $OUTPUT"
else
    echo "Build failed."
fi
