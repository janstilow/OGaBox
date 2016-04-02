#include "OGaUser.h"

#include <iostream>



OGaUser::OGaUser(const std::string &id)
{
	std::cout << "new user created: " << id << std::endl;
	this->id = id;
}

bool OGaUser::isThisUser(const std::string &id) const
{
	if(this->id.compare(id) == 0)
	{
		return true;
	}
	return false;
}

