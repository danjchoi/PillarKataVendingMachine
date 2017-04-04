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
	VendingMachine machine1;
	char quarter = 'Q', dime = 'D', nickel = 'N', penny = 'P';
	string actualDisplay1, expectedDisplay1;

	//Press return on empty machine
	expectedDisplay1 = "$0.00";
	actualDisplay1 = machine1.returnCoins();
	compareAssert(expectedDisplay1, actualDisplay1);

	//Insert a quarter and press return
	cout << "Inserting $0.25" << endl;
	machine1.depositCoin(quarter);
	expectedDisplay1 = "$0.25";
	actualDisplay1 = machine1.returnCoins();
	compareAssert(expectedDisplay1, actualDisplay1);

	//Checking a recently emptied machine
	expectedDisplay1 = "$0.00";
	actualDisplay1 = machine1.returnCoins();
	compareAssert(expectedDisplay1, actualDisplay1);

	//Insert a dime and press return
	cout << "Inserting $0.10" << endl;
	machine1.depositCoin(dime);
	expectedDisplay1 = "$0.10";
	actualDisplay1 = machine1.returnCoins();
	compareAssert(expectedDisplay1, actualDisplay1);

	//Insert a nickel and press return
	cout << "Inserting $0.05" << endl;
	machine1.depositCoin(nickel);
	expectedDisplay1 = "$0.05";
	actualDisplay1 = machine1.returnCoins();
	compareAssert(expectedDisplay1, actualDisplay1);

	//Insert a penny and press return
	cout << "Inserting $0.01" << endl;
	machine1.depositCoin(penny);
	expectedDisplay1 = "$0.01";
	actualDisplay1 = machine1.returnCoins();
	compareAssert(expectedDisplay1, actualDisplay1);

	//Insert a normal coin + penny combination and press return
	cout << "Inserting $0.25" << endl;
	machine1.depositCoin(quarter);
	cout << "Inserting $0.01" << endl;
	machine1.depositCoin(penny);
	//Checking penny behavior
	expectedDisplay1 = "$0.25";
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);
	
	expectedDisplay1 = "$0.26";
	actualDisplay1 = machine1.returnCoins();
	compareAssert(expectedDisplay1, actualDisplay1);

	//Insert over a dollar (1.25) and press return
	for(unsigned i = 0; i < 5; ++i)
	{
		cout << "Inserting $0.25" << endl;
		machine1.depositCoin(quarter);
	}
	expectedDisplay1 = "$1.25";
	actualDisplay1 = machine1.returnCoins();
	compareAssert(expectedDisplay1, actualDisplay1);

}
