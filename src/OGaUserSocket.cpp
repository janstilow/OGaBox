#include "OGaUserSocket.h"



OGaUserSocket::OGaUserSocket(Poco::Net::WebSocket &w, std::shared_ptr<OGaUser> u) :
	w(w)
{
	this->u = u;

	this->u->setWebSocket(&this->w);
}

OGaUserSocket::~OGaUserSocket()
{
	this->u->clearWebSocket(&this->w);
}

