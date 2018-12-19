/*
Lab 5 - Polymorphism Lab (Library Holdings)
Author:  Chris Hopp - 010809627
Version: 05.18.2018

*/

#include "book.h"

#include <fstream>

extern ofstream csis;

Book::Book(const Book& book1) : Holding(book1) {}								//Book derived copy constructor

Book::Book(char* bookTitle, char* bookAuthor, int bookNumber) : Holding(bookTitle, bookAuthor, bookNumber){}	//3 arg derived constructor

Book& Book::operator = (const Book& book1){										//Assignment operator for Book objects (Rule of Three)
	Holding::operator=(book1);
	return *this;
}


void Book::print() {																			//Book specific print function
		cout << "BOOK: " << artist << " " << "\"" << title << "\" " << callNumber << endl;
		csis << "BOOK: " << artist << " " << "\"" << title << "\" " << callNumber << endl;

}

Book::~Book() {}	//Book destructor