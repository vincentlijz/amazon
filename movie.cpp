#include "movie.h"
#include "product.h"
#include <iostream>
using namespace std; 

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating):
Product(category, name, price, qty)
{
	genre_ = genre;
	rating_ = rating;
}

std::set<std::string> Movie::keywords(){
		std::set<std::string> temp; 
		temp.insert(name_);
		temp.insert(genre_);
		temp.insert(rating_);
		return temp;
	}

std::string Movie::displayString(){
		std::string info;
		info = name_ + "/n" + "Genre: " + genre_ + " " + "Rating: " + rating_
			+ "/n" + to_string(price_) + " " + to_string(qty_) + " left.";
		return info;
	}
	
	void Movie::dump(std::ostream& os) const{
		cout << category_ << endl;
		cout << name_ << endl;
		cout << price_ << endl;
		cout << qty_ << endl;
		cout << genre_ << endl;
		cout << rating_ << endl;
	}