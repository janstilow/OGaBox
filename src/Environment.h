#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include<unordered_map>
#include<mutex>
#include<memory>
#include<thread>
#include "OGaUser.h"
#include "OGaWorker.h"

#include <Poco/Net/WebSocket.h>


class Environment
{
	public:
		Environment();
		virtual ~Environment();

		void addUser(std::shared_ptr<OGaUser> user);
		void removeUser(std::shared_ptr<OGaUser> user);
		void removeUser(std::string userUUID);

		void startListening();

		void run();
		void join();

	private:
		std::mutex mutex;
		std::thread environmentThread;

		std::list<OGaWorker*> workerThreads;

		std::unordered_map<std::string, std::shared_ptr<OGaUser> > users;

		bool running;
};

#endif // ENVIRONMENT_H
