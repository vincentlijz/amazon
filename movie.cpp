#include "movie.h"
#include <sstream>

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating):
Product(category, name, price, qty)
{
	genre_ = genre;
	rating_ = rating;
}

std::set<std::string> Movie::keywords()const{
	  std::set<std::string> n = parseStringToWords(name_); 
		std::set<std::string> i;
		std::string g = convToLower(genre_);
		i.insert(g);
		std::set<std::string> a;
		std::string r =convToLower(rating_);
		a.insert(r);
		std::set<std::string> temp;
		temp = setUnion(n,i);
		temp = setUnion(temp, a);
		return temp;
}

std::string Movie::displayString() const{
		std::string info;
		std::ostringstream streamObj;
		streamObj << price_;
		std::string strObj = streamObj.str();
		info = name_ + "\n" + "Genre: " + genre_ + " " + "Rating: " + rating_
			+ "\n" + strObj + " " + std::to_string(qty_) + " left.";
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