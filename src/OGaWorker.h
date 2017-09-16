#ifndef OGAWORKER_H
#define OGAWORKER_H

#include <thread>


class OGaWorker
{
	public:
		OGaWorker();
		virtual ~OGaWorker();

		void run();
		void join();
	protected:

	private:
		std::thread thread;
		volatile bool running;
};

#endif // OGAWORKER_H
