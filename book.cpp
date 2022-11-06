#include "book.h"
#include "product.h"
#include<iostream>
#include <string>
#include <string.h>

#include <iostream>
#include<sstream>
using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, const std::string author):
Product(category, name, price, qty)
{
	isbn_ = isbn;
	author_ = author;
}

std::set<std::string> Book:: keywords() const{
		std::set<std::string> n = parseStringToWords(name_);
		std::set<std::string> i;
		i.insert(isbn_);
		std::set<std::string> a = parseStringToWords(author_);
		std::set<std::string> temp;
		temp = setUnion(n,i);
		temp = setUnion(temp, a);
		return temp;
	}

std::string Book:: displayString() const{
		std::string info;
		std::ostringstream streamObj;
		streamObj << price_;
		std::string strObj = streamObj.str();
		info = name_ + "\n" + "Author: " + author_ + " " + "ISBN: " + isbn_
			+ "\n" + strObj + " " + std::to_string(qty_) + " left.";
		return info;
	}
	
	void Book::dump(std::ostream& os) const{
		os << category_ << std::endl;
		os << name_ <<  std::endl;
		os << price_ <<  std::endl;
		os << qty_ <<  std::endl;
		os << isbn_ <<  std::endl;
		os << author_ <<  std::endl;
	}