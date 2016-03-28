cmake_minimum_required(VERSION 3.3.0)

project("OGaBoxProject")



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
	set("OGaBox_Poco${pocoLibName}d" "${OGaBox_tmpDebug}" PARENT_SCOPE)
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
		"src/FileHandler.cpp"
		"src/FileHandler.h"
		"src/OGaRequestHandlerFactory.cpp"
		"src/OGaRequestHandlerFactory.h"
		"src/Config.cpp"
		"src/Config.h"
		"OGaBox.cfg")

target_link_libraries(
		OGaBox optimized
		"${OGaBox_PocoFoundation}"
		"${OGaBox_PocoUtil}"
		"${OGaBox_PocoNet}"
		"${OGaBox_PocoJSON}"
		"${OGaBox_PocoXML}")
if(
		(EXISTS "${OGaBox_PocoFoundationd}")
		AND (EXISTS "${OGaBox_PocoUtild}")
		AND (EXISTS "${OGaBox_PocoNetd}")
		AND (EXISTS "${OGaBox_PocoJSONd}")
		AND (EXISTS "${OGaBox_PocoXMLd}") )
	target_link_libraries(
			OGaBox debug
			"${OGaBox_PocoFoundationd}"
			"${OGaBox_PocoUtild}"
			"${OGaBox_PocoNetd}"
			"${OGaBox_PocoJSONd}"
			"${OGaBox_PocoXMLd}")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)



install(
		TARGETS OGaBox
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION bin)

