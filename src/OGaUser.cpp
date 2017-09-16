#include "OGaUser.h"

#include <iostream>



OGaUser::OGaUser(const std::string &uuid)
{
	std::cout << "new user created: " << uuid << std::endl;
	this->uuid = uuid;
	this->webSocket = 0;
}

bool OGaUser::isThisUser(const std::string &uuid) const
{
	if(this->uuid.compare(uuid) == 0)
	{
		return true;
	}
	return false;
}

void OGaUser::setWebSocket(std::shared_ptr<Poco::Net::WebSocket> w)
{
	Poco::ScopedLock<Poco::Mutex> lock(this->mutex);

	if(this->webSocket != 0)
	{
		this->webSocket->shutdown();
	}

	this->webSocket = w;
}

std::string OGaUser::getUUID()
{
	return this->uuid;
}

std::shared_ptr<Poco::Net::WebSocket> OGaUser::getWebSocket()
{
    return this->webSocket;
}

void OGaUser::sendMessage(char *data, int len, int flags)
{
	Poco::ScopedLock<Poco::Mutex> lock(this->mutex);

	if(this->webSocket != 0)
	{
		this->webSocket->sendFrame(data, len, flags);
	}
}

