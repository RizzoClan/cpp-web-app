#!/bin/bash
#@file: Intended to call other helper scripts in order to install all neccessary components to compile

[[ "$OSTYPE" == "msys" || "$OSTYPE" == "cygwin" ]] && isWindows=true || isWindows=false

# if linux, need to check if using correct permissions
if [[ "${isWindows}" = false ]]; then
    if [ "$EUID" -ne 0 ]; then
        echo "Please run as root ('sudo')"
        exit
    fi
else # is windows
    echo "Windows install not yet implemented..."
    echo "Check README for requirements to try manual installation"
    exit
fi

# Get absolute paths
INSTALL_DIR="$(readlink -fm "$0"/..)"
rootDir="$(readlink -fm "${INSTALL_DIR}/..")"

# get neccessary packages/libraries
echo "#1.1 Updating..."
apt update -y

echo "#1.2 Installing..."
apt install -y \
    libboost-all-dev \
    gcc-5 \
    cmake \
    build-essential \
    libtcmalloc-minimal4 \
    && sudo ln -s /usr/lib/libtcmalloc_minimal.so.4 /usr/lib/libtcmalloc_minimal.so

echo "#1.3 Upgrading..."
apt upgrade -y

echo "Install Complete!!"
