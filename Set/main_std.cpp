#include "set.hpp"
#include <set>


void testInsert(){
	std::set<int> a;

	a.insert(3);
	a.insert(1);
	a.insert(6);
	a.insert(10);
	a.insert(20);
	a.insert(3);

	for (std::set<int>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << *it << std::endl;

	//**************************************************************
	std::set<int>::iterator first = a.begin();
	std::set<int>::iterator last = a.end();

	std::set<int> b;
	b.insert(first, last);

	for (std::set<int>::iterator it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;

	//**************************************************************

	first++;

	a.insert(first, 56);
	for (std::set<int>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << *it << std::endl;
}

int main(){
	testInsert();




}
