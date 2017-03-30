HEADERS			= VendingMachine.h
SOURCES			= VendingMachine.cpp
TESTSOURCES		= testAcceptCoin.cpp

help: 
	@echo -e "help: \n\tPrints this help message."
	@echo -e "testAcceptCoin: \n\tTests the acceptCoin feature of the vending machine. \n\tOutput is printed on the terminal."
	@echo -e "alltests: \n\tCompiles and runs all tests."


testAcceptCoin: $(HEADERS) $(SOURCES) $(TESTSOURCES)
	g++ -std=c++11 -pedantic -Wall -Werror testAcceptCoin.cpp -o testAcceptCoin.out

alltests: testAcceptCoin
	./testAcceptCoin.out
clean:
	rm testAcceptCoin.out
