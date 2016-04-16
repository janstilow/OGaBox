#include "OGaRoom.h"

#include "OGaUser.h"

#include <iostream>



OGaRoom::OGaRoom(const std::string &id)
{
	std::cout << "created new room: " << id << std::endl;
}

bool OGaRoom::isThisRoom(const std::string &id)
{
	if(this->id.compare(id) == 0)
	{
		return true;
	}
	return false;
}

void OGaRoom::addUser(std::shared_ptr<OGaUser> user)
{
	Poco::ScopedLock<Poco::Mutex> lock(this->mutex);

	for(std::shared_ptr<OGaUser> u: this->users)
	{
		if( u.get() == user.get() )
		{
			return;
		}
	}

	this->users.push_back(user);
}

void OGaRoom::sendMessage(char *data, int len, int flags)
{
	Poco::ScopedLock<Poco::Mutex> lock(this->mutex);

	for(std::shared_ptr<OGaUser> u: this->users)
	{
		u->sendMessage(data, len, flags);
	}
}

