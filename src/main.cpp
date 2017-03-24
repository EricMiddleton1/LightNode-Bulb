#include "LightNode/LightNode.hpp"
#include "Bulb.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <thread>
#include <chrono>

int main(int argc, char **argv) {
	if(argc < 3) {
		std::cout << "Usage: " << argv[0] << " NodeName ip0 port0 ip1 port1..." << std::endl;
		return 1;
	}

	std::vector<std::shared_ptr<LightStrip>> bulbs;

	for(unsigned int i = 2; i < (argc-1); i += 2) {
		std::cout << "Constructing bulb at " << argv[i] << ":" << argv[i+1] << std::endl;

		bulbs.push_back(std::make_shared<Bulb>(argv[i], std::stoi(argv[i+1])));
	}
	
	std::cout << "Starting LightNode as \"" << argv[1] << "\"" << std::endl;

	LightNode node(bulbs, argv[1]);

	while(1) {
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	}

	return 0;
}
