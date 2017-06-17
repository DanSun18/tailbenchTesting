#include <queue>
#include <vector>
#include <stdint.h> //for uint64_t
#include <iostream>
#include <assert.h>
int main(int argc, char* argv[]){
	std::queue< std::vector<uint64_t> > Q;
	std::vector<uint64_t> v;
	for(uint64_t i = 0; i < 5; i++)
	{
		v.push_back(i);
	}
	//print v
	std::cout << "v: [ ";
		for(int i = 0; i < 5; i++)
		{
			std::cout << v[i] << " ";
		}
		std::cout << " ]\n";
	Q.push(v);
	v.clear();
	std::cout << "v is cleared";
	assert(v.empty());
	if(Q.front().empty())
	{
		std::cout << "the vector inside queue is also cleared\n"; 
	}
	else
	{
		std::cout << "v: [ ";
		for(int i = 0; i < 5; i++)
		{
			std::cout << (Q.front())[i] << " ";
		}
		std::cout << " ]\n";
	}

}