cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-01 LANGUAGES NONE)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  message(STATUS "configuring on linux")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  message(STATUS "configuring for Windows")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  message(STATUS "configuring for MacOS")
else()
  message(STATUS "Configuring on/for IBM AIX")
endif()

# # set minimum cmake version
# cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# # project name, in this case no language required
# project(recipe-01 LANGUAGES NONE)

# # print custom message depending on the operating system
# if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
#   message(STATUS "Configuring on/for Linux")
# elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
#   message(STATUS "Configuring on/for macOS")
# elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
#   message(STATUS "Configuring on/for Windows")
# elseif(CMAKE_SYSTEM_NAME STREQUAL "AIX")
#   message(STATUS "Configuring on/for IBM AIX")
# else()
#   message(STATUS "Configuring on/for ${CMAKE_SYSTEM_NAME}")
# endif()
