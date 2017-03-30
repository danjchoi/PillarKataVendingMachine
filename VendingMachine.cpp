#include "VendingMachine.h"

using namespace std;

VendingMachine::VendingMachine(): cents(0), dollars(0), display("INSERT COIN") {}

string VendingMachine::printDisplay()
{
	updateDisplay();
	return display;
}

void VendingMachine::depositCoin(char coin)
{
	return;
}

string VendingMachine::checkCoinReturn()
{
	return "";
}

void VendingMachine::updateDisplay()
{
	if(dollars + cents == 0)
	{
		display = "INSERT COIN";
	}
	else
	{
		display = "$";
		display += to_string(dollars);
		display += ".";
		display += to_string(cents); 
	}
	
}