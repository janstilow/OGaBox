cmake_minimum_required(VERSION 3.3.0)

project("OGaBoxProject")

include_directories ("${PROJECT_SOURCE_DIR}/include")

link_directories ("${PROJECT_SOURCE_DIR}/lib")

add_executable(OGaBox 
		"src/main.cpp"
		"src/FileHandler.cpp"
		"src/OGaRequestHandlerFactory.cpp"
	)

target_link_libraries(OGaBox PocoNet PocoFoundation)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

