HEADERS			= VendingMachine.h
SOURCES			= VendingMachine.cpp
TESTSOURCES		= testAcceptCoin.cpp

alltests: testAcceptCoin
	./testAcceptCoin.out

testAcceptCoin: $(SOURCES) $(HEADERS) $(TESTSOURCES)
	g++ -std=c++11 -pedantic -Wall -Werror testAcceptCoin.cpp $(SOURCES) -o testAcceptCoin.out

help: 
	@echo -e "help: \n\tPrints this help message."
	@echo -e "testAcceptCoin: \n\tTests the acceptCoin feature of the vending machine. \n\tOutput is printed on the terminal."
	@echo -e "alltests: \n\tCompiles and runs all tests."

clean:
	rm testAcceptCoin.out
