cmake_minimum_required(VERSION 3.3.0)

project("OGaBoxProject")

add_executable(OGaBox "src/main.cpp")

target_link_libraries(OGaBox PocoNet PocoFoundation)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

