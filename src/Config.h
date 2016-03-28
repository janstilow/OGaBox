#pragma once

#include <Poco/Foundation.h>
#include <string>



namespace Config
{
	void loadConfig(std::string);
	Poco::UInt16 getServerPort();
	Poco::UInt32 getMaxQueued();
	Poco::UInt32 getMaxThreads();
};
