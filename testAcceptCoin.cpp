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
	VendingMachine machine1, machine2, machine3, machine4;
	char penny = 'P', nickel = 'N', dime = 'D', quarter = 'Q';
	string actualDisplay1, actualDisplay2, actualDisplay3, actualDisplay4;
	string expectedDisplay1, expectedDisplay2, expectedDisplay3, expectedDisplay4;
	
	cout << "Checking initial display" << endl;
	expectedDisplay1 = "INSERT COIN";
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Adding a nickel to an empty machine" << endl;
	expectedDisplay1 = "$0.05";
	machine1.depositCoin(nickel);
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Adding a dime to an empty machine" << endl;
	expectedDisplay2 = "$0.10";
	machine2.depositCoin(dime);
	actualDisplay2 = machine2.printDisplay();
	compareAssert(expectedDisplay2, actualDisplay2);

	cout << "Adding a quarter to an empty machine" << endl;
	expectedDisplay3 = "$0.25";
	machine3.depositCoin(quarter);
	actualDisplay3 = machine3.printDisplay();
	compareAssert(expectedDisplay3, actualDisplay3);

	cout << "Adding a penny is the special case" << endl;
	expectedDisplay4 = "INSERT COIN";
	machine4.depositCoin(penny);
	actualDisplay4 = machine4.printDisplay();
	compareAssert(expectedDisplay4, actualDisplay4);

	cout << "Checking the coin return of Machine4" << endl;
	expectedDisplay4 = "$0.01";
	actualDisplay4 = machine4.checkCoinReturn();
	compareAssert(expectedDisplay4, actualDisplay4);

	cout << "Adding a dime to a machine with money already inserted" << endl;
	expectedDisplay1 = "$0.15";
	machine1.depositCoin(dime);
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Adding a dime to a machine with money already inserted" << endl;
	expectedDisplay1 = "$0.40";
	machine1.depositCoin(quarter);
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Adding two pennies to a machine with money already inserted" << endl;
	machine1.depositCoin(penny);
	machine1.depositCoin(penny);
	actualDisplay1 = machine1.printDisplay();
	compareAssert(expectedDisplay1, actualDisplay1);

	cout << "Checking the coin return of the machine" << endl;
	expectedDisplay1 = "$0.02";
	actualDisplay1 = machine1.checkCoinReturn();
	compareAssert(expectedDisplay1, actualDisplay1);

	return 0;	
}