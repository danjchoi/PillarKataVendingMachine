#pragma once
#include <string>

class VendingMachine{
public:
	VendingMachine();
	VendingMachine(bool exactChange_in);
	VendingMachine(bool colaSoldout_in, bool chipsSoldout_in, bool candySoldout_in);
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
	bool exactChange;
	bool colaSoldout;
	bool chipsSoldout;
	bool candySoldout;
	int cents;
	int dollars;
	int returnBalance;
	std::string display;
};