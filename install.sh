#!/bin/bash

BINARY_FILE="darbshell"
INSTALL_PATH="/usr/local/bin/$BINARY_NAME"

    echo "       ----------------------"
    echo "      | Darb Shell Installer |"
    echo "       ----------------------"

if  command -v g++ >/dev/null 2>&1; then
    echo "Initializing Package"
    g++ -std=c++23 main.cpp lib/cd/cd.cpp lib/input/inputParser.cpp lib/runner/runner.cpp -o darbshell
else 
    echo "Error: g++ compiler isn't installed"
    exit 1
fi

echo "Copying files"
    sudo cp "$BINARY_FILE" "$INSTALL_PATH"
    sudo chmod 755 "$INSTALL_PATH"
echo "removing unnecessary files"
    rm "$BINARY_FILE"
echo "done"

echo "Registering Shell in /etc/shells"

if ! grep -q "$INSTALL_PATH" /etc/shells; then
    echo "$INSTALL_PATH" | sudo tee -a /etc/shells > /dev/null
else
    echo "Shell already registered in /etc/shells"
fi