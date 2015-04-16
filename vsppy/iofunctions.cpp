#include "iofunctions.h"

std::istream &read(std::istream &is, StockTicks &stk) {

	

	std::string date;
	float open;
	float high;
	float low;
	float close;
	int volume;
	float adj_close;
	is >> date >> open >> high >> low >> close >> volume >> adj_close;
	//std::cout << date << std::endl;


	// Pandas has a problem of returning an extra carriage return
	// This is a really shitty hack to get around not having to process
	// the extra line so as not to throw an exception.

	if (date == ""){
		return is;
	}

	boost::posix_time::ptime d(boost::posix_time::from_iso_string(date));
	Quote new_quote(d, open, high, low, close, volume, adj_close);
	//test.printDate();
	stk.stocks.push_back(new_quote);
	return is;
}
