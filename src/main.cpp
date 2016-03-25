#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerParams.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/ServerSocket.h>
#include <iostream>
#include "Config.h"




class RootHandler: public Poco::Net::HTTPRequestHandler
{
	public:
		void handleRequest(Poco::Net::HTTPServerRequest& request, Poco::Net::HTTPServerResponse& response)
		{
			//Application& app = Application::instance();
			//app.logger().information("Request from " + request.clientAddress().toString());
			response.setChunkedTransferEncoding(true);
			response.setContentType("text/html");
			std::ostream& ostr = response.send();
			ostr << "<html><head><title>HTTP Server powered by POCO C++ Libraries for OGaBox!</title></head>";
			ostr << "<body>OGaBox!";
			ostr << "</body></html>";
		}
};




class MyRequestHandlerFactory: public Poco::Net::HTTPRequestHandlerFactory
{
	public:
		MyRequestHandlerFactory()
		{
		}

		Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request)
		{
			return new RootHandler();
		}
};




int main(int argc, char **argv)
{
	Config::loadConfig("OGaBox.cfg");
	std::cout << "OGaBox!Service v0.0" << std::endl;
	Poco::UInt16 port = Config::getServerPort();
	std::cout << "port: " << port << std::endl;

	Poco::Net::HTTPServerParams* pParams = new Poco::Net::HTTPServerParams;

	pParams->setMaxQueued(Config::getMaxQueued());
	pParams->setMaxThreads(Config::getMaxThreads());
	Poco::Net::ServerSocket svs(port);
	Poco::Net::HTTPServer srv(new MyRequestHandlerFactory(), svs, pParams);
	srv.start();

	std::cout << "Hit return to quit service." << std::endl;
	std::string t;
	std::getline(std::cin, t);

	srv.stop();

	return 0;
}

