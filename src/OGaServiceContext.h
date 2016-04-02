#pragma once

#include "OGaUser.h"
#include "OGaRoom.h"

#include <memory>



class OGaServiceContext
{
	public:
		OGaServiceContext(std::shared_ptr<OGaUser> user, std::shared_ptr<OGaRoom> room);

		std::shared_ptr<OGaUser> getUser();
		std::shared_ptr<OGaRoom> getRoom();

	private:
		std::shared_ptr<OGaUser> user;
		std::shared_ptr<OGaRoom> room;
};

