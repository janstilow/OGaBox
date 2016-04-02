#pragma once

#include <Poco/Mutex.h>

#include <string>
#include <vector>
#include <memory>



class OGaUser;

class OGaRoom
{
	friend class OGaService;
	protected:
		OGaRoom(const std::string &id);

		bool isThisRoom(const std::string &id);

	public:
		void addUser(std::shared_ptr<OGaUser> user);

	private:
		Poco::Mutex mutex;
		std::string id;
		std::vector< std::shared_ptr<OGaUser> > users;

		// Are not to be implemented because we will never use them.
		OGaRoom(OGaRoom const&);
		void operator=(OGaRoom const&);
};

