# Hello Word
Sample "Hello World" with [googletest](https://github.com/google/googletest)

Can be used as a template for future projects for education only

## Project Supports
* project version
* cmake for build
* gtest to check the version number
* automatic version increase when pushing
* automatically run tests after build
* automatic build for Ubuntu
* automatic build for Windows

## Build local
```shell
cd HelloWorld
git clone https://github.com/google/googletest.git

mkdir build && cd build

cmake ..

# debug
cmake --build .

# release
cmake --build . --config Release
```
