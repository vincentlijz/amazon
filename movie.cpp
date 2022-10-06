#include "movie.h"

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating):
Product(category, name, price, qty)
{
	genre_ = genre;
	rating_ = rating;
}

std::set<std::string> Movie::keywords()const{
	  std::set<std::string> n = parseStringToWords(name_); 
		std::set<std::string> i = parseStringToWords(genre_);
		std::set<std::string> a = parseStringToWords(rating_);
		std::set<std::string> temp;
		temp = setUnion(n,i);
		temp = setUnion(temp, a);
		return temp;
}

std::string Movie::displayString() const{
		std::string info;
		info = name_ + "\n" + "Genre: " + genre_ + " " + "Rating: " + rating_
			+ "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";
		return info;
	}
	
	void Movie::dump(std::ostream& os) const{
		os << category_ << std::endl;
		os << name_ << std::endl;
		os << price_ << std::endl;
		os << qty_ << std::endl;
		os << genre_ << std::endl;
		os << rating_ << std::endl;
	}