#pragma once

#include "OGaServiceContext.h"

#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Mutex.h>

#include <vector>
#include <memory>



class OGaService
{
	private:
		OGaService();

	public:
		static OGaService& getInstance();

		OGaServiceContext getContext(Poco::Net::HTTPServerRequest &request);

		void setResponseCookies(Poco::Net::HTTPResponse &response);

	private:
		Poco::Mutex mutex;
		std::vector< std::shared_ptr<OGaUser> > users;
		std::vector< std::shared_ptr<OGaRoom> > rooms;

		std::shared_ptr<OGaUser> getUser(Poco::Net::HTTPServerRequest &request);
		std::shared_ptr<OGaRoom> getRoom(Poco::Net::HTTPServerRequest &request);

		std::shared_ptr<OGaUser> findOrCreateUser(const std::string &uid);
		std::shared_ptr<OGaRoom> findOrCreateRoom(const std::string &rid);

		std::string getSaveCollectionValue(
				Poco::Net::NameValueCollection &nc,
				const std::string &name);

		std::string getUUID();

		// Are not to be implemented because we will never allow to use them.
		OGaService(OGaService const&);
		void operator=(OGaService const&);
};

