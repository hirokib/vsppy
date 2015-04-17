/*
* File:   main.cpp
* Author: Hiroki
*
* Created on April 13, 2015, 4:47 PM
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost\date_time\posix_time\posix_time.hpp>
#include <algorithm>
#include <boost\filesystem.hpp>
#include <boost\filesystem\fstream.hpp>

#include "quote.h"
#include "stockticks.h"
#include "iofunctions.h"



using std::cout;
using std::endl;
namespace fs = boost::filesystem;



int main(int argc, char** argv) {


	fs::path data_dir("./data");
	std::cout << data_dir << std::endl;


	std::vector<fs::path> vec;

	try {
		if (fs::is_directory(data_dir)){
			std::cout << "is a directory to data" << std::endl;

			std::copy(fs::directory_iterator(data_dir), fs::directory_iterator(), std::back_inserter(vec));
			sort(vec.begin(), vec.end());



			fs::directory_iterator end;
			for (fs::directory_iterator iter(data_dir); iter != end; ++iter) {
				//vec.push_back(iter->path());
				//cout << iter->path().filename() << endl;

			}

			for (std::vector<fs::path>::iterator iter = (vec.begin()); iter != vec.end(); ++iter) {
				cout << *iter << endl;
			}



		}
		else {
			std::cout << "this is not a directory" << std::endl;
		}
	}
	catch (const fs::filesystem_error& ex) {
		cout << ex.what() << endl;
	}


	cout << 123 << endl;


	fs::ifstream file(vec[0]);

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
	
	
	
	//std::cout << st.stocks.size() << std::endl;

	//for (auto ix = st.stocks.begin(); ix != st.stocks.end() && !st.stocks.empty(); ++ix) {
	//	// (*ix).printDate();
	//}


	file.close();

	system("pause");

	return 0;
}

