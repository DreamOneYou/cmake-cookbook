# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-01 LANGUAGE CXX)

# 生成可执行文件的名字
add_executable(hello-world hello-world.cpp)

# cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# # project name and language
# project(recipe-01 LANGUAGES C)

# add_executable(hello-world hello-world.c)
