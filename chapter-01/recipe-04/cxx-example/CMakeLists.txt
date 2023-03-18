# 设置版本
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
# 创建项目名称和语言设置
project(recipe-04 LANGUAGES CXX)
# 设置USE_LIBRARY，是否创建链接库。
set(USE_LINRARY 1)
message(STATUS "USE_LIBRARY ${USE_LIBRARY}")
# 当add_library中没有设置STATIC或者SHARED时，BUILD_SHARED_LIBS可以设置一个全局变量，如果为1，则默认使用SHARED动态库，如果为0，则默认设置STATIC静态库
set(BUILD_SHARED_LIBS 1)
# 这个命令就是一个列表，将元素（也就是我们用到的其他文件）追加到里面，并对其进行命名，我们这里命名为_source
# 这里的_source是一个局部变量
list(APPEND _source Message.cpp Message.hpp)
# 判断语句
if(USE_LIBRARY)
  # 构建生成一个库，然后将生成的库链接到hellows这个可执行文件中
  add_library(message SHARED ${_source})
  add_executable(hellows hello-world.cpp)
  target_link_libraries(hellows message)
else()
  add_executable(hellows hello-world.cpp ${_source}) # 构建一个可执行文件，不生成任何库
endif()