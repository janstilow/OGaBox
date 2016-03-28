#pragma once

#include <Poco/Util/PropertyFileConfiguration.h>
#include <Poco/Foundation.h>
#include <string>



namespace Config
{
	void initConfig(int argc, char **argv);

	Poco::UInt16 getServerPort();
	Poco::UInt32 getMaxQueued();
	Poco::UInt32 getMaxThreads();
};
