#include "stack.hpp"
#include <stack>
#include <string>

void testOtherMethods(){
	ft::stack<std::string> strs;
	strs.push("askjna");
	strs.push("ewiuhew");
	strs.push("weujeuwihuew");
	strs.push("aszmnbxhzbx");
	strs.push("zxkcnzxjcnj");

	ft::stack<std::string> strs2;
	strs2 = strs;

	while (strs2.size() != 0){
		std::cout << strs2.top() << std::endl;
		strs2.pop();
		strs2.size();
	}

	std::cout << strs2.empty() << std::endl;
	std::cout << strs.empty() << std::endl;


}

void  testPushPop(){
	ft::stack<int> a;

	for (int i=0; i < 100000; i++){
		a.push(i);
		std::cout << a.size() << std::endl;
	}

	while (a.size() != 0){
		std::cout << a.top() << std::endl;
		a.pop();
		a.size();
	}
}

void testOperators(){
	ft::stack<int> a;
	a.push(12);
	a.push(13);
	a.push(14);
	std::cout << a.top() << std::endl;

	ft::stack<int> b;
	b.push(12);
	b.push(13);
	b.push(14);
	std::cout << b.top() << std::endl;

	if (a == b)
		std::cout << "a == b" << std::endl;
	if (a != b)
		std::cout << "a != b" << std::endl;
	if (a >= b)
		std::cout << "a >= b" << std::endl;
	if (a > b)
		std::cout << "a > b" << std::endl;
	if (a <= b)
		std::cout << "a <= b" << std::endl;
	if (a < b)
		std::cout << "a < b" << std::endl;
}


int main(){
	testOperators();
	testOtherMethods();
	testPushPop();
}
