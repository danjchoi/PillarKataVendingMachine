#include "VendingMachine.h"

using namespace std;

VendingMachine::VendingMachine(): 
	cents(0), dollars(0), returnBalance(0), display("INSERT COIN"){}

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
			returnBalance += 1;
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
	//Alternative way to manage money.
	string returnBalanceString = "$" + to_string(returnBalance/100) + ".";
	if(returnBalance%100 < 10)
	{
		returnBalanceString += "0";
	}
	returnBalanceString += to_string(returnBalance%100);

	//Checking the coin return also means taking the coins
	returnBalance = 0;
	
	return returnBalanceString;
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
			display += "0";
		}
		display += to_string(cents); 
	}
}

void VendingMachine::buyCola()
{
	if(dollars == 0)
	{
		display = "PRICE $1.00";
	}
	else
	{
		display = "THANK YOU";
		--dollars;
	}
}

void VendingMachine::buyChips()
{
	if(cents < 50 && dollars == 0)
	{
		display = "PRICE $0.50";
	}
	else
	{
		display = "THANK YOU";
		if(cents < 50)
		{
			--dollars;
			cents += 100;
		}
		cents -= 50;
	}
}

void VendingMachine::buyCandy()
{
	if(cents < 65 && dollars == 0)
	{
		display = "PRICE $0.65";
	}
	else
	{
		display = "THANK YOU";
		if(cents < 65)
		{
			--dollars;
			cents += 100;
		}
		cents -= 65;
	}
}