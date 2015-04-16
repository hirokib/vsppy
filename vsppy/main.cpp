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
#include <boost\date_time\posix_time\posix_time.hpp>
#include "quote.h"
#include "stockticks.h"
#include "iofunctions.h"
#include <boost\filesystem.hpp>


using std::cout;
using std::endl;
namespace fs = boost::filesystem;



int main(int argc, char** argv) {


	fs::path data_dir("C:/");

	fs::path full_path(boost::filesystem::current_path());
	std::cout << "Current path is : " << full_path << std::endl;




	std::ifstream file("data\\GOOG.csv");

	if (file.is_open()) {
		std::cout << "file is open" << std::endl;
	}

	//const std::string ddate = "20140327T000000";

	//boost::posix_time::ptime d(boost::posix_time::from_iso_string(ddate));

	//std::string testdate = boost::posix_time::to_iso_string(d);

	//cout << testdate << endl;



	StockTicks st;
	while (file.good()) {
		read(file, st);
	}
	std::cout << st.stocks.size() << std::endl;

	for (auto ix = st.stocks.begin(); ix != st.stocks.end() && !st.stocks.empty(); ++ix) {
		// (*ix).printDate();
	}


	file.close();

	system("pause");

	return 0;
}

