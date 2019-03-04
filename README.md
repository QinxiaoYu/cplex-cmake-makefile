# Cplex cmake and makefile for C++

## CmaleLists

- All credits go to https://github.com/coin-or/Gravity/blob/master/CMakeLists.txt

## Makefile

## Using a makefile in a cmake file

```cmake
add_custom_target(<PROJECT_NAME> COMMAND make -C ${PROJECT_SOURCE_DIR} CLION_EXE_DIR=${PROJECT_BINARY_DIR})
```
