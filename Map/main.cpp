#include "map.hpp"
#include "../Utils/utility.hpp"
#include <map>
#include <iostream>
#include <string>


//struct mycomp{
//	bool operator()(const int &x, const int &y) const{
//		return x > y;
//	}
//};

void testElementAccess(){
	std::cout  << "- - - - - - - - - - - - - - - - - - - Element access"  << std::endl;
	ft::map<int, int> a;
	a.insert(ft::pair<int, int>(10,3));
	a.insert(ft::pair<int, int>(5,632));
	a.insert(ft::pair<int, int>(20,2));
	a.insert(ft::pair<int, int>(200,1267));
	a.insert(ft::pair<int, int>(18,212));
	a.insert(ft::pair<int, int>(12,8917));
	a.insert(ft::pair<int, int>(18,192));
	a.insert(ft::pair<int, int>(12,12900));
	a.insert(ft::pair<int, int>(22,99));
	a.insert(ft::pair<int, int>(24,001));
	a.insert(ft::pair<int, int>(-30,12));
	a.insert(ft::pair<int, int>(120,765));

	std::cout << a[22] << std::endl;
	for (ft::map<int, int>::iterator it = a.begin(); it != a.end(); it++){
		std::cout << it->first << std::endl;
	}

	std::cout << a[349] << std::endl;
	for (ft::map<int, int>::iterator it = a.begin(); it != a.end(); it++){
		std::cout << it->first << std::endl;
	}

	ft::map<char, std::string> b;
	b.insert(ft::pair<char, std::string>('a', "jhnashsa"));
	b.insert(ft::pair<char, std::string>('b', "hnjajknas"));
	b.insert(ft::pair<char, std::string>('c', "wquiiqwiwq"));
	b.insert(ft::pair<char, std::string>('d', "znbbzxbnxnz"));

	std::cout << b['b'] << std::endl;
	for (ft::map<char, std::string>::iterator it = b.begin(); it != b.end(); it++){
		std::cout << it->first << std::endl;
	}

	std::cout << b['e'] << std::endl;
	for (ft::map<char, std::string>::iterator it = b.begin(); it != b.end(); it++){
		std::cout << it->first << std::endl;
	}

	b['a'] = "blabla";
	for (ft::map<char, std::string>::iterator it = b.begin(); it != b.end(); it++){
		std::cout << it->first << std::endl;
	}
}


void testCapacity(){
	std::cout  << "- - - - - - - - - - - - - - - - - - - empty()"  << std::endl;
	ft::map<int, int> a;
	std::cout << a.empty() <<std::endl;
	a.insert(ft::pair<int, int>(22,99));
	std::cout << a.empty() <<std::endl;

	std::cout  << "- - - - - - - - - - - - - - - - - - - size()"  << std::endl;

	std::cout << a.size() << std::endl;
	a.insert(ft::pair<int, int>(22,99));
	a.insert(ft::pair<int, int>(22,99));
	std::cout << a.size() << std::endl;

	std::cout  << "- - - - - - - - - - - - - - - - - - - max_size()"  << std::endl;
	std::cout << a.max_size() << std::endl;
}

void testModifiers(){
	std::cout  << "- - - - - - - - - - - - - - - - - - - clear()"  << std::endl;

	ft::map<int, int> a;
	a.insert(ft::pair<int, int>(10,3));
	a.insert(ft::pair<int, int>(5,632));
	a.insert(ft::pair<int, int>(20,2));
	a.insert(ft::pair<int, int>(200,1267));
	a.insert(ft::pair<int, int>(18,212));
	a.insert(ft::pair<int, int>(12,8917));
	a.insert(ft::pair<int, int>(18,192));
	a.insert(ft::pair<int, int>(12,12900));
	a.insert(ft::pair<int, int>(22,99));
	a.insert(ft::pair<int, int>(24,001));
	a.insert(ft::pair<int, int>(-30,12));
	a.insert(ft::pair<int, int>(120,765));

	for (ft::map<int, int>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << it->first << std::endl;

	a.clear();

	for (ft::map<int, int>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << it->first << std::endl;

	std::cout << a.size() << std::endl;

}


int main(){
//	testElementAccess();
//	testCapacity();
	testModifiers();
}