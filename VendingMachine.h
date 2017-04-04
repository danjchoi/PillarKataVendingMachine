#pragma once
#include <string>

class VendingMachine{
public:
	VendingMachine();
	std::string printDisplay();
	void depositCoin(char coin);
	std::string checkCoinReturn();
	void buyCola();
	void buyChips();
	void buyCandy();
	std::string returnCoins();
private:
	void updateDisplay();
	void makeChange();
	bool displayChangedByOtherMember;
	int cents;
	int dollars;
	int returnBalance;
	std::string display;
};