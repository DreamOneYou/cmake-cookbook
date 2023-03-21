cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(recipe-10 LANGUAGES CXX)
add_library(geometry
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

target_compile_options(geometry
  PRIVATE
   -O3
)

list(APPEND source_low_opt geometry_circle.cpp  geometry_polygon.cpp)
message(STAUTS "setting source properity using IN LISTS syntx:")

foreach(_source IN LISTS source_low_opt)
  set_source_files_properties(${_source} PROERTIES COMPILE_FLAGS -O2)
  message(SATUS "source_low_opt:${_source}")
  message(SATUS "COMPILE_FLAGS:${COMPILE_FLAGS}")
endforeach()

foreach(_source ${source_low_opt})
  get_source_file_property(_flag ${_source} COMPILE)
  message(STAUTS "_source:${_source}_flag:${_flag}")
endforeach()
add_executable(computer compute-areas.cpp)
target_link_libraries(computer geometry)


# # set minimum cmake version
# cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# # project name and language
# project(recipe-10 LANGUAGES CXX)

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

# # we wish to compile the library with the optimization flag: -O3
# target_compile_options(geometry
#   PRIVATE
#     -O3
#   )

# list(
#   APPEND sources_with_lower_optimization
#     geometry_circle.cpp
#     geometry_rhombus.cpp
#   )

# # we use the IN LISTS foreach syntax to set source properties
# message(STATUS "Setting source properties using IN LISTS syntax:")
# foreach(_source IN LISTS sources_with_lower_optimization)
#   set_source_files_properties(${_source} PROPERTIES COMPILE_FLAGS -O2)
#   message(STATUS "Appending -O2 flag for ${_source}")
# endforeach()

# # we demonstrate the plain foreach syntax to query source properties
# # which requires to expand the contents of the variable
# message(STATUS "Querying sources properties using plain syntax:")
# foreach(_source ${sources_with_lower_optimization})
#   get_source_file_property(_flags ${_source} COMPILE_FLAGS)
#   message(STATUS "Source ${_source} has the following extra COMPILE_FLAGS: ${_flags}")
# endforeach()

# add_executable(compute-areas compute-areas.cpp)

# target_link_libraries(compute-areas geometry)
