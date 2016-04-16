#pragma once

#include "OGaUser.h"

#include <Poco/Net/WebSocket.h>



class OGaUserSocket
{
	public:
		OGaUserSocket(Poco::Net::WebSocket &w, std::shared_ptr<OGaUser> u);
		~OGaUserSocket();

	private:
		Poco::Net::WebSocket &w;
		std::shared_ptr<OGaUser> u;
};

