#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "movie.h"
#include "book.h"
#include "clothing.h"
#include "util.h"
#include "user.h"
#include <deque>
#include "datastore.h"
#include<map>

class MyDataStore : public DataStore{
		public:
		MyDataStore();
		~MyDataStore();
		void addProduct(Product* p);
		void addUser(User* u);
		std::vector<Product*> search(std::vector<std::string>& terms, int type);
		void dump(std::ostream& ofile);
		void addtoCart(std::string username, int hit);
		void viewCart(std::string username);
		void buyCart(std::string username);
		void printKey();

		private:
		std::map<std::string, std::set<Product*>> products;
		std::vector<Product*> prev_search_result;
		std::map<std::string, User*> users;
		std::map<std::string, std::deque<Product*>> usercart; 

};


#endif