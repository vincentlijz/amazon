#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
	  rawWords = convToLower(rawWords);
	  set<string> words;
		string tmp= "";
    for(auto x: rawWords){
        if((ispunct(x)) && tmp.size()>=2){
					words.insert(tmp);
					tmp = "";
				}
				else if(ispunct(x)) tmp = "";
				else{
					tmp += x;
				}
			
		}
		if(tmp !="" && tmp.size()>=2){
					words.insert(tmp);
				}
		return words;
}
int main(){
	set<int> val{6,3,5,4}; 
	set<int> lav = {};
	set<int> hey = setUnion(val, lav);
	set<int, greater<int> >::iterator itr;
	for (itr = hey.begin(); itr != hey.end(); itr++) {
        cout << *itr << " ";
    }
	return 0;
}
/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
