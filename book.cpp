#include "book.h"
#include "product.h"
#include<iostream>
using namespace std; 

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, const std::string author):
Product(category, name, price, qty)
{
	isbn_ = isbn;
	author_ = author;
}

std::set<std::string> Book:: keywords(){
		std::set<std::string> temp; 
		temp.insert(name_);
		temp.insert(isbn_);
		temp.insert(author_);
		return temp;
	}

std::string Book:: displayString(){
		std::string info;
		info = name_ + "/n" + "Author: " + author_ + " " + "ISBN: " + isbn_
			+ "/n" + to_string(price_) + " " + to_string(qty_) + " left.";
		return info;
	}
	
	void Book::dump(std::ostream& os) const{
		cout << category_ << endl;
		cout << name_ << endl;
		cout << price_ << endl;
		cout << qty_ << endl;
		cout << isbn_ << endl;
		cout << author_ << endl;
	}