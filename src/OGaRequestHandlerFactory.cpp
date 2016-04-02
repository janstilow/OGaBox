#include "OGaRequestHandlerFactory.h"

#include "FileHandler.h"

#include <iostream>



OGaRequestHandlerFactory::OGaRequestHandlerFactory()
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
		
	}
	return new FileHandler();
}
