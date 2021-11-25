#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace ft {

	/* * * * * * * * * * * * * * *
 	* 		ENABLE_IF
 	* * * * * * * * * * * * * * */

	template<bool Cond, class T = void>
	struct enable_if {
	};

	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};

	/* * * * * * * * * * * * * * *
 	* 		IS_INTEGRAL
 	* * * * * * * * * * * * * * */

	template <class T>
	struct is_integral{ static const bool value = false; };

	template <>
	struct is_integral<bool> { static const bool value = true; };

	template <>
	struct is_integral<char>{ static const bool value = true; };

	template <>
	struct is_integral<wchar_t> { static const bool value = true; };

	template <>
	struct is_integral<signed char>{ static const bool value = true; };

	template <>
	struct is_integral<unsigned char> { static const bool value = true; };


	template <>
	struct is_integral<short int> { static const bool value = true; };

	template <>
	struct is_integral<int> { static const bool value = true; };

	template <>
	struct is_integral<long int> { static const bool value = true; };

	template <>
	struct is_integral<long long int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned short int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long int> { static const bool value = true; };

	template <>
	struct is_integral<unsigned long long int> { static const bool value = true; };


	/* * * * * * * * * * * * * * *
 	* 		     EQUAL
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
 	*   LEXICOGRAPHICAL COMPARE
 	* * * * * * * * * * * * * * */

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								  InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 <* first2)
				return true;
			++first1;
			++first2;
		}
		return (first2!=last2);
	}

}


#endif
