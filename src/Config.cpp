#include "Config.h"

#include <Poco/Util/PropertyFileConfiguration.h>
#include <iostream>
#include <fstream>
#include <cstring>



Poco::UInt16 serverPort = 8080;
#define SERVER_PORT_KEY "serverPort"
Poco::UInt32 serverMaxQueued = 128;
#define SERVER_MAX_QUEUED_KEY "serverMaxQueued"
Poco::UInt32 serverMaxThreads = 16;
#define SERVER_MAX_THREADS "serverMaxThreads"

bool createConfigFile(std::string path);
void loadConfig(std::string);
unsigned int getUIntFromConf(
	Poco::AutoPtr<Poco::Util::PropertyFileConfiguration> pConf,
	std::string key,
	unsigned int defaultValue);


void Config::initConfig(int argc, char **argv)
{
	std::string configFilePath = "OGaBox.cfg";

	for(int i = 1; i < argc-1; i++)
	{
		if(strcmp("-c", argv[i]) == 0 || strcmp("--config", argv[i]) == 0)
		{
			configFilePath = argv[i+1];
		}
	}

	loadConfig(configFilePath);
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

void loadConfig(std::string path)
{
	std::ifstream confFile(path.c_str());
	bool fileExists = confFile.good();
	confFile.close();

	if(fileExists)
	{
		Poco::AutoPtr<Poco::Util::PropertyFileConfiguration> pConf;
		pConf = new Poco::Util::PropertyFileConfiguration(path);

		serverPort = getUIntFromConf(pConf, SERVER_PORT_KEY, serverPort);
		serverMaxQueued = getUIntFromConf(pConf, SERVER_MAX_QUEUED_KEY, serverMaxQueued);
		serverMaxThreads = getUIntFromConf(pConf, SERVER_MAX_THREADS, serverMaxThreads);
	}
	else
	{
		std::cerr << "Config file '" << path << "' does not exist" << std::endl;

		if(createConfigFile(path))
		{
			std::cout << "Config file '" << path << "' was created with default values."
					<< std::endl;
		}
	}
}

unsigned int getUIntFromConf(
		Poco::AutoPtr<Poco::Util::PropertyFileConfiguration> pConf,
		std::string key,
		unsigned int defaultValue)
{
	unsigned int value = 0;

	try
	{
		value = pConf->getUInt(key);
	}
	catch (...)
	{
		value = defaultValue;
		std::cerr << "Config file does not contain a '" << key << "' value." << std::endl;
	}

	return value;
}

bool createConfigFile(std::string path)
{
    Poco::AutoPtr<Poco::Util::PropertyFileConfiguration> pConf;
	pConf = new Poco::Util::PropertyFileConfiguration();

	pConf->setUInt(SERVER_PORT_KEY, serverPort);
	pConf->setUInt(SERVER_MAX_QUEUED_KEY, serverMaxQueued);
	pConf->setUInt(SERVER_MAX_THREADS, serverMaxThreads);

	pConf->save(path);

	std::ifstream confFile(path.c_str());
	bool fileExists = confFile.good();
	confFile.close();

	return fileExists;
}
