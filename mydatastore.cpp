#include "mydatastore.h"
#include "util.h"
#include <iostream>
#include "user.h"


MyDataStore::MyDataStore(){
}

MyDataStore::~MyDataStore(){
	
}


void MyDataStore::addProduct(Product* p){
	std::set<std::string> terms = p->keywords();
	for(std::set<std::string>::iterator it=terms.begin(); it != terms.end(); it++){
			products[*it].insert(p);
	}
}

void MyDataStore::addUser(User* u){
	users[u->getName()] = u;
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
	//return a vector of products that match the keyterms 
	if(type == 0){
		std::cout << terms[0] << std::endl;
		std::set<Product*> cur = products[terms[0]];
		std::set<Product*> temp;
		for(unsigned int i=1; i <terms.size(); i+=2) {
    	temp = products[terms[i]];
			cur = setIntersection(cur, temp);
 		}
		 prev_search_result = std::vector<Product*>(cur.begin(),cur.end());
		 return prev_search_result;
	}
	else if(type == 1){
		std::set<Product*> cur;
		std::set<Product*> temp;
		for(unsigned int i=0; i <terms.size(); i+=2) {
    	temp = products[terms[i]];
			cur = setUnion(cur, temp);
 		}
		 prev_search_result = std::vector<Product*>(cur.begin(),cur.end());
		 return prev_search_result;
	}
}

void MyDataStore::dump(std::ostream& ofile){
	ofile << "<products>" << std::endl;
	std::map<std::string, std::set<Product*>>::iterator it;
	for(it = products.begin(); it!=products.end(); it++){
		std::set<Product*> temp= it->second;
		std::set<Product*>:: iterator itr;
		for(itr = temp.begin(); itr!=temp.end(); itr++){
			(*itr)->dump(ofile);
		}
	}
	ofile << "</products>" << std::endl;
	ofile << "users" <<std::endl;
	std::map<std::string, User*>:: iterator i;
	for (i=users.begin(); i!=users.end(); i++){
		i->second->dump(ofile);
	}
	ofile<< "/users" << std::endl;
}

// void MyDataStore::addtoCart(std::string username, std::vector<Product*> s_result, int hit_index)
void MyDataStore::addtoCart(std::string username, int hit){
	int hit_index = hit - 1;
	if(users.find(username) == users.end() || hit_index > prev_search_result.size() || hit_index < 0){
		std::cout << "invalid username" << std::endl;
		return;
	}
	Product* choice = prev_search_result[hit_index];
	usercart[username].push_back(choice);
}

void MyDataStore::viewCart(std::string username){
	if(users.find(username)== users.end()){
		std::cout << "invalid user" << std::endl;
		return;
	}
	std::deque<Product*> q_copy = usercart[username];
	for (unsigned int i=0; i < q_copy.size(); i++) {
    std::cout << i+1 <<". " << q_copy[i]->displayString() << std::endl;
  }
}

void MyDataStore::buyCart(std::string username){
	if(users.find(username)== users.end())
		std::cout << "Invalid username" << std::endl; 
	std::deque<Product*> q_copy = usercart[username];
	for(unsigned int i=0; i<q_copy.size();i++) {
		int q = usercart[username][0]->getQty();
		int b = users[username]->getBalance();
		int p = usercart[username][0]->getPrice();
		if( q>0 && b>=p ){
			usercart[username][0]->subtractQty(1);
			users[username]->deductAmount(p);
			usercart[username].pop_front();
		}
	}
}
