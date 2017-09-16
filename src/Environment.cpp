#include "Environment.h"

#include <Poco/Net/Socket.h>
#include <Poco/Net/SocketNotification.h>

#include<iostream>

Environment::Environment():
	environmentThread(&Environment::run, this)
{
	this->running = true;
	for (int i = 0; i < 16; i++)
	{
		this->workerThreads.push_back(new OGaWorker());
	}
}

Environment::~Environment()
{
	for (OGaWorker* worker : this->workerThreads)
	{
		worker->join();
		delete worker;
	}
}

void Environment::addUser(std::shared_ptr<OGaUser> user)
{
	std::lock_guard<std::mutex> lock(this->mutex);

	this->users.insert({user->getUUID(), user});
}

void Environment::removeUser(std::shared_ptr<OGaUser> user)
{
	this->removeUser(user->getUUID());
}

void Environment::removeUser(std::string userUUID)
{
	std::lock_guard<std::mutex> lock(this->mutex);

	this->users.erase(userUUID);
}

void Environment::startListening()
{


}

void Environment::run()
{

	while (this->running)
	{
		Poco::Net::Socket::SocketList readList;
		Poco::Net::Socket::SocketList writeList;
		Poco::Net::Socket::SocketList errorList;

		for (std::pair< const std::string, std::shared_ptr<OGaUser> > userPair : this->users)
		{
			readList.push_back(*userPair.second->getWebSocket());
			Poco::Net::WebSocket.
		}

		Poco::Net::Socket::select(readList, writeList, errorList, Poco::Timespan(1, 0));

		for (Poco::Net::Socket socket : readList)
		{
			//Poco::Net::SocketNotification sockNot()
			//Pouco::NotificationQueue.enqueueNotification()
			char buffer[1024];
			int flags;
			int n;
			std::cout << "in while, do" << std::endl;
			n = ((Poco::Net::WebSocket)socket).receiveFrame(buffer, sizeof(buffer), flags);
			std::cout << "n: " << n << ", flags: " << flags << std::endl;
			std::cout << "data: " << std::string(buffer, buffer + n) << std::endl;
			//room->sendMessage(buffer, n, flags);
		}
	}

}

void Environment::join()
{
	this->running = false;
	this->environmentThread.join();
}
