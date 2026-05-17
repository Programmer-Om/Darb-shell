#!/bin/bash

BINARY_FILE="darb"
INSTALL_PATH="/usr/local/bin/$BINARY_FILE"

echo "       ------------------------"
echo "      | Darb Shell Uninstaller |"
echo "       ------------------------"

# 1. Remove the binary executable
if [ -f "$INSTALL_PATH" ]; then
    echo "Removing binary file from $INSTALL_PATH..."
    sudo rm "$INSTALL_PATH"
else
    echo "Binary not found at $INSTALL_PATH. Skipping."
fi

# 2. Deregister the shell from /etc/shells
if grep -Fxq "$INSTALL_PATH" /etc/shells; then
    echo "Deregistering Shell from /etc/shells..."
    # Escape the forward slashes in the path so sed doesn't break
    ESCAPED_PATH=$(echo "$INSTALL_PATH" | sed 's/\//\\\//g')
    sudo sed -i "/$ESCAPED_PATH/d" /etc/shells
else
    echo "Shell was not registered in /etc/shells."
fi

echo "Uninstall completed successfully."
