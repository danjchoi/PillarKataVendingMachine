#include <cassert>
#include <iostream>
#include <string>

#include "VendingMachine.h"

using namespace std;

void compareAssert(string expected, string actual)
{
	cout << "expected:\t" << expected << endl;
	cout << "actual:  \t" << actual << endl;
	assert(expected == actual);
	cout << "PASS!!!!!!!" << endl << endl;
	return;
}

void testBuyingCola();
void testBuyingChips();
void testBuyingCandy();

int main() 
{
	testBuyingCola();
	testBuyingChips();
	testBuyingCandy();
}

void testBuyingCola()
{
	VendingMachine machine1;
	char quarter = 'Q';
	string actualDisplay1, expectedDisplay1;

	for(unsigned i = 0; i < 5; ++i)
	{
		cout << "Inserting $0.25" << endl;
		machine1.depositCoin(quarter);
	}
	//Buying Cola Tests
	cout << "Test1: More than enough money in machine. Trying to purchase cola" << endl;
	expectedDisplay1 = "THANK YOU";
	machine1.buyCola();
	actualDisplay1 = machine1.printDisplay();	
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Checking display again" << endl;
	expectedDisplay1 = "INSERT COIN";
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Checking coin return" << endl;
	expectedDisplay1 = "$0.25";
	actualDisplay1 = machine1.checkCoinReturn();
	compareAssert(expectedDisplay1, actualDisplay1);

	for(unsigned i = 0; i < 9; ++i)
	{
		cout << "Inserting $0.25" << endl;
		machine1.depositCoin(quarter);
	}

	cout << "Test2: $2.25 in machine. Trying to purchase cola" << endl;
	expectedDisplay1 = "THANK YOU";
	machine1.buyCola();
	actualDisplay1 = machine1.printDisplay();	
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Checking display again" << endl;
	expectedDisplay1 = "INSERT COIN";
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Checking coin return" << endl;
	expectedDisplay1 = "$1.25";
	actualDisplay1 = machine1.checkCoinReturn();
	compareAssert(expectedDisplay1, actualDisplay1);

}

void testBuyingChips()
{
	VendingMachine machine1;
	char quarter = 'Q';
	string actualDisplay1, expectedDisplay1;

	for(unsigned i = 0; i < 3; ++i)
	{
		cout << "Inserting $0.25" << endl;
		machine1.depositCoin(quarter);
	}
	//Buying Chips Tests
	cout << "Test1: More than enough money in machine. Trying to purchase chips" << endl;
	expectedDisplay1 = "THANK YOU";
	machine1.buyChips();
	actualDisplay1 = machine1.printDisplay();	
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Checking display again" << endl;
	expectedDisplay1 = "INSERT COIN";
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Checking coin return" << endl;
	expectedDisplay1 = "$0.25";
	actualDisplay1 = machine1.checkCoinReturn();
	compareAssert(expectedDisplay1, actualDisplay1);

	for(unsigned i = 0; i < 7; ++i)
	{
		cout << "Inserting $0.25" << endl;
		machine1.depositCoin(quarter);
	}

	cout << "Test2: $1.75 in machine. Trying to purchase chips" << endl;
	expectedDisplay1 = "THANK YOU";
	machine1.buyChips();
	actualDisplay1 = machine1.printDisplay();	
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Checking display again" << endl;
	expectedDisplay1 = "INSERT COIN";
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Checking coin return" << endl;
	expectedDisplay1 = "$1.25";
	actualDisplay1 = machine1.checkCoinReturn();
	compareAssert(expectedDisplay1, actualDisplay1);
}

void testBuyingCandy()
{
	VendingMachine machine1;
	char quarter = 'Q';
	string actualDisplay1, expectedDisplay1;

	for(unsigned i = 0; i < 3; ++i)
	{
		cout << "Inserting $0.25" << endl;
		machine1.depositCoin(quarter);
	}
	//Buying Candy Tests
	cout << "Test1: More than enough money in machine. Trying to purchase candy" << endl;
	expectedDisplay1 = "THANK YOU";
	machine1.buyCandy();
	actualDisplay1 = machine1.printDisplay();	
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Checking display again" << endl;
	expectedDisplay1 = "INSERT COIN";
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Checking coin return" << endl;
	expectedDisplay1 = "$0.10";
	actualDisplay1 = machine1.checkCoinReturn();
	compareAssert(expectedDisplay1, actualDisplay1);

	for(unsigned i = 0; i < 7; ++i)
	{
		cout << "Inserting $0.25" << endl;
		machine1.depositCoin(quarter);
	}

	cout << "Test2: $1.75 in machine. Trying to purchase candy" << endl;
	expectedDisplay1 = "THANK YOU";
	machine1.buyCandy();
	actualDisplay1 = machine1.printDisplay();	
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Checking display again" << endl;
	expectedDisplay1 = "INSERT COIN";
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Checking coin return" << endl;
	expectedDisplay1 = "$1.10";
	actualDisplay1 = machine1.checkCoinReturn();
	compareAssert(expectedDisplay1, actualDisplay1);
}