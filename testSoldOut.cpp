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

int main() 
{
	bool colaSoldout = true, chipsSoldout = false, candySoldout = true;
	VendingMachine machine1(colaSoldout, chipsSoldout, candySoldout);
	char quarter = 'Q';
	string actualDisplay1, expectedDisplay1;

	//Buying Cola Tests
	cout << "Test1: No money in machine. Trying to purchase sold out cola" << endl;
	expectedDisplay1 = "SOLD OUT";
	machine1.buyCola();
	actualDisplay1 = machine1.printDisplay();	
	compareAssert(expectedDisplay1, actualDisplay1);
	
	cout << "Checking display again" << endl;
	expectedDisplay1 = "INSERT COIN";
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);

	for(unsigned i = 0; i < 2; ++i)
	{
		cout << "Inserting $0.25" << endl;
		machine1.depositCoin(quarter);
	}

	cout << "Test2: Not enough money in machine. Trying to purchase sold out cola" << endl;
	expectedDisplay1 = "SOLD OUT";
	machine1.buyCola();
	actualDisplay1 = machine1.printDisplay();	
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Checking display again" << endl;
	expectedDisplay1 = "$0.50";
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);

	for(unsigned i = 0; i < 2; ++i)
	{
		cout << "Inserting $0.25" << endl;
		machine1.depositCoin(quarter);
	}

	cout << "Test3: Just enough money in machine. Trying to purchase sold out cola" << endl;
	expectedDisplay1 = "SOLD OUT";
	machine1.buyCola();
	actualDisplay1 = machine1.printDisplay();	
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Checking display again" << endl;
	expectedDisplay1 = "$1.00";
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Inserting $0.25" << endl;
	machine1.depositCoin(quarter);

	cout << "Test4: More than enough money in machine. Trying to purchase sold out cola" << endl;
	expectedDisplay1 = "SOLD OUT";
	machine1.buyCola();
	actualDisplay1 = machine1.printDisplay();	
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Checking display again" << endl;
	expectedDisplay1 = "$1.25";
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);

	machine1.returnCoins();

	//Buying Chips Tests
	cout << "Test5: No money in machine. Trying to purchase chips" << endl;
	expectedDisplay1 = "PRICE $0.50";
	machine1.buyChips();
	actualDisplay1 = machine1.printDisplay();	
	compareAssert(expectedDisplay1, actualDisplay1);
	
	cout << "Checking display again" << endl;
	expectedDisplay1 = "INSERT COIN";
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);

	for(unsigned i = 0; i < 1; ++i)
	{
		cout << "Inserting $0.25" << endl;
		machine1.depositCoin(quarter);
	}

	cout << "Test6: Not enough money in machine. Trying to purchase chips" << endl;
	expectedDisplay1 = "PRICE $0.50";
	machine1.buyChips();
	actualDisplay1 = machine1.printDisplay();	
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Checking display again" << endl;
	expectedDisplay1 = "$0.25";
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);

	for(unsigned i = 0; i < 1; ++i)
	{
		cout << "Inserting $0.25" << endl;
		machine1.depositCoin(quarter);
	}

	cout << "Test7: Just enough money in machine. Trying to purchase chips" << endl;
	expectedDisplay1 = "THANK YOU";
	machine1.buyChips();
	actualDisplay1 = machine1.printDisplay();	
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Checking display again" << endl;
	expectedDisplay1 = "INSERT COIN";
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);

	for(unsigned i = 0; i < 3; ++i)
	{
		cout << "Inserting $0.25" << endl;
		machine1.depositCoin(quarter);
	}

	cout << "Test8: More than enough money in machine. Trying to purchase chips" << endl;
	expectedDisplay1 = "THANK YOU";
	machine1.buyChips();
	actualDisplay1 = machine1.printDisplay();	
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Checking display again" << endl;
	expectedDisplay1 = "INSERT COIN";
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);
}
