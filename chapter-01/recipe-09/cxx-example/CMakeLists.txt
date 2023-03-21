cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-09 LANGUAGES CXX)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS off)
add_library(animal
  STATIC
    Animal.cpp
    Animal.hpp
    Cat.cpp
    Cat.hpp
    Dog.cpp
    Dog.hpp
    Factory.hpp
)
set_target_properties(animal
  PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
add_executable(animal-farm  animal-farm.cpp)
set_target_properties(animal-farm
  PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED on
    CXX_EXTENSIONS OFF
)

target_link_libraries(animal-farm animal)


# # set minimum cmake version
# cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# # project name and language
# project(recipe-09 LANGUAGES CXX)

# set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# add_library(animals
#   SHARED
#     Animal.cpp
#     Animal.hpp
#     Cat.cpp
#     Cat.hpp
#     Dog.cpp
#     Dog.hpp
#     Factory.hpp
#   )

# set_target_properties(animals
#   PROPERTIES
#     CXX_STANDARD 14
#     CXX_EXTENSIONS OFF
#     CXX_STANDARD_REQUIRED ON
#     POSITION_INDEPENDENT_CODE 1
#   )

# add_executable(animal-farm animal-farm.cpp)


# set_target_properties(animal-farm
#   PROPERTIES
#     CXX_STANDARD 14
#     #CXX_EXTENSIONS OFF ：默认是ON，即开启状态。一旦开启，就意味着编译器可以支持一些非标准的C++特征，比如空函数参数列表、非成员模板函数的隐式实例化。
#     #虽然这些扩展会让开发者编写更加简洁易懂的代码，但是也代表这代码移植会变得困难。
#     CXX_EXTENSIONS OFF  
#     CXX_STANDARD_REQUIRED ON  # 用于指定编译器需要强制遵守c++标准，比如当前设定c++ 14.必须严格按照14的标准，否则会报错
#   )

# target_link_libraries(animal-farm animals)
