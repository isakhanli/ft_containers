#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator>
#include "iterator_traits.hpp"

namespace ft {

	template<class T>
	class random_access_iterator {

		/* * * * * * * * * * * * * * *
		* 		Member Types
		* * * * * * * * * * * * * * */

	public:
		typedef T								*pointer;
		typedef T								&reference;
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef std::random_access_iterator_tag iterator_category;
		typedef T*								iterator_type;

	private:
		pointer ptr;

		/* * * * * * * * * * * * * * *
		* 		Member Functions
		* * * * * * * * * * * * * * */

	public:

		random_access_iterator() : ptr(0) {}; // ?

		random_access_iterator(pointer ptr) : ptr(ptr) {};

		~random_access_iterator() {};

		random_access_iterator(const random_access_iterator &copy)  { *this = copy; }

		random_access_iterator &operator=(const random_access_iterator &rhs) {
			if (this == &rhs)
				return *this;
			this->ptr = rhs.ptr;
			return *this;
		}

		// Const conversion
		operator random_access_iterator<const value_type> () const {
			return random_access_iterator<const value_type>(ptr);
		}

		pointer base() const { return ptr; }

		/*
			*a , a->m
		 */

		pointer operator->() const { return ptr; }

		reference operator*() const { return *ptr; }

		/*
		 	++a, a++
		 */

		random_access_iterator &operator++() {
			++ptr;
			return *this;
		}

		random_access_iterator operator++(int) {
			random_access_iterator temp = *this;
			++ptr;
			return temp;
		}

		/*
			--a, a--
		*/

		random_access_iterator &operator--() {
			--ptr;
			return *this;
		}

		random_access_iterator operator--(int) {
			random_access_iterator temp = *this;
			--ptr;
			return temp;
		}

		/*
			a + n, a -n, a - b
		 */

		random_access_iterator operator+(difference_type n) const {
			return ptr + n;
		};

		random_access_iterator operator-(difference_type n) const {
			return ptr - n;

		};

		difference_type operator-(const random_access_iterator &it) {
			return ptr - it.ptr;
		};

		difference_type operator+(const random_access_iterator &it) {
			return ptr + it.ptr;
		};

		/*
			a += n, a -= n
		 */

		random_access_iterator operator+=(difference_type n)  {
			ptr += n;
			return *this;
		};

		random_access_iterator operator-=(difference_type n)  {
			ptr -= n;
			return *this;
		};


		/*
			 a[n]
		 */

		reference operator[](difference_type n) const {
			return ptr[n];
		};

		};


			/* * * * * * * * * * * * * * *
			* 	  NON MEMBER FUNCTIONS
			* * * * * * * * * * * * * * */


		/*
			 n + a
		*/

		template<class T>
		random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n,
											const random_access_iterator<T> &rhs){
		return (rhs + n);
		}

		/*
			 a < b, a > b, a <= b, a >= b
		*/

		template<class Iterator1, class Iterator2>
		bool operator==(ft::random_access_iterator<Iterator1> const &lhs,
						ft::random_access_iterator<Iterator2> const &rhs){
			return (lhs.base() == rhs.base());
		}

		template<class Iterator1, class Iterator2>
		bool operator!=(ft::random_access_iterator<Iterator1> const &lhs,
						ft::random_access_iterator<Iterator2> const &rhs){
			return (lhs.base() != rhs.base());
		}

		template<class Iterator1, class Iterator2>
		bool operator>(ft::random_access_iterator<Iterator1> const &lhs,
						ft::random_access_iterator<Iterator2> const &rhs){
			return (lhs.base() > rhs.base());
		}

		template<class Iterator1, class Iterator2>
		bool operator>=(ft::random_access_iterator<Iterator1> const &lhs,
					   ft::random_access_iterator<Iterator2> const &rhs){
			return (lhs.base() >= rhs.base());
		}

		template<class Iterator1, class Iterator2>
		bool operator<(ft::random_access_iterator<Iterator1> const &lhs,
						ft::random_access_iterator<Iterator2> const &rhs){
			return (lhs.base() < rhs.base());
		}

		template<class Iterator1, class Iterator2>
		bool operator<=(ft::random_access_iterator<Iterator1> const &lhs,
					   ft::random_access_iterator<Iterator2> const &rhs){
			return (lhs.base() <= rhs.base());
		}
}

#endif
