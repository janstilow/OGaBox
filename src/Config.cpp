#include "Config.h"
#include <Poco/Util/PropertyFileConfiguration.h>
#include <Poco/Foundation.h>

Poco::UInt16 serverPort = 80;
Poco::UInt32 serverMaxQueued = 128;
Poco::UInt32 serverMaxThreads = 16;

void Config::loadConfig(std::string path)
{
	Poco::AutoPtr<Poco::Util::PropertyFileConfiguration> pConf;
	pConf = new Poco::Util::PropertyFileConfiguration(path);

	serverPort = pConf->getUInt("serverPort");
	serverMaxQueued = pConf->getUInt("serverMaxQueued");
	serverMaxThreads = pConf->getUInt("serverMaxThreads");
}

Poco::UInt16 Config::getServerPort()
{
	return serverPort;
}

Poco::UInt32 Config::getMaxQueued()
{
	return serverMaxQueued;
}

Poco::UInt32 Config::getMaxThreads()
{
	return serverMaxThreads;
}