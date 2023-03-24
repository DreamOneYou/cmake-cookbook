cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-04 LANGUAGES CXX)
add_executable(arch arch-dependent.cpp)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  target_compile_definitions(arch PUBLIC "IS_64_BIT_ARCH")
  message("IS_64_BIT_ARCH")
else()
  target_compile_definitions(arch PUBLIC "IS_32_BIT_ARCH")
  message("IS_32_BIT_ARCH")
endif()

if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "I386")
  message("i386")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "i686")
  message(STATUS "i686 architecture detected")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")
  message("x86_64")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "i7-10750H")
  message("i7-10750H")
else()
  message("other")
endif()
target_compile_definitions(arch PUBLIC "ARCHITECTURE=${CMAKE_HOST_STSTEM_PROCESSOR}")


# # set minimum cmake version
# cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# # project name and language
# project(recipe-04 LANGUAGES CXX)

# # define executable and its source file
# add_executable(arch-dependent arch-dependent.cpp)

# # let the preprocessor know about the size of void *
# if(CMAKE_SIZEOF_VOID_P EQUAL 8)
#   target_compile_definitions(arch-dependent PUBLIC "IS_64_BIT_ARCH")
#   message(STATUS "Target is 64 bits")
# else()
#   target_compile_definitions(arch-dependent PUBLIC "IS_32_BIT_ARCH")
#   message(STATUS "Target is 32 bits")
# endif()

# # let the preprocessor know about the host processor architecture
# if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "i386")
#   message(STATUS "i386 architecture detected")
# elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "i686")
#   message(STATUS "i686 architecture detected")
# elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")
#   message(STATUS "x86_64 architecture detected")
# else()
#   message(STATUS "host processor architecture is unknown")
# endif()

# target_compile_definitions(arch-dependent
#   PUBLIC "ARCHITECTURE=${CMAKE_HOST_SYSTEM_PROCESSOR}"
#   )
