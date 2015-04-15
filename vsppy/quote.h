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

class Quote {
public:

	Quote(std::string date, float open, float high, float low, float close, int volume, float adj_close);
	void printDate();
	void printOpen();

private:

	std::string date;
	float open;
	float high;
	float low;
	float close;
	int volume;
	float adj_close;



};

#endif	/* QUOTE_H */

