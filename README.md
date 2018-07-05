# CppNotes

My notes about C++, algorithms and data structures.

## Requirements
Ubuntu 14+, g++ 8+, cmake 3.9+, Boost 1.55+

## Download

``` bash
git clone https://github.com/iamantony/CppNotes.git
cd CppNotes
git submodule update --init --recursive
```

## Setup environment

### Install g++ 8

``` bash
# Check version of your current g++
g++ -v

# For example, we have g++ 5. Add it to 'update-alternatives'
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-5 60 --slave /usr/bin/g++ g++ /usr/bin/g++-5

# Install gcc-8 and g++-8
# https://gist.github.com/application2000/73fd6f4bf1be6600a2cf9f56315a2d91
sudo add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt-get update
sudo apt-get install gcc-8 g++-8

# Add them to alternative compilres
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-8 60 --slave /usr/bin/g++ g++ /usr/bin/g++-8

# Configure which gcc to use. Choose gcc 8
sudo update-alternatives --config gcc

g++ -v
```

### Install cmake 3.11

``` bash
# Download sources and build cmake
mkdir tmp
cd tmp
wget https://cmake.org/files/v3.11/cmake-3.11.4.tar.gz
tar -xvzf ./cmake-3.10.1.tar.gz
cd cmake-3.10.1/
./configure
make -j4

# Install cmake into /usr/local/bin
sudo make install

# cd to home directory and check cmake version
cd ~
cmake --version
```

### Install Boost on Linux

http://www.boost.org/doc/libs/1_59_0/more/getting_started/unix-variants.html
http://shoddykid.blogspot.ru/2014/10/building-boost-libraries-quickly.html

## Build

``` bash
cd CppNotes
mkdir build
cd build

# Build type - Release or Debug; if you want to enable sanitizers, use -DSANITIZE_UNDEFINED=ON
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
make
```

## How to import project to Eclipse
https://cmake.org/Wiki/Eclipse_CDT4_Generator
