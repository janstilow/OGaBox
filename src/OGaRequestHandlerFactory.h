#pragma once

#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPRequestHandler.h>

#include "Environment.h"


class OGaRequestHandlerFactory: public Poco::Net::HTTPRequestHandlerFactory
{
	public:
		OGaRequestHandlerFactory(Environment &environment);
		virtual ~OGaRequestHandlerFactory();

		Poco::Net::HTTPRequestHandler* createRequestHandler(
				const Poco::Net::HTTPServerRequest& request);

	protected:

	private:
		Environment &environment;
};
