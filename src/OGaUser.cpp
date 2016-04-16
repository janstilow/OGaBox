#include "OGaUser.h"

#include <iostream>



OGaUser::OGaUser(const std::string &id)
{
	std::cout << "new user created: " << id << std::endl;
	this->id = id;
	this->webSocket = 0;
}

bool OGaUser::isThisUser(const std::string &id) const
{
	if(this->id.compare(id) == 0)
	{
		return true;
	}
	return false;
}

void OGaUser::setWebSocket(Poco::Net::WebSocket *w)
{
	Poco::ScopedLock<Poco::Mutex> lock(this->mutex);

	if(this->webSocket != 0)
	{
		this->webSocket->shutdown();
	}

	this->webSocket = w;
}

void OGaUser::clearWebSocket(Poco::Net::WebSocket *w)
{
	Poco::ScopedLock<Poco::Mutex> lock(this->mutex);

	if(this->webSocket == w)
	{
		this->webSocket = 0;
	}
}

void OGaUser::sendMessage(char *data, int len, int flags)
{
	Poco::ScopedLock<Poco::Mutex> lock(this->mutex);

	if(this->webSocket != 0)
	{
		this->webSocket->sendFrame(data, len, flags);
	}
}

