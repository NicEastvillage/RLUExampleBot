cmake_minimum_required(VERSION 3.10)
project(cppbot LANGUAGES CXX)

# look in for the RLUtilities directory next door
add_subdirectory(RLUtilities ${CMAKE_BINARY_DIR}/rlu)

# let CMake know which files to compile for your bot library
set(source_files
  ${PROJECT_SOURCE_DIR}/src/examplebot.cc
)

# build the library
add_library(botlib STATIC ${source_files})
target_include_directories(botlib PUBLIC inc)
target_compile_features(botlib PUBLIC cxx_std_17)        
target_link_libraries(botlib PUBLIC rlutilities_cpp)
set_target_properties(botlib PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# build the executable
set(exe_name "CppExampleBot")
add_executable(my_cpp_bot src/main.cpp)
target_link_libraries(my_cpp_bot PUBLIC rlutilities_cpp botlib)
set_target_properties(my_cpp_bot PROPERTIES OUTPUT_NAME ${exe_name})
set_target_properties(my_cpp_bot PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

add_custom_command(TARGET my_cpp_bot POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_BINARY_DIR}/bin/rlutilities.dll
    ${CMAKE_BINARY_DIR}/bin/${exe_name}.exe

    ${CMAKE_BINARY_DIR}/../release
)