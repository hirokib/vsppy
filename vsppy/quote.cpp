#include "quote.h"
#include <string>
#include <iostream>



Quote::Quote(ptime date, float open, float high, float low, float close, int volume, float adj_close) {
	this->date = date;
	this->open = open;
	this->high = high;
	this->low = low;
	this->close = close;
	this->volume = volume;
	this->adj_close = adj_close;
}

void Quote::printDate() {
	std::cout << this->date << std::endl;

}

void Quote::printOpen() {
	std::cout << this->open << std::endl;
}



