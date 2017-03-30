#pragma once
#include <string>

class VendingMachine{
public:
	VendingMachine();
	std::string printDisplay();
	void depositCoin(char coin);
	std::string checkCoinReturn();
private:
	void updateDisplay();
	int cents;
	int dollars;
	int returnBalance;
	std::string display;
};