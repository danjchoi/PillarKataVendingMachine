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
	switch(coin){
		case('N'):
			cents += 5;
			break;

		case('D'):
			cents += 10;
			break;

		case('Q'):
			cents += 25;
			break;
		
		case('P'):
			//TODO: Add to coin return
			break;
		
		default:
			//This case shouldn't occur
			break;
	}
	//
	dollars = cents/100;
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
		if(cents < 10)
		{
			display += '0';
		}
		display += to_string(cents); 
	}
	
}