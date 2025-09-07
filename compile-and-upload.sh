#!/bin/bash

# Arduino CLI not installed 
if ! command -v arduino-cli > /dev/null 2>&1; then
  echo "Arduino CLI not installed"
  exit 1
fi

# Did not pass arg
if [[ -z "$1" ]]; then
  echo "Usage: ./compile-and-upload [source path]"
  exit 2
fi

SKETCH_DIR="$1"
BOARD_NAME="arduino:avr:uno"
BOARD_PORT_PATH="/dev/ttyACM0"

# Compile the sketch 
arduino-cli compile \
  -b "$BOARD_NAME" \
  -v \
  "$SKETCH_DIR"

# Upload it; ensure R+W permission for port is set first
sudo chmod a+rw "$BOARD_PORT_PATH"

arduino-cli upload \
  "$SKETCH_DIR" \
  -p "$BOARD_PORT_PATH" \
  -b "$BOARD_NAME"

# NOTE: Arduino temporarily stores compilation result of sketch at path and knows where to pull it from when calling upload with the same sketch path 
exit 0
