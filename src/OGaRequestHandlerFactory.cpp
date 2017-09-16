#include "OGaRequestHandlerFactory.h"

#include "FileHandler.h"
#include "OGaWebSocket.h"

#include <iostream>



OGaRequestHandlerFactory::OGaRequestHandlerFactory(Environment &environment):
	environment(environment)
{

}

OGaRequestHandlerFactory::~OGaRequestHandlerFactory()
{

}

Poco::Net::HTTPRequestHandler* OGaRequestHandlerFactory::createRequestHandler(
		const Poco::Net::HTTPServerRequest& request)
{
	std::cout << "host: " << request.getHost() << std::endl;
	std::cout << "content length: " << request.getContentLength() << std::endl;
	std::cout << "get URL: " << request.getURI() << std::endl;
	if(request.getURI().compare("/ws") == 0)
	{
		std::cout << "a" << std::endl;
		if(
				request.find("Upgrade") != request.end() &&
				Poco::icompare(request["Upgrade"], "websocket") == 0)
		{
			std::cout << "b" << std::endl;
			return new OGaWebSocket(this->environment);
		}
	}
	return new FileHandler();
}

