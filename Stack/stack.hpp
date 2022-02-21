#ifndef STACK_HPP
#define STACK_HPP

#include "../Vector/vector.hpp"


namespace ft{

	template <class T, class Container = ft::vector<T> >
	class stack{

			/* * * * * * * * * * * * * * * * * *
			* 			Member Types
			* * * * * * * * * * * * * * * * * */

	public:
		typedef Container							container_type;
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_type		size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;

	protected:
		// Member Object
		container_type c;


			/* * * * * * * * * * * * * * * * * *
			* 	Constructors & Other Functions
			* * * * * * * * * * * * * * * * * */


	public:
		explicit stack(const Container& cont = Container()) : c(cont){
		}

		virtual ~stack(){

		}

		stack& operator=(const stack& other){
			if (this == &other)
				return *this;
			c = other.c;
			return *this;
		}


			/* * * * * * * * * * * * * * * * * *
			* 			Element Access
			* * * * * * * * * * * * * * * * * */


		reference top(){
			return c.back();
		}

		const_reference top() const{
			return c.back();
		}


			/* * * * * * * * * * * * * * * * * *
			* 			Capacity
			* * * * * * * * * * * * * * * * * */


		bool empty() const{
			return c.empty();
		}

		size_type size() const{
			return c.size();
		}


			/* * * * * * * * * * * * * * * * * *
			* 		Element Access
			* * * * * * * * * * * * * * * * * */


		void push( const value_type& value ){
			c.push_back(value);
		}

		void pop(){
			c.pop_back();
		}


			/* * * * * * * * * * * * * * * * * *
			* 		Operator Overloads
			* * * * * * * * * * * * * * * * * */


		template< class U, class Cont >
		friend bool operator==( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs );

		template< class U, class Cont >
		friend bool operator<( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs );

	};

	template< class U, class Cont >
	bool operator==( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs ){
		return lhs.c == rhs.c;
	}

	template< class U, class Cont >
	bool operator!=( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs ){
		return !(lhs == rhs);
	}

	template< class U, class Cont >
	bool operator<( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs ){
		return lhs.c < rhs.c;
	}

	template< class U, class Cont >
	bool operator<=( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs ){
		return !(rhs < lhs);
	}

	template< class U, class Cont >
	bool operator>( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs ){
		return rhs < lhs;
	}

	template< class U, class Cont >
	bool operator>=( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs ){
		return !(lhs < rhs);
	}
}

#endif
