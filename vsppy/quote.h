/*
* File:   quote.h
* Author: hirok_000
*
* Created on April 14, 2015, 8:30 PM
*/



#ifndef QUOTE_H
#define	QUOTE_H

#include <string>
#include <iostream>
#include <boost\date_time\posix_time\posix_time.hpp>

using boost::posix_time::ptime;


class Quote {


public:

	Quote(ptime date, float open, float high, float low, float close, int volume, float adj_close);
	void printDate();
	void printOpen();

private:

	ptime date;
	float open;
	float high;
	float low;
	float close;
	int volume;
	float adj_close;



};

#endif	/* QUOTE_H */

