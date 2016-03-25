#include "OGaRequestHandlerFactory.h"

#include "FileHandler.h"



OGaRequestHandlerFactory::OGaRequestHandlerFactory()
{

}

OGaRequestHandlerFactory::~OGaRequestHandlerFactory()
{

}

Poco::Net::HTTPRequestHandler* OGaRequestHandlerFactory::createRequestHandler(
		const Poco::Net::HTTPServerRequest& request)
{
	return new FileHandler();
}
