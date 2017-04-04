#include "VendingMachine.h"

using namespace std;

VendingMachine::VendingMachine(): 
	displayChangedByOtherMember(false), colaSoldout(false), chipsSoldout(false), candySoldout(false),
	cents(0), dollars(0), returnBalance(0), display("INSERT COIN"){}

VendingMachine::VendingMachine(bool colaSoldout_in, bool chipsSoldout_in, bool candySoldout_in): 
	displayChangedByOtherMember(false), 
	colaSoldout(colaSoldout_in), chipsSoldout(chipsSoldout_in), candySoldout(candySoldout_in),
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
	dollars += cents/100;
	cents = cents%100;
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

void VendingMachine::buyCola()
{
	if(colaSoldout)
	{
		display = "SOLD OUT";
		displayChangedByOtherMember = true;
		return;
	}
	if(dollars == 0)
	{
		display = "PRICE $1.00";
	}
	else
	{
		display = "THANK YOU";
		--dollars;
		makeChange();
	}
	displayChangedByOtherMember = true;
}

void VendingMachine::buyChips()
{
	if(chipsSoldout)
	{
		display = "SOLD OUT";
		displayChangedByOtherMember = true;
		return;
	}
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
		makeChange();
	}
	displayChangedByOtherMember = true;
}

void VendingMachine::buyCandy()
{
	if(candySoldout)
	{
		display = "SOLD OUT";
		displayChangedByOtherMember = true;
		return;
	}
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
		makeChange();
	}
	displayChangedByOtherMember = true;
}

void VendingMachine::updateDisplay()
{
	if(displayChangedByOtherMember)
	{
		displayChangedByOtherMember = false;
		return;
	}
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

void VendingMachine::makeChange()
{
	returnBalance += dollars*100 + cents;
	dollars = 0;
	cents = 0;
}

string VendingMachine::returnCoins()
{
	makeChange();
	return checkCoinReturn();
}