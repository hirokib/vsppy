/*
* File:   main.cpp
* Author: Hiroki
*
* Created on April 13, 2015, 4:47 PM
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "quote.h"

using std::cout;
using std::endl;

/*
*
*/



class StockInfo {
public:
	std::vector<Quote> stocks;


private:
};




std::istream &read(std::istream &is, StockInfo &stk) {


	std::string date;
	float open;
	float high;
	float low;
	float close;
	int volume;
	float adj_close;
	is >> date >> open >> high >> low >> close >> volume >> adj_close;
	Quote new_quote(date, open, high, low, close, volume, adj_close);
	//test.printDate();
	stk.stocks.push_back(new_quote);
	return is;
}






int main(int argc, char** argv) {

	std::ifstream file("data\\GOOG.csv");

	if (file.is_open()) {
		std::cout << "file is open" << std::endl;
	}

	StockInfo st;
	while (file.good()) {
		read(file, st);
	}
	std::cout << st.stocks.size() << std::endl;


	Quote t2("2014-03-27", 568.0, 568.0, 552.92, 558.46, 13100, 558.46);
	t2.printOpen();

	for (auto ix = st.stocks.begin(); ix != st.stocks.end() && !st.stocks.empty(); ++ix) {
		// (*ix).printDate();
	}

	system("pause");

	return 0;
}

