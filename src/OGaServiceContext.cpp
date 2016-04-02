#include "OGaServiceContext.h"



OGaServiceContext::OGaServiceContext(std::shared_ptr<OGaUser> user, std::shared_ptr<OGaRoom> room)
{
	this->user = user;
	this->room = room;
}

std::shared_ptr<OGaUser> OGaServiceContext::getUser()
{
	return user;
}

std::shared_ptr<OGaRoom> OGaServiceContext::getRoom()
{
	return room;
}

