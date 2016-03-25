#pragma once

#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPRequestHandler.h>



class FileHandler: public Poco::Net::HTTPRequestHandler
{
	public:
		FileHandler();
		virtual ~FileHandler();

		void handleRequest(
				Poco::Net::HTTPServerRequest& request,
				Poco::Net::HTTPServerResponse& response);


	protected:

	private:
};
