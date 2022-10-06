#include "clothing.h"
#include "product.h"



Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand):
Product(category, name, price, qty)
{
	size_ = size;
	brand_ = brand;
}

	std::set<std::string> Clothing:: keywords()const{
		std::set<std::string> n = parseStringToWords(name_); 
		std::set<std::string> i = parseStringToWords(size_);
		std::set<std::string> a = parseStringToWords(brand_);
		std::set<std::string> temp;
		temp = setUnion(n,i);
		temp = setUnion(temp, a);
		return temp;
	}

	std::string Clothing:: displayString()const{
		std::string info;
		info = name_ + "\n" + "Size: " + size_ + " " + "Brand: " + brand_
			+ "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";
		return info;
	}
	
	void Clothing::dump(std::ostream& os) const{
		os << category_ << std::endl;
		os << name_ << std::endl;
		os << price_ << std::endl;
		os << qty_ << std::endl;
		os << size_ << std::endl;
		os << brand_ << std::endl;
	}