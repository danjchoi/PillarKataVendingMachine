#include "VendingMachine.h"

using namespace std;

VendingMachine::VendingMachine(): cents(0), dollars(0) {}

string VendingMachine::printDisplay()
{
	return "INSERT COIN";
}

void VendingMachine::depositCoin(char coin)
{
	return;
}

string VendingMachine::checkCoinReturn()
{
	return "";
}