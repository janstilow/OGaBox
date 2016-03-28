#pragma once

#include <Poco/Foundation.h>



namespace Config
{
	void initConfig(int argc, char **argv);

	Poco::UInt16 getServerPort();
	Poco::UInt32 getMaxQueued();
	Poco::UInt32 getMaxThreads();
};
