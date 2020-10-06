# Cpp-Web-App

Uses "crow" microframework library to create a website using C++

## Install (Automate this later)

Quick Install: `sudo ./install/setup.sh`

### Requirements from Crow

* C++ compiler with good C++11 support (tested with g++>=4.8)
  * ubuntu 16.04 starts off with g++5.5 I believe
* boost library
  * `sudo apt install libboost-all-dev`
* CMake (to build)
  * `sudo apt install cmake`
* Linking with tcmalloc/jemalloc is recommended for speed.
  * `sudo apt install build-essential libtcmalloc-minimal4 && sudo ln -s /usr/lib/libtcmalloc_minimal.so.4 /usr/lib/libtcmalloc_minimal.so`
* Now supporting VS2013 with limited functionality (only run-time check for url is available.)
