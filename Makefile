install: clean uninstall
	bash bash/install.sh
	mv CPP_Calc/CPP_Calc.app Calculator.app

uninstall: clean
	rm -rf Calculator.app

clean_test:
	rm -rf test/*.o
	rm -rf test/test
	rm -rf test/googletest-release-1.11.0

clean: clean_test
	bash bash/clean.sh

tests: 
	gcc -lstdc++ -g -std=c++17 -Wall -Werror -Wextra -lgtest test/test.cc CPP_Calc/model.cc -o test/test
	./test/test

dist: install
	rm -rf Calculator.tar.gz
	tar -zcf Calculator.tar.gz Calculator.app

div:
	cat info/div.txt