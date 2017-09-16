#pragma once

#include <Poco/Mutex.h>
#include <Poco/Net/WebSocket.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>

#include <string>
#include <vector>
#include <memory>



class OGaRoom;

class OGaUser
{
	friend class OGaService;
	protected:
		OGaUser(const std::string &uuid);

		bool isThisUser(const std::string &uuid) const;

	public:
		void addRoom(std::shared_ptr<OGaRoom> room);

		void setWebSocket(std::shared_ptr<Poco::Net::WebSocket> webSocket);

		std::string getUUID();
		std::shared_ptr<Poco::Net::WebSocket> getWebSocket();

		void sendMessage(char *data, int len, int flags);

	private:
		Poco::Mutex mutex;
		std::string uuid;
		std::vector< std::shared_ptr<OGaRoom> > rooms;
		std::shared_ptr<Poco::Net::WebSocket> webSocket;

		// Are not to be implemented because we will never use them.
		OGaUser(OGaUser const&);
		void operator=(OGaUser const&);
};

