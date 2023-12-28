# Hello Word
Sample "Hello World" with [googletest](https://github.com/google/googletest)

Can be used as a template for future projects for education only

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

#otus #cpp #cmake #gtest