#include "stack.hpp"
#include <stack>


int main(){
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
