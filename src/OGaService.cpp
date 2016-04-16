#include "OGaService.h"

#include <Poco/UUID.h>
#include <Poco/UUIDGenerator.h>

#define SESSION_VAR_NAME "uid"



OGaService::OGaService()
{
	std::shared_ptr<OGaRoom> r( new OGaRoom("lobby") );
	this->rooms.push_back(r);
}



OGaService& OGaService::getInstance()
{
	static OGaService service;
	return service;
}




OGaServiceContext OGaService::getContext(Poco::Net::HTTPServerRequest &request)
{
	Poco::ScopedLock<Poco::Mutex> lock(this->mutex);

	std::shared_ptr<OGaUser> user;
	std::shared_ptr<OGaRoom> room;
	user = this->getUser(request);
	room = this->getRoom(request);
	OGaServiceContext c(user, room);

	return c;
}

std::shared_ptr<OGaUser> OGaService::getUser(Poco::Net::HTTPServerRequest &request)
{
	std::string uid;
	Poco::Net::NameValueCollection c;
	request.getCookies(c);
	if( c.has(SESSION_VAR_NAME) )
	{
		uid = this->getSaveCollectionValue(c, SESSION_VAR_NAME);
	}
	else
	{
		uid = this->getSaveCollectionValue(request, SESSION_VAR_NAME);
	}
	return this->findOrCreateUser(uid);
}

std::shared_ptr<OGaRoom> OGaService::getRoom(Poco::Net::HTTPServerRequest &request)
{
	std::string rid = "";
	return this->findOrCreateRoom(rid);
}

std::shared_ptr<OGaUser> OGaService::findOrCreateUser(const std::string &uid)
{
	if(uid.length() == 0)
	{
		std::shared_ptr<OGaUser> u( new OGaUser( this->getUUID() ) );
		return u;
	}

	for(std::shared_ptr<OGaUser> i: this->users)
	{
		if( i->isThisUser(uid) )
		{
			return i;
		}
	}

	std::shared_ptr<OGaUser> u( new OGaUser(uid) );
	return u;
}

std::shared_ptr<OGaRoom> OGaService::findOrCreateRoom(const std::string &rid)
{
	if(rid.length() > 0)
	{
		std::shared_ptr<OGaRoom> r( new OGaRoom(rid) );
		return r;
	}
	return this->rooms[0];
}

std::string OGaService::getSaveCollectionValue(
		Poco::Net::NameValueCollection &nc,
		const std::string &name)
{
	try
	{
		return nc.get(name);
	}
	catch(...)
	{
	}
	return "";
}

std::string OGaService::getUUID()
{
	Poco::UUIDGenerator &generator = Poco::UUIDGenerator::defaultGenerator();
	Poco::UUID uuid( generator.create() );
	return uuid.toString();
}

