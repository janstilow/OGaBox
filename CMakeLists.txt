cmake_minimum_required(VERSION 3.3.0)

project("OGaBoxProject")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

function(findPocoLib pocoLibName)
	unset("OGaBox_tmpOpt" CACHE)
	unset("OGaBox_tmpDebug" CACHE)

	find_library(
			"OGaBox_tmpOpt"
			"Poco${pocoLibName}"
			PATHS "${USE_POCO_DIR}/lib"
			NO_DEFAULT_PATH)
	find_library(
			"OGaBox_tmpDebug"
			"Poco${pocoLibName}d"
			PATHS "${USE_POCO_DIR}/lib"
			NO_DEFAULT_PATH)

	set("OGaBox_Poco${pocoLibName}" "${OGaBox_tmpOpt}" PARENT_SCOPE)
	if(EXISTS "${OGaBox_tmpDebug}")
		set("OGaBox_Poco${pocoLibName}d" "${OGaBox_tmpDebug}" PARENT_SCOPE)
	else()
		set("OGaBox_Poco${pocoLibName}d" "${OGaBox_tmpOpt}" PARENT_SCOPE)
	endif()
endfunction(findPocoLib)



if(DEFINED USE_POCO_DIR)
	if(NOT EXISTS "${USE_POCO_DIR}/include/Poco/Foundation.h")
		message(FATAL_ERROR "Did not find POCO includes on '${USE_POCO_DIR}/includes'.")
	endif()
	findPocoLib("Foundation")
	findPocoLib("Util")
	findPocoLib("Net")
	findPocoLib("JSON")
	findPocoLib("XML")
	if(
			(NOT EXISTS "${OGaBox_PocoFoundation}")
			OR (NOT EXISTS "${OGaBox_PocoUtil}")
			OR (NOT EXISTS "${OGaBox_PocoNet}")
			OR (NOT EXISTS "${OGaBox_PocoJSON}")
			OR (NOT EXISTS "${OGaBox_PocoXML}") )
		message(FATAL_ERROR "Did not find POCO libraries on '${USE_POCO_DIR}/lib'.")
	endif()
	include_directories("${USE_POCO_DIR}/include")
else()
	set(OGaBox_PocoFoundation PocoFoundation)
	set(OGaBox_PocoUtil PocoUtil)
	set(OGaBox_PocoNet PocoNet)
	set(OGaBox_PocoJSON PocoJSON)
	set(OGaBox_PocoXML PocoXML)
endif()



add_executable(
		OGaBox 
		"src/main.cpp"
		"src/Environment.cpp"
		"src/Environment.h"
		"src/FileHandler.cpp"
		"src/FileHandler.h"
		"src/OGaRequestHandlerFactory.cpp"
		"src/OGaRequestHandlerFactory.h"
		"src/OGaWebSocket.cpp"
		"src/OGaWebSocket.h"
		"src/OGaService.cpp"
		"src/OGaService.h"
		"src/OGaServiceContext.cpp"
		"src/OGaServiceContext.h"
		"src/OGaRoom.cpp"
		"src/OGaRoom.h"
		"src/OGaUser.cpp"
		"src/OGaUser.h"
		"src/OGaWorker.cpp"
		"src/OGaWorker.h"
		"src/Config.cpp"
		"src/Config.h"
		"OGaBox.cfg")

target_link_libraries(
		OGaBox optimized
		"${OGaBox_PocoFoundation}"
		"${OGaBox_PocoUtil}"
		"${OGaBox_PocoNet}"
		"${OGaBox_PocoJSON}"
		"${OGaBox_PocoXML}"
		"pthread")
target_link_libraries(
		OGaBox debug
		"${OGaBox_PocoFoundationd}"
		"${OGaBox_PocoUtild}"
		"${OGaBox_PocoNetd}"
		"${OGaBox_PocoJSONd}"
		"${OGaBox_PocoXMLd}"
		"pthread")

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)



install(
		TARGETS OGaBox
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION bin)

