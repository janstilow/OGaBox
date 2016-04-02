#pragma once

#include <Poco/Mutex.h>

#include <string>
#include <vector>
#include <memory>



class OGaRoom;

class OGaUser
{
	friend class OGaService;
	protected:
		OGaUser(const std::string &id);

		bool isThisUser(const std::string &id) const;

	public:
		void addRoom(std::shared_ptr<OGaRoom> room);

	private:
		Poco::Mutex mutex;
		std::string id;
		std::vector< std::shared_ptr<OGaRoom> > rooms;

		// Are not to be implemented because we will never use them.
		OGaUser(OGaUser const&);
		void operator=(OGaUser const&);
};

