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
		OGaUser(const std::string &id);

		bool isThisUser(const std::string &id) const;

	public:
		void addRoom(std::shared_ptr<OGaRoom> room);

		void setWebSocket(Poco::Net::WebSocket *w);
		void clearWebSocket(Poco::Net::WebSocket *w);

		void sendMessage(char *data, int len, int flags);

	private:
		Poco::Mutex mutex;
		std::string id;
		std::vector< std::shared_ptr<OGaRoom> > rooms;
		Poco::Net::WebSocket *webSocket;

		// Are not to be implemented because we will never use them.
		OGaUser(OGaUser const&);
		void operator=(OGaUser const&);
};

