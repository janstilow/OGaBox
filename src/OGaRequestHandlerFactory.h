#pragma once

#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPRequestHandler.h>



class OGaRequestHandlerFactory: public Poco::Net::HTTPRequestHandlerFactory
{
	public:
		OGaRequestHandlerFactory();
		virtual ~OGaRequestHandlerFactory();

		Poco::Net::HTTPRequestHandler* createRequestHandler(
				const Poco::Net::HTTPServerRequest& request);

	protected:

	private:
};
