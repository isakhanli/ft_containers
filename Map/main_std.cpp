#include "map.hpp"
#include "../Utils/utility.hpp"
#include <map>
#include <iostream>
#include <string>

using namespace std::chrono;

#include <chrono>

#include <vector>

#define _map std::map
#define _make_pair std::make_pair


//struct mycomp{
//	bool operator()(const int &x, const int &y) const{
//		return x > y;
//	}
//};

struct myComp{
	bool operator()( int a, int b) const {
		return a > b;
	}
};

void testElementAccess(){
	std::cout  << "- - - - - - - - - - - - - - - - - - - Element access"  << std::endl;
	std::map<int, int> a;
	a.insert(std::pair<int, int>(10,3));
	a.insert(std::pair<int, int>(5,632));
	a.insert(std::pair<int, int>(20,2));
	a.insert(std::pair<int, int>(200,1267));
	a.insert(std::pair<int, int>(18,212));
	a.insert(std::pair<int, int>(12,8917));
	a.insert(std::pair<int, int>(18,192));
	a.insert(std::pair<int, int>(12,12900));
	a.insert(std::pair<int, int>(22,99));
	a.insert(std::pair<int, int>(24,001));
	a.insert(std::pair<int, int>(-30,12));
	a.insert(std::pair<int, int>(120,765));

	std::cout << a[22] << std::endl;
	for (std::map<int, int>::iterator it = a.begin(); it != a.end(); it++){
		std::cout << it->first << std::endl;
	}

	std::map<int, int>::iterator it = a.begin();
	std::cout << it->second << std::endl;

	std::cout << a[349] << std::endl;
	for (std::map<int, int>::iterator it = a.begin(); it != a.end(); it++){
		std::cout << it->first << std::endl;
	}

	std::map<char, std::string> b;
	b.insert(std::pair<char, std::string>('a', "jhnashsa"));
	b.insert(std::pair<char, std::string>('b', "hnjajknas"));
	b.insert(std::pair<char, std::string>('c', "wquiiqwiwq"));
	b.insert(std::pair<char, std::string>('d', "znbbzxbnxnz"));

	std::cout << b['b'] << std::endl;
	for (std::map<char, std::string>::iterator it = b.begin(); it != b.end(); it++){
		std::cout << it->first << std::endl;
	}

	std::cout << b['e'] << std::endl;
	for (std::map<char, std::string>::iterator it = b.begin(); it != b.end(); it++){
		std::cout << it->first << std::endl;
	}

	b['a'] = "blabla";
	for (std::map<char, std::string>::iterator it = b.begin(); it != b.end(); it++){
		std::cout << it->first << std::endl;
	}
}


void testCapacity(){
	std::cout  << "- - - - - - - - - - - - - - - - - - - empty()"  << std::endl;
	std::map<int, int> a;
	std::cout << a.empty() <<std::endl;
	a.insert(std::pair<int, int>(22,99));
	std::cout << a.empty() <<std::endl;

	std::cout  << "- - - - - - - - - - - - - - - - - - - size()"  << std::endl;

	std::cout << a.size() << std::endl;
	a.insert(std::pair<int, int>(22,99));
	a.insert(std::pair<int, int>(22,99));
	std::cout << a.size() << std::endl;

	std::cout  << "- - - - - - - - - - - - - - - - - - - max_size()"  << std::endl;
	std::cout << a.max_size() << std::endl;
}

void testModifiers(){
	std::cout  << "- - - - - - - - - - - - - - - - - - - clear()"  << std::endl;

	std::map<int, int> a;
	a.insert(std::pair<int, int>(10,3));
	a.insert(std::pair<int, int>(5,632));
	a.insert(std::pair<int, int>(20,2));
	a.insert(std::pair<int, int>(200,1267));
	a.insert(std::pair<int, int>(18,212));
	a.insert(std::pair<int, int>(12,8917));
	a.insert(std::pair<int, int>(18,192));
	a.insert(std::pair<int, int>(12,12900));
	a.insert(std::pair<int, int>(22,99));
	a.insert(std::pair<int, int>(24,001));
	a.insert(std::pair<int, int>(-30,12));
	a.insert(std::pair<int, int>(120,765));

	for (std::map<int, int>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << it->first << std::endl;

	a.clear();

	for (std::map<int, int>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << it->first << std::endl;

	std::cout << a.size() << std::endl;

}

void testDelete(){
	std::map<int, int> a;

	a.insert(std::pair<int, int>(10,3));
	a.insert(std::pair<int, int>(5,632));
	a.insert(std::pair<int, int>(20,2));
	a.insert(std::pair<int, int>(1,2));
	a.insert(std::pair<int, int>(18,192));
	a.insert(std::pair<int, int>(12,12900));
	a.insert(std::pair<int, int>(22,99));
	a.insert(std::pair<int, int>(3,2));
	a.insert(std::pair<int, int>(4,2));

	std::map<int, int>::iterator first = a.begin();
	std::map<int, int>::iterator  last = a.end();


	last--;
	last--;
	last--;


	a.erase(first, last);
//	a.erase(1);
//	a.erase(10);
//	a.erase(3);

	for (std::map<int, int>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << it->first << std::endl;

	a.insert(std::pair<int, int>(22,99));
	a.insert(std::pair<int, int>(3,2));
	a.insert(std::pair<int, int>(4,2));

	for (std::map<int, int>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << it->first << std::endl;
}



void testLookUp(){
	std::cout  << "- - - - - - - - - - - - - - - - - - - count()"  << std::endl;

	std::map<int, int> a;

	a.insert(std::pair<int, int>(10,3));
	a.insert(std::pair<int, int>(5,632));
	a.insert(std::pair<int, int>(20,2));
	a.insert(std::pair<int, int>(1,2));
	a.insert(std::pair<int, int>(18,192));
	a.insert(std::pair<int, int>(12,12900));
	a.insert(std::pair<int, int>(22,99));
	a.insert(std::pair<int, int>(3,2));
	a.insert(std::pair<int, int>(4,2));

	std::cout << a.count(4545) << std::endl;
	std::cout << a.count(1) << std::endl;

	std::cout  << "- - - - - - - - - - - - - - - - - - - lower upper equal bounds()"  << std::endl;

	std::cout << a.lower_bound(10)->first << std::endl;
	std::cout << a.lower_bound(5)->first << std::endl;
	std::cout << a.lower_bound(20)->first << std::endl;
	std::cout << a.lower_bound(1)->first << std::endl;
	std::cout << a.lower_bound(18)->first << std::endl;
	std::cout << a.lower_bound(12)->first << std::endl;
	std::cout << a.lower_bound(22)->first << std::endl;
	std::cout << a.lower_bound(3)->first << std::endl;
	std::cout << a.lower_bound(4)->first << std::endl;

	std::cout << a.upper_bound(10)->first << std::endl;
	std::cout << a.upper_bound(5)->first << std::endl;
	std::cout << a.upper_bound(20)->first << std::endl;
	std::cout << a.upper_bound(1)->first << std::endl;
	std::cout << a.upper_bound(18)->first << std::endl;
	std::cout << a.upper_bound(12)->first << std::endl;
//	std::cout << a.upper_bound(22)->first << std::endl;
	std::cout << a.upper_bound(3)->first << std::endl;
	std::cout << a.upper_bound(4)->first << std::endl;


//	std::cout << a.equal_range(10).first->first << std::endl;
//	std::cout << a.equal_range(10).first->second << std::endl;
//
//	std::cout << a.equal_range(5).first->first << std::endl;
//	std::cout << a.equal_range(5).first->second << std::endl;
//
//	std::cout << a.equal_range(20).first->first << std::endl;
//	std::cout << a.equal_range(20).first->second << std::endl;
//
//	std::cout << a.equal_range(1).first->first << std::endl;
//	std::cout << a.equal_range(1).first->second << std::endl;
//
//	std::cout << a.equal_range(18).first->first << std::endl;
//	std::cout << a.equal_range(18).first->second << std::endl;
//
//	std::cout << a.equal_range(12).first->first << std::endl;
//	std::cout << a.equal_range(12).first->second << std::endl;
//
//	std::cout << a.equal_range(22).first->first << std::endl;
//	std::cout << a.equal_range(22).first->second << std::endl;
//
//	std::cout << a.equal_range(3).first->first << std::endl;
//	std::cout << a.equal_range(3).first->second << std::endl;
//
//	std::cout << a.equal_range(4).first->first << std::endl;
//	std::cout << a.equal_range(4).first->second << std::endl;

	std::pair<std::map<int,int>::const_iterator , std::map<int,int>::const_iterator> pr =  a.equal_range(4);
	std::cout << pr.first->first << std::endl;

	const std::pair<std::map<int,int>::const_iterator , std::map<int,int>::const_iterator> pr2 =  a.equal_range(4);
	std::cout << pr.first->first << std::endl;


//	const std::map<int, int> b;

//	const int pr =  b.equal_range(4);
//	std::cout << pr << std::endl;


//	std::pair<std::map<int,int>::iterator , std::map<int,int>::iterator> pr =  a.equal_range(4);
//	std::cout << pr.first->first << std::endl;
}

//template <class T, class V>
//std::vector<int> copy_constructor_test(_map<T, V> mp) {
//
//	std::vector<int> v;
//
//	for (int i = 0, j = 10; i < 300000; ++i, ++j) {
//		mp.insert(_make_pair(i, j));
//	}
//	_map<int, int> mp2(mp.begin(), mp.end());
//	_map<int, int>::iterator it = mp2.begin();
//	for (int i = 0; i < 300000; ++i, it++) {
//		v.push_back(it->first);
//		v.push_back(it->second);
//	}
//	return v;
//}

template <class T, class V>
std::vector<int> erase_test_1(std::map<T, V> mp) {
	std::vector<int> v;
	v.push_back(mp.erase(3));
	for (int i = 0, j = 0; i < 300000 ; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	typename std::map<T, V>::iterator it = mp.begin();
	v.push_back(it->first);
	v.push_back(mp.erase(-5));
	v.push_back(mp.size());
	v.push_back(mp.erase(0));
	v.push_back(10);
	v.push_back(mp.size());
	it = mp.begin();
	v.push_back(it->first);
	typename std::map<T, V>::iterator it4 = mp.begin();

	for (; it4 != mp.end(); it4 = mp.begin())
		mp.erase(it4->first);

	typename std::map<T, V>::iterator it2 = mp.end();
	it2--;
	v.push_back(mp.erase(299999));
	v.push_back(mp.size());
	std::map<int, int> mp2;
	for (int i = 0, j = 0; i < 10 ; ++i, ++j)
		mp2.insert(std::make_pair(i, j));
	mp2.erase(2);
	mp2.erase(7);
	typename std::map<T, V>::iterator it3 = mp2.begin();
	for (; it3 != mp2.end(); ++it3) {
		v.push_back(it3->first);
		v.push_back(it3->second);
	}
	return v;
}



template <class T, class V>
std::vector<int> erase_test_2(std::map<T, V> mp) {
	std::vector<int> v;
	for (int i = 0, j = 0; i < 300000 ; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	typename std::map<T, V>::iterator it = mp.begin();
	v.push_back(it->first);
	mp.erase(it);
	v.push_back(mp.size());
	it = mp.begin();
	mp.erase(++it);
	v.push_back(mp.size());
	it = mp.begin();
	v.push_back(it->first);
	typename std::map<T, V>::iterator it4 = mp.begin();
//	g_start2 = timer();
	for (; it4 != mp.end(); it4 = mp.begin())
		mp.erase(it4);
//	g_end2 = timer();
	v.push_back(mp.size());
	std::map<int, int> mp2;
	for (int i = 0, j = 0; i < 10 ; ++i, ++j)
		mp2.insert(std::make_pair(i, j));
	typename std::map<T, V>::iterator ittest = mp2.begin();
	for (int i = 0; i < 2; ++i) ittest++;
	mp2.erase(ittest);
	for (int i = 0; i < 5; ++i) ittest++;
	mp2.erase(ittest);
	typename std::map<T, V>::iterator it3 = mp2.begin();
	for (; it3 != mp2.end(); ++it3) {
		v.push_back(it3->first);
		v.push_back(it3->second);
	}
	return v;
}

void test2() {
	std::map<int, int> b;
	std::vector<int> a = erase_test_2(b);
	for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++){
		std::cout << *it << std::endl;
	}

}


template <class T, class V>
std::vector<int> testErase(std::map<T, V> mp) {
	std::vector<int> v;
	for (int i = 0, j = 0; i < 300000 ; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	typename std::map<T, V>::iterator it = mp.begin();
	v.push_back(it->first);
	mp.erase(it);
	v.push_back(mp.size());
	it = mp.begin();
	mp.erase(++it);
	v.push_back(mp.size());
	it = mp.begin();
	v.push_back(it->first);
	typename std::map<T, V>::iterator it4 = mp.begin();
//	g_start1 = timer();
	for (; it4 != mp.end(); it4 = mp.begin())
		mp.erase(it4);
//	g_end1 = timer();
	v.push_back(mp.size());
	std::map<int, int> mp2;
	for (int i = 0, j = 0; i < 10 ; ++i, ++j)
		mp2.insert(std::make_pair(i, j));
	typename std::map<T, V>::iterator ittest = mp2.begin();
	for (int i = 0; i < 2; ++i) ittest++;
	mp2.erase(ittest);
	for (int i = 0; i < 5; ++i) ittest++;
	mp2.erase(ittest);
	typename std::map<T, V>::iterator it3 = mp2.begin();
	for (; it3 != mp2.end(); ++it3) {
		v.push_back(it3->first);
		v.push_back(it3->second);
	}
	return v;
}

template <class T, class V>
std::vector<int> testErase2(std::map<T, V> mp) {
	std::vector<int> v;
	for (int i = 0, j = 0; i < 300000 ; ++i, ++j)
		mp.insert(std::make_pair(i, j));
	typename std::map<T, V>::iterator it = mp.begin();
	v.push_back(it->first);
	mp.erase(it);
	v.push_back(mp.size());
	it = mp.begin();
	mp.erase(++it);
	v.push_back(mp.size());
	it = mp.begin();
	v.push_back(it->first);
	typename std::map<T, V>::iterator it4 = mp.begin();
//	g_start1 = timer();
	for (; it4 != mp.end(); it4 = mp.begin())
		mp.erase(it4);
//	g_end1 = timer();
	v.push_back(mp.size());
	std::map<int, int> mp2;
	for (int i = 0, j = 0; i < 10 ; ++i, ++j)
		mp2.insert(std::make_pair(i, j));
	typename std::map<T, V>::iterator ittest = mp2.begin();
	for (int i = 0; i < 2; ++i) ittest++;
	mp2.erase(ittest);
	for (int i = 0; i < 5; ++i) ittest++;
	mp2.erase(ittest);
	typename std::map<T, V>::iterator it3 = mp2.begin();
	for (; it3 != mp2.end(); ++it3) {
		v.push_back(it3->first);
		v.push_back(it3->second);
	}
	return v;
}


void 	testComparator(){
	std::map<int, int, myComp> a;
	a.insert(std::pair<int, int>(10,3));
	a.insert(std::pair<int, int>(5,632));
	a.insert(std::pair<int, int>(20,2));
	a.insert(std::pair<int, int>(1,2));
	a.insert(std::pair<int, int>(18,192));
	a.insert(std::pair<int, int>(12,12900));
	a.insert(std::pair<int, int>(22,99));
	a.insert(std::pair<int, int>(3,2));
	a.insert(std::pair<int, int>(4,2));

	for (std::map<int, int, myComp>::iterator it = a.begin(); it != a.end(); it++)
		std::cout << it->first << std::endl;
}

template <class T, class V>
std::vector<int> lower_bound_test(std::map<T, V> mp) {
	auto f = []() -> int { return rand() % 10000; };

	std::vector<int> v;
	std::map<int, int, std::greater<int> > mp2;
	mp.insert(std::make_pair(10, 10));
	mp2.insert(std::make_pair(10, 10));
	if (mp.lower_bound(11) == mp.end())
		v.push_back(1);
	if (mp2.lower_bound(1) == mp2.end())
		v.push_back(1);
	mp.insert(std::make_pair(20, 20));
	mp.insert(std::make_pair(30, 30));
	mp.insert(std::make_pair(40, 40));
	mp.insert(std::make_pair(50, 50));
	mp.insert(std::make_pair(60, 60));
	mp2.insert(std::make_pair(20, 20));
	mp2.insert(std::make_pair(30, 30));
	mp2.insert(std::make_pair(40, 40));
	mp2.insert(std::make_pair(50, 50));
	mp2.insert(std::make_pair(60, 60));
	std::map<int, int>::iterator it;
	for (int i = 1; i < 60; i += 10) {
		it = mp.lower_bound(i);
		v.push_back(it->first);
	}
	for (int i = 11; i < 70; i += 10) {
		it = mp2.lower_bound(i);
		v.push_back(it->first);
	}
	std::map<int, int> mp3;
	for (int i = 0, j = 0; i < 500000; ++i, ++j) {
		mp3.insert(std::make_pair(i, j));
	}
//	g_start1 = timer();
	auto start = high_resolution_clock::now();
	mp3.lower_bound(490000);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	std::cout << "Time taken by function: "
			  << duration.count() << " microseconds" << std::endl;
//	g_end1 = timer();
	return v;
}

template <class T, class V>
std::vector<int> lower_bound_test2(std::map<T, V> mp) {

	auto f = []() -> int { return rand() % 10000; };


	std::vector<int> v;
	std::map<int, int, std::greater<int> > mp2;
	mp.insert(std::make_pair(10, 10));
	mp2.insert(std::make_pair(10, 10));
	if (mp.lower_bound(11) == mp.end())
		v.push_back(1);
	if (mp2.lower_bound(1) == mp2.end())
		v.push_back(1);
	mp.insert(std::make_pair(20, 20));
	mp.insert(std::make_pair(30, 30));
	mp.insert(std::make_pair(40, 40));
	mp.insert(std::make_pair(50, 50));
	mp.insert(std::make_pair(60, 60));
	mp2.insert(std::make_pair(20, 20));
	mp2.insert(std::make_pair(30, 30));
	mp2.insert(std::make_pair(40, 40));
	mp2.insert(std::make_pair(50, 50));
	mp2.insert(std::make_pair(60, 60));
	std::map<int, int>::iterator it;
	for (int i = 1; i < 60; i += 10) {
		it = mp.lower_bound(i);
		v.push_back(it->first);
	}
	for (int i = 11; i < 70; i += 10) {
		it = mp2.lower_bound(i);
		v.push_back(it->first);
	}
	std::map<int, int> mp3;
	for (int i = 0, j = 0; i < 500000; ++i, ++j) {
		mp3.insert(std::make_pair(i, j));
	}
//	g_start1 = timer();
	auto start = high_resolution_clock::now();
	mp3.lower_bound(490000);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	std::cout << "Time taken by function: "
		 << duration.count() << " microseconds" << std::endl;
//	g_end1 = timer();
	return v;
}


void testbounds(){
	std::map<int, int> sMap;
	std::vector<int> a = lower_bound_test<int,int>(sMap);

	std::map<int, int> fMap;
	std::vector<int> b = lower_bound_test2<int,int>(fMap);
}

void testbounds2(){
	std::map<int, int> a;

	for (int i = 0; i < 50000; i++){
		a.insert(std::pair<int, int>(i, i));
	}



	std::cout << a.lower_bound(49000)->first << std::endl;

}



int main(){
//	testElementAccess();
//	testCapacity();
//	testModifiers();
//	testDelete();
//	testLookUp();
//	testIterators();
//	test2();
//	std::map<int, int> ft_map;
//	std::map<int, int> std_map;
////	testErase<int, int>(std_map);
//	testErase2<int, int>(ft_map);

//	testComparator();
//	testbounds();
	testbounds2();
}
