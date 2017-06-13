#include "read_input.h"
#include "helpers.h"

int main(int argc, char* argv[]) {
	
	std::string fileName = "test.input";
	readInput(fileName);
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

void readInput(std::string fileName){
	std::ifstream infile(fileName.c_str());
	//take input
	uint64_t duration;
	double QPS;
	
	while(infile >> duration >> QPS)
	{
		QPStiming.push(new QPScombo(duration, QPS));
	}
}