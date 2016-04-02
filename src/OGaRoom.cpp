#include "OGaRoom.h"

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

