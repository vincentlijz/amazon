#ifndef BOOK_H
#define BOOK_H

#include "product.h"
#include <iostream>
#include <string>
#include <string.h>
#include <set>


class Book: public Product{
	public:
		Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, const std::string author);
		std::set<std::string> keywords() const;
		std::string displayString() const;
		void dump(std::ostream& os) const;
		
  protected:
		std::string isbn_;
		std::string author_;
};




#endif