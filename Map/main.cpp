#include "map.hpp"
#include <map>
#include <iostream>
#include <string>
#include <vector>

struct mycomp{
	bool operator()(const int &x, const int &y) const{
		return x > y;
	}
};

//struct myComp{
//	bool operator()( int a, int b) const {
//		return a > b;
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

	ft::map<int, int>::iterator it = a.begin();
	std::cout << it->second << std::endl;

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

void testDelete(){
	ft::map<int, int> b;
	for (int i = 0; i < 1000000; i++){
		b.insert(ft::make_pair(i, i+10));
	}
	ft::map<int,int>::iterator firstIt = b.begin();
	ft::map<int,int>::iterator  lastIt  = b.end();
	b.erase(858585);

	for (int i = 0; i < 1000000; i++){
		b.insert(ft::make_pair(i, i+10));
	}

	for (;firstIt != lastIt; firstIt++){
		std::cout << firstIt->first << " - " << firstIt->second << std::endl;
	}



	ft::map<int, int> a;

	a.insert(ft::pair<int, int>(10,3));
	a.insert(ft::pair<int, int>(5,632));
	a.insert(ft::pair<int, int>(20,2));
	a.insert(ft::pair<int, int>(1,2));
	a.insert(ft::pair<int, int>(18,192));
	a.insert(ft::pair<int, int>(12,12900));
	a.insert(ft::pair<int, int>(22,99));
	a.insert(ft::pair<int, int>(3,2));
	a.insert(ft::pair<int, int>(4,2));

	ft::map<int, int>::iterator first = a.begin();
	ft::map<int, int>::iterator  last = a.end();


	last--;
	last--;
	last--;


	a.erase(first, last);
//	a.erase(1);
//	a.erase(10);
//	a.erase(3);

	for (ft::map<int, int>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << it->first << std::endl;

	a.insert(ft::pair<int, int>(22,99));
	a.insert(ft::pair<int, int>(3,2));
	a.insert(ft::pair<int, int>(4,2));

	for (ft::map<int, int>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << it->first << std::endl;
}



void testLookUp(){
	std::cout  << "- - - - - - - - - - - - - - - - - - - count()"  << std::endl;

	ft::map<int, int> a;

	a.insert(ft::pair<int, int>(10,3));
	a.insert(ft::pair<int, int>(5,632));
	a.insert(ft::pair<int, int>(20,2));
	a.insert(ft::pair<int, int>(1,2));
	a.insert(ft::pair<int, int>(18,192));
	a.insert(ft::pair<int, int>(12,12900));
	a.insert(ft::pair<int, int>(22,99));
	a.insert(ft::pair<int, int>(3,2));
	a.insert(ft::pair<int, int>(4,2));

	std::cout << a.count(4545) << std::endl;
	std::cout << a.count(1) << std::endl;

	std::cout  << "- - - - - - - - - - - - - - - - - - - lower upper equal bounds()"  << std::endl;

	std::cout << a.lower_bound(10)->first << std::endl;
	std::cout << a.lower_bound(5)->first << std::endl;
	std::cout << a.lower_bound(20)->first << std::endl;
	std::cout << a.lower_bound(1)->first << std::endl;
	std::cout << a.lower_bound(18)->first << std::endl;
	std::cout << a.lower_bound(12)->first << std::endl;
	std::cout << a.lower_bound(3)->first << std::endl;
	std::cout << a.lower_bound(4)->first << std::endl;

	std::cout << a.upper_bound(10)->first << std::endl;
	std::cout << a.upper_bound(5)->first << std::endl;
	std::cout << a.upper_bound(20)->first << std::endl;
	std::cout << a.upper_bound(1)->first << std::endl;
	std::cout << a.upper_bound(18)->first << std::endl;
	std::cout << a.upper_bound(12)->first << std::endl;
	std::cout << a.upper_bound(3)->first << std::endl;
	std::cout << a.upper_bound(4)->first << std::endl;


	std::cout << a.equal_range(10).first->first << std::endl;
	std::cout << a.equal_range(10).first->second << std::endl;

	std::cout << a.equal_range(5).first->first << std::endl;
	std::cout << a.equal_range(5).first->second << std::endl;

	std::cout << a.equal_range(20).first->first << std::endl;
	std::cout << a.equal_range(20).first->second << std::endl;

	std::cout << a.equal_range(1).first->first << std::endl;
	std::cout << a.equal_range(1).first->second << std::endl;

	std::cout << a.equal_range(18).first->first << std::endl;
	std::cout << a.equal_range(18).first->second << std::endl;

	std::cout << a.equal_range(12).first->first << std::endl;
	std::cout << a.equal_range(12).first->second << std::endl;


	std::cout << a.equal_range(3).first->first << std::endl;
	std::cout << a.equal_range(3).first->second << std::endl;

	std::cout << a.equal_range(4).first->first << std::endl;
	std::cout << a.equal_range(4).first->second << std::endl;

	ft::pair<ft::map<int,int>::const_iterator , ft::map<int,int>::const_iterator> pr =  a.equal_range(4);
	std::cout << pr.first->first << std::endl;

	const ft::pair<ft::map<int,int>::const_iterator , ft::map<int,int>::const_iterator> pr2 =  a.equal_range(4);
	std::cout << pr2.first->first << std::endl;


}

void testComparators(){
	ft::map<int, int, mycomp> a;
	a.insert(ft::pair<int, int>(5, 7));
	a.insert(ft::pair<int, int>(10, 23));
	a.insert(ft::pair<int, int>(56, 741));
	a.insert(ft::pair<int, int>(78, 135));
	a.insert(ft::pair<int, int>(2, 0));
	a.insert(ft::pair<int, int>(708, -454));
	a.insert(ft::pair<int, int>(5656, 6));
	a.insert(ft::pair<int, int>(1, 987));
	a.insert(ft::pair<int, int>(-1001, 987));
	a.insert(ft::pair<int, int>(12, 36));

	for (ft::map<int, int>::iterator it = a.begin(); it != a.end(); it++){
		std::cout << it->first << std::endl;
		std::cout << it->second << std::endl;
	}
}



int main(){
	testElementAccess();
	testCapacity();
	testModifiers();
	testDelete();
	testLookUp();
	testComparators();
}
