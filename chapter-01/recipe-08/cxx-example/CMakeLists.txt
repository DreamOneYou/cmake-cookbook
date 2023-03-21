cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
message("VERSION:${VERSION}")
project(recope-08 LANGUAGES CXX)

# 为编译器设定特定标识。我们在不修改CMAKE_<LANG>_FLAGS_<CONGIF>变量的情况下，可以采用定义特定的标志列表。
set(COMPILE_FLAGS)
set(COMPILE_FLAGS_DEBUG)
set(COMPILE_FLAGS_RELEASE)
if(CMAKE_CXX_COMPILE_ID MATCHES GNU)
  list(APPEND CXX_FLAGS "-fon-rtti" "-fno-exception")  # -fno-rtti:禁用runtimeout错误。-fno-exception禁用异常错误，也就是try-catch不能使用了，
  # -Wsuggest-final-type:提示类型不完整错误；-Wsuggest-final-methos:提示方法程序员可能适合将虚函数标记为“final”，因为final在c++11中是一个关键字
  # 用于指示一个类、成员函数或者虚函数不能被继承或者重写。-Wsuggest-override:提示程序员，如果子类中重写了父类的方法，那么需要添加“override”关键字
  list(APPENd CXX_FLAGS_DEBUG "-Wsuggest-final-types" "-Wsuggest-final-methods" "-Wsuggest-override")
  list(APPEND CXX_FLAGS_RELEASE "-03" "-Wno-unused")
endif()
if(CMAKE_CXX_COMPILER_ID MATCHES Clang)
    list(APPEND CXX_FLAGS "-fno-rtti" "-fno-exceptions" "-Qunused-arguments" "-fcolor-diagnostics")
    list(APPEND CXX_FLAGS_DEBUG "-Wdocumentation")
    list(APPEND CXX_FLAGS_RELEASE "-O3" "-Wno-unused")
endif()


list(APPEND flags "-fPIC" "-Wall")
if(NOT WIN32)
  list(APPEND flags "Wextra" "Wpedantic")
endif()
add_library(message
  STATIC
    geometry_circle.cpp
    geometry_circle.hpp
    geometry_polygon.cpp
    geometry_polygon.hpp
    geometry_rhombus.cpp
    geometry_rhombus.hpp
    geometry_square.cpp
    geometry_square.hpp
)
# 为当前这个库设置编译选项，我们在外面可以使用：cmake -D CMAKE_CXX_FLAGS="-fno-rtti" .. 。其中-fno-rtti就是我们设置的一个编译选项
target_compile_options(message
  PRIVATE
    ${flags}
)
add_executable(compute compute-areas.cpp)
target_compile_options(compute
  PRIVATE
    "-fPIC"  # 告诉编译生成位置无关代码，通常主要用于动态库的生成。因为一个进程在执行的过程中，可以会多次调用这部分代码，所以需要确保在运行时可以加载并正确运行库中的函数
)
target_compile_options(compute
  PRIVATE
    ${CXX_FLAGS}
    "$<$<CONFIG:Debug>:${CXX_FLAGS_DEBUG}>"
    "$<$<CONFIG:Release>:${CXX_FLAGS_RELEASE}>"
)
message("CMAKE_CXX_FLAGS:${CMAKE_CXX_FLAGS}")

target_link_libraries(compute message)

# # set minimum cmake version
# cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# # project name and language
# project(recipe-08 LANGUAGES CXX)

# message("C++ compiler flags: ${CMAKE_CXX_FLAGS}")

# list(APPEND flags "-fPIC" "-Wall")
# if(NOT WIN32)
#   list(APPEND flags "-Wextra" "-Wpedantic")
# endif()

# add_library(geometry
#   STATIC
#     geometry_circle.cpp
#     geometry_circle.hpp
#     geometry_polygon.cpp
#     geometry_polygon.hpp
#     geometry_rhombus.cpp
#     geometry_rhombus.hpp
#     geometry_square.cpp
#     geometry_square.hpp
#   )

# target_compile_options(geometry
#   PRIVATE
#     ${flags}
#   )

# add_executable(compute-areas compute-areas.cpp)

# target_compile_options(compute-areas
#   PRIVATE
#     "-fPIC"
#   )

# target_link_libraries(compute-areas geometry)
