#include "clothing.h"
#include "product.h"
#include<iostream>
using namespace std; 

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand):
Product(category, name, price, qty)
{
	size_ = size;
	brand_ = brand;
}

std::set<std::string> Clothing:: keywords(){
		std::set<std::string> temp; 
		temp.insert(name_);
		temp.insert(size_);
		temp.insert(brand_);
		return temp;
	}

std::string Clothing:: displayString(){
		std::string info;
		info = name_ + "/n" + "Size: " + size_ + " " + "Brand: " + brand_
			+ "/n" + to_string(price_) + " " + to_string(qty_) + " left.";
		return info;
	}
	
	void Clothing::dump(std::ostream& os) const{
		cout << category_ << endl;
		cout << name_ << endl;
		cout << price_ << endl;
		cout << qty_ << endl;
		cout << size_ << endl;
		cout << brand_ << endl;
	}