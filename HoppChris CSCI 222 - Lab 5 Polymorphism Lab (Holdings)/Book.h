/*
Lab 5 - Polymorphism Lab (Library Holdings)
Author:  Chris Hopp - 010809627
Version: 05.18.2018

*/

#ifndef _BOOK_H
#define _BOOK_H

#include "Holding.h"

class Book : public Holding {
public:
	Book(const Book&);
	Book(char*, char*, int);
	Book& operator = (const Book& book1);

	virtual ~Book();
	virtual void print();
};

#endif