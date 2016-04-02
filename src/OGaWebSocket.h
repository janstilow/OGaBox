#pragma once

#include "Poco/Net/HTTPRequestHandler.h"



class OGaWebSocket : public Poco::Net::HTTPRequestHandler
{
	public:
		OGaWebSocket();
		~OGaWebSocket();

		void handleRequest(
				Poco::Net::HTTPServerRequest& request,
				Poco::Net::HTTPServerResponse& response);
};

