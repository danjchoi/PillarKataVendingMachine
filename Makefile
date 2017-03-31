HEADERS			= VendingMachine.h
SOURCES			= VendingMachine.cpp

alltests: testAcceptCoin testSelectProduct testMakeChange #testReturnCoins testSoldOut testExactChange
	#./testReturnCoins.out
	#./testSoldOut.out
	#./testExactChange.out

testAcceptCoin: $(SOURCES) $(HEADERS) testAcceptCoin.cpp
	g++ -std=c++11 -pedantic -Wall -Werror testAcceptCoin.cpp $(SOURCES) -o testAcceptCoin.out
	./testAcceptCoin.out

testSelectProduct: $(SOURCES) $(HEADERS) testSelectProduct.cpp
	git checkout remotes/origin/selectProduct
	g++ -std=c++11 -pedantic -Wall -Werror testSelectProduct.cpp $(SOURCES) -o testSelectProduct.out
	./testSelectProduct.out
	git checkout makeChange

testMakeChange: $(SOURCES) $(HEADERS) testMakeChange.cpp
	g++ -std=c++11 -pedantic -Wall -Werror testMakeChange.cpp $(SOURCES) -o testMakeChange.out
	./testMakeChange.out

testReturnCoins: $(SOURCES) $(HEADERS) testReturnCoins.cpp
	g++ -std=c++11 -pedantic -Wall -Werror testReturnCoins.cpp $(SOURCES) -o testReturnCoins.out

testSoldOut: $(SOURCES) $(HEADERS) testSoldOut.cpp
	g++ -std=c++11 -pedantic -Wall -Werror testSoldOut.cpp $(SOURCES) -o testSoldOut.out

testExactChange: $(SOURCES) $(HEADERS) testExactChange.cpp
	g++ -std=c++11 -pedantic -Wall -Werror testExactChange.cpp $(SOURCES) -o testExactChange.out

help: 
	@echo -e "help: \n\tPrints this help message."
	@echo -e "testAcceptCoin: \n\tTests the Accept Coin feature of the vending machine."
	@echo -e "testSelectProduct: \n\tTests the Select Product feature of the vending machine."
	@echo -e "\tMust be tested on its own branch (handled by make commands)."
	@echo -e "\tMakeChange feature overwrites original intended behavior."
	@echo -e "testMakeChange: \n\tTests the Make Change feature of the vending machine."
	@echo -e "testReturnCoins: \n\tTests the Return Coins feature of the vending machine."
	@echo -e "testSoldOut: \n\tTests the Sold Out feature of the vending machine."
	@echo -e "testExactChange: \n\tTests the Exact Change feature of the vending machine"
	@echo -e "alltests: \n\tCompiles and runs all tests."

clean:
	rm testAcceptCoin.out
