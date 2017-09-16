#include "OGaWorker.h"

#include <Poco/NotificationQueue.h>
#include <Poco/Notification.h>

#include <iostream>

OGaWorker::OGaWorker():
	thread(&OGaWorker::run, this)
{
	this->running = false; // TODO: set to true
}

OGaWorker::~OGaWorker()
{
	//dtor
}

void OGaWorker::run()
{
	std::cout << "hallo" << std::endl;
	while(running)
	{
		Poco::Notification::Ptr notification = Poco::NotificationQueue::defaultQueue().waitDequeueNotification();
		if (!notification)
		{
            return;
		}
	}
}

void OGaWorker::join()
{
	this->running = false;
	this->thread.join();
}
