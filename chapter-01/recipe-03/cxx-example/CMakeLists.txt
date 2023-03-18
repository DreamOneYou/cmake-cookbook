cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(hell LANGUAGES CXX)

add_library(message-obj
  OBJECT
    Message.cpp
    Message.hpp
)

set_target_properties(message-obj
  PROPERTIES
    POSITION_INDEPENDENT_CODE 1
)

add_library(message-shared
  SHARED
    $<TARGET_OBJECTS:message-obj>
)
set_target_properties(message-shared
  PROPERTIES
    OUTPUT_NAME "message"
)
add_library(message-static
  STATIC
    $<TARGET_OBJECTS:message-obj>
)
set_target_properties(message-static
  PROPERTIES
   OUTPUT_NAME "message"

)

add_executable(hellw hello-world.cpp)
target_link_libraries(hellw message-static)