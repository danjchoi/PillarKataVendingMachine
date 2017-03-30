#pragma once
#include <string>

class VendingMachine{
public:
	VendingMachine();
	std::string printDisplay();
	void depositCoin(char coin);
	std::string checkCoinReturn();
};