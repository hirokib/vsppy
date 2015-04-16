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

	boost::posix_time::ptime d(boost::posix_time::time_from_string(date));
	Quote new_quote(d, open, high, low, close, volume, adj_close);
	//test.printDate();
	stk.stocks.push_back(new_quote);
	return is;
}
