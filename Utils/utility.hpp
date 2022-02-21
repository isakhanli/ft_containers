#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft {

			/* * * * * * * * * * * * * * *
			* 		Enable_if
			* * * * * * * * * * * * * * */


	template<bool Cond, class T = void>
	struct enable_if {
	};

	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};


			/* * * * * * * * * * * * * * *
			* 		Is_integral
			* * * * * * * * * * * * * * */


	template <class T, T v>
	struct integral_constant{
		static const T value = v;

		typedef T                  		value_type;
		typedef integral_constant<T,v>  type;

		operator value_type() const { return value; }
	};

	typedef integral_constant<bool, true>   true_type;
	typedef integral_constant<bool, false>  false_type;

	template <class T> struct is_integral                     : public false_type {};
	template <>        struct is_integral<bool>               : public true_type {};
	template <>        struct is_integral<char>               : public true_type {};
//	template <>        struct is_integral<char16_t>           : public true_type {};
//	template <>        struct is_integral<char32_t>           : public true_type {};
	template <>        struct is_integral<signed char>        : public true_type {};
	template <>        struct is_integral<unsigned char>      : public true_type {};
	template <>        struct is_integral<wchar_t>            : public true_type {};
	template <>        struct is_integral<short>              : public true_type {};
	template <>        struct is_integral<unsigned short>     : public true_type {};
	template <>        struct is_integral<int>                : public true_type {};
	template <>        struct is_integral<unsigned int>       : public true_type {};
	template <>        struct is_integral<long>               : public true_type {};
	template <>        struct is_integral<unsigned long>      : public true_type {};
	template <>        struct is_integral<long long>          : public true_type {};
	template <>        struct is_integral<unsigned long long> : public true_type {};


			/* * * * * * * * * * * * * * *
			* 		     Equal
			* * * * * * * * * * * * * * */


	template <class InputIterator1, class InputIterator2>
	bool equal ( InputIterator1 begin1, InputIterator1   end1, InputIterator2 begin2 ) {
		while (begin1 != end1) {
			if (!(*begin1 == *begin2))
				return false;
			++begin1;
			++begin2;
		}
		return true;
	}


			/* * * * * * * * * * * * * * *
			*   Lexicographcial Compare
			* * * * * * * * * * * * * * */


	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								  InputIterator2 first2, InputIterator2 last2){
		while (first1 != last1){
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 <* first2)
				return true;
			++first1;
			++first2;
		}
		return (first2!=last2);
	}


			/* * * * * * * * * * * * * * *
			*   		Pair
			* * * * * * * * * * * * * * */


	template< class T1, class T2>
	struct pair{

		typedef	T1		first_type;
		typedef	T2		second_type;

		pair() : first(first_type()), second(second_type()){
		}

		pair(const T1& x, const T2& y) : first(x), second(y){
		}

		template< class U1, class U2 >
		pair(const pair<U1, U2>& p): first(p.first), second(p.second){
		}

		pair& operator=(const pair& other){
			if (this == &other)
				return *this;
			this->first = other.first;
			this->second = other.second;
			return *this;
		}

		first_type first;
		second_type second;

	};

	template< class T1, class T2 >
	ft::pair<T1,T2> make_pair(T1 t, T2 u){
		return pair<T1, T2>(t, u);
	}

	template< class T1, class T2 >
	bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template< class T1, class T2 >
	bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return !(lhs == rhs);
	}

	template< class T1, class T2 >
	bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return (lhs.first < rhs.first) || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	}

	template< class T1, class T2 >
	bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return !(rhs < lhs);
	}

	template< class T1, class T2 >
	bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return (rhs < lhs);
	}

	template< class T1, class T2 >
	bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs ){
		return !(lhs < rhs);
	}

}

#endif
