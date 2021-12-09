#include "set.hpp"
#include <set>
#include <vector>

template <class T>
std::vector<int> erase_test_3(std::set<T> st) {
	std::vector<int> v;
	for (int i = 0; i < 500000; ++i)
		st.insert(i);
//	g_start1 = timer();
	st.erase(st.begin(), --st.end());
//	g_end1 = timer();
	v.push_back(*(st.begin()));
	return v;
}

template <class T>
std::vector<int> erase_test_4(ft::set<T> st) {
	std::vector<int> v;
	for (int i = 0; i < 500000; ++i)
		st.insert(i);
//	g_start1 = timer();
	st.erase(st.begin(), --st.end());
//	g_end1 = timer();
	v.push_back(*(st.begin()));
	return v;
}


void testConstructors(){
	ft::set<int> ftSet;
	std::vector<int> a = erase_test_4(ftSet);
}

void testInsert(){
	ft::set<int> a;

	a.insert(3);
	a.insert(1);
	a.insert(6);
	a.insert(10);
	a.insert(20);
	a.insert(3);

	for (ft::set<int>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << *it << std::endl;

	//**************************************************************
	ft::set<int>::iterator first = a.begin();
	ft::set<int>::iterator last = a.end();

	ft::set<int> b;
	b.insert(first, last);

	for (ft::set<int>::iterator it = b.begin(); it != b.end(); it++)
		std::cout << *it << std::endl;

	//**************************************************************

	first++;

	a.insert(first, 56);
	for (ft::set<int>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << *it << std::endl;
}

int main(){
//	testInsert();
	testConstructors();




}
