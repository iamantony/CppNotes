CppNotes
========

My notes about C++.

## Requirements
g++ 4.9+, cmake 3.2+, Boost 1.55+

## Download

``` bash
git clone https://github.com/iamantony/CppNotes.git
cd CppNotes
git submodule update --init --recursive
```

## Build

``` bash
cd CppNotes
mkdir build
cd build

# Build type - Release or Debug; if you want to enable sanitizers, use -DSANITIZE_UNDEFINED=ON
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
make
```

## Import project to Eclipse
https://cmake.org/Wiki/Eclipse_CDT4_Generator

## Install Boost on Linux
http://www.boost.org/doc/libs/1_59_0/more/getting_started/unix-variants.html
http://shoddykid.blogspot.ru/2014/10/building-boost-libraries-quickly.html
