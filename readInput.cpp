#include <fstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <time.h>
#include <queue>
#include <iostream>
#include <string>
#include <unistd.h>

class QPScombo{
	private:
		uint64_t duration;
		double QPS;
	public:
		QPScombo(uint64_t dur, double _QPS){
			duration = dur;
			QPS = _QPS;
		}
		double getQPS(){return QPS;}
		uint64_t getDuration(){return duration;}
};

uint64_t getCurNs() {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    uint64_t t = ts.tv_sec*1000*1000*1000 + ts.tv_nsec;
    return t;
}

int main(int argc, char* argv[]) {
	
	std::ifstream infile("test.input");
	//take input
	uint64_t duration;
	double QPS;
	std::queue<QPScombo*> QPStiming;
	while(infile >> duration >> QPS)
	{
		QPStiming.push(new QPScombo(duration, QPS));
	}
	//progress
	uint64_t startingNs = getCurNs();
	uint64_t currentNs;
	double currentQPS = QPStiming.front()->getQPS();
	std::cout << "Started at " << (startingNs/1000000000) << ", current QPS is " << currentQPS << "\n";
	while(true)
	{
		currentNs = getCurNs();
		if(currentNs - startingNs >= (QPStiming.front()->getDuration())*1000*1000*1000)
		{
			QPStiming.pop();
			if(QPStiming.empty())
				exit(0);
			startingNs = getCurNs();
			currentQPS = QPStiming.front()->getQPS();
			std::cout << "Current time is " << (startingNs/1000000000) << ", current QPS is " << currentQPS << "\n";
		}
			sleep(0.5);
	}
}