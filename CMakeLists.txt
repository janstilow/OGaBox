cmake_minimum_required(VERSION 3.3.0)

project("OGaBoxProject")

include_directories ("${PROJECT_SOURCE_DIR}/include")

link_directories ("${PROJECT_SOURCE_DIR}/lib")

add_executable(
		OGaBox 
		"src/main.cpp"
		"src/FileHandler.cpp"
		"src/FileHandler.h"
		"src/OGaRequestHandlerFactory.cpp"
		"src/OGaRequestHandlerFactory.h"
		"src/Config.cpp"
		"src/Config.h"
		"OGaBox.cfg")
IF(MSVC)
	target_link_libraries(
			OGaBox)
ELSE()
	target_link_libraries(
			OGaBox
			PocoFoundation
			PocoUtil
			PocoNet)
ENDIF()

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

