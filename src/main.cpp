#include <Poco/Net/HTTPServerParams.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/ServerSocket.h>
#include <iostream>

#include "Config.h"
#include "OGaRequestHandlerFactory.h"



int main(int argc, char **argv)
{
	Config::initConfig(argc, argv);
	std::cout << "OGaBox!Service v0.0" << std::endl;
	Poco::UInt16 port = Config::getServerPort();
	std::cout << "port: " << port << std::endl;

	Poco::Net::HTTPServerParams* pParams = new Poco::Net::HTTPServerParams;

	pParams->setMaxQueued(Config::getMaxQueued());
	pParams->setMaxThreads(Config::getMaxThreads());
	Poco::Net::ServerSocket svs(port);
	Poco::Net::HTTPServer srv(new OGaRequestHandlerFactory(), svs, pParams);
	srv.start();

	std::cout << "Hit return to quit service." << std::endl;
	std::string t;
	std::getline(std::cin, t);

	srv.stop();

	return 0;
}

