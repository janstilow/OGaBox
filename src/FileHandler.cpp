#include "FileHandler.h"



FileHandler::FileHandler()
{

}

FileHandler::~FileHandler()
{

}

void FileHandler::handleRequest(
		Poco::Net::HTTPServerRequest& request,
		Poco::Net::HTTPServerResponse& response)
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
