#pragma once
#include <string>

class VendingMachine{
public:
	VendingMachine();
	std::string printDisplay();
	void depositCoin(char coin);
	std::string checkCoinReturn();
private:
	std::string makeBalance();
	int cents;
	int dollars;
};