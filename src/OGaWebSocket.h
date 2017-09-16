#pragma once

#include "Poco/Net/HTTPRequestHandler.h"
#include "Environment.h"


class OGaWebSocket : public Poco::Net::HTTPRequestHandler
{
	public:
		OGaWebSocket(Environment &environment);
		~OGaWebSocket();

		void handleRequest(
				Poco::Net::HTTPServerRequest& request,
				Poco::Net::HTTPServerResponse& response);

	private:
		Environment &environment;
};

