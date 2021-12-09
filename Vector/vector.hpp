#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
#include "../Utils/random_access_iterator.hpp"
#include "../Utils/reverse_iterator.hpp"
#include "../Utils/utility.hpp"
#include <exception>
#include <stdexcept>

namespace ft{

	template <class T, class Allocator = std::allocator<T> >
	class vector{


		/* * * * * * * * * * * * * * *
		* 		MEMBER TYPES
		* * * * * * * * * * * * * * */

	public:
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef value_type&										reference;
		typedef const value_type&								const_reference;
		typedef typename Allocator::value_type					pointer;
		typedef typename Allocator::const_pointer				const_pointer;
		typedef ft::random_access_iterator<value_type>			iterator;
		typedef ft::random_access_iterator<const value_type>	const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef std::ptrdiff_t 									difference_type;
		typedef std::size_t										size_type;


		/* * * * * * * * * * * * * * *
		* 		PRIVATE MEMBERS
		* * * * * * * * * * * * * * */

	private:
		value_type* 	_data;
		size_type		_size;
		size_type		_capacity;
		allocator_type	alloc;

		/* * * * * * * * * * * * * * *
		* 		CONSTRUCTORS
		* * * * * * * * * * * * * * */

	public:
		//DEFAULT
		explicit vector (const allocator_type& alloc = allocator_type()):
		_size(0), _capacity(0), alloc(alloc), _data(NULL){}

		//FILL
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()):
		_size(n), _capacity(n), alloc(alloc){
			_data = this->alloc.allocate(_size);
			for (size_type i = 0; i < n; i++)
				this->alloc.construct(_data + i, val);
		}

		//RANGE
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) :alloc(alloc){
			size_type len = last - first;
			_size = len;
			_capacity = len;
			_data =  this->alloc.allocate(_capacity);

			for (size_type i = 0; i < len; i++) {
				this->alloc.construct((_data + i), *first);
				first++;
			}
		}

		//COPY
		vector (const vector &copy)
			: _capacity(copy._capacity), _size(copy._size), alloc(copy.alloc){
			this->_data = alloc.allocate(_capacity);

			for (size_type i = 0; i < _size; i++)
				alloc.construct(_data + i, copy._data[i]);
		}

		vector& operator=(const vector& other){
			if (this == &other)
				return *this;

			clear();
			alloc.deallocate(_data, _capacity);

			this->_capacity = other._capacity;
			this->alloc = other.alloc;
			this->_size = other._size;
			this->_data = alloc.allocate(_capacity);

			for (size_type i = 0; i < _size; i++)
				alloc.construct(_data + i, other._data[i]);

			return *this;
		}

		//DESTRUCTOR
		~vector(){
//			if (_data) {
				clear();
				alloc.deallocate(_data, _capacity);
//			}
		}


		allocator_type get_allocator() const{
			return alloc;
		}


		void assign (size_type count, const value_type& val){
			clear();
			if (count > _capacity){
				alloc.deallocate(_data, _capacity);
				_data = alloc.allocate(count);
				_capacity = count;
			}
			for (size_type i = 0; i < count; i++)
				alloc.construct(_data + i, val);
			_size = count;
		}


		template <class InputIt>
		void assign (InputIt first, InputIt last,
					 typename enable_if<!is_integral<InputIt>::value>::type* = 0){
			clear();
			size_type  count = last - first;
			if (count > _capacity){
				alloc.deallocate(_data, _capacity);
				_data = alloc.allocate(count);
				_capacity = count;
			}

			for (size_type i = 0; i < count; i++) {
				alloc.construct(_data + i, *first);
				first++;
			}
			_size = count;

		}




		/* * * * * * * * * * * * * * *
		 * 			ITERATORS
		 * * * * * * * * * * * * * * */


		iterator begin() { return iterator(_data); }
		iterator end() { return iterator(_data + _size); }

		const_iterator begin() const { return const_iterator(_data); }
		const_iterator end() const{ return const_iterator(_data + _size); }

		reverse_iterator rbegin()  { return reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }

		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
		const_reverse_iterator rend() const{ return const_reverse_iterator(begin()); }


		/* * * * * * * * * * * * * * *
		 * 	ELEMENT ACCESS METHODS
		 * * * * * * * * * * * * * * */

		reference at(size_type pos){
			if (!(pos < size()))
				throw std::out_of_range("Out of range");
			return _data[pos];
		}

		const_reference at( size_type pos ) const{
			if (!(pos < size()))
				throw std::out_of_range("Out of range");
			return _data[pos];
		}

		reference operator[]( size_type pos ){
			return _data[pos];
		}

		const_reference operator[]( size_type pos ) const{
			return _data[pos];
		}

		reference front(){
			return _data[0];
		}

		const_reference front() const{
			return _data[0];
		}

		reference back(){
			return _data[_size -1];
		}

		const_reference back() const{
			return _data[_size - 1];
		}

		T* data(){
			return _data;
		}

		const T* data() const{
			return _data;
		}



		/* * * * * * * * * * * * * * *
		 * 			CAPACITY
		 * * * * * * * * * * * * * * */

		bool empty() const{
			return (_size == 0);
		}

		size_type size() const{
			return _size;
		}

		size_type capacity() const{
			return _capacity;
		}

		//need to check
		size_type max_size() const{
			return alloc.max_size();
		}

		void reserve(size_type new_cap){
			if (new_cap > max_size())
				throw std::length_error("Length error");
			if (new_cap < _capacity)
				return;

			T* newAlloc = alloc.allocate(new_cap);

			for (size_type i = 0; i < _size; i++)
				alloc.construct(newAlloc + i, _data[i]);

			for (size_type i = 0; i < _size; i++)
				alloc.destroy(_data + i);

			if (_data)
				alloc.deallocate(_data, _capacity);

			_capacity = new_cap;
			_data = newAlloc;
		}



		/* * * * * * * * * * * * * * *
		 * 			MODIFIERS
		 * * * * * * * * * * * * * * */


		void clear(){
			for (size_type i = _size; i > 0; i--)
				alloc.destroy(_data + i);

			_size = 0;
		}

		iterator insert(iterator pos, const T& value){
			size_type index = pos - begin();

			if (_size == _capacity){
				size_type new_cap = (_capacity == 0) ? _capacity + 1 : _capacity * 2;
				value_type *newAlloc = alloc.allocate(new_cap);
				for (size_type i = 0; i < (_size - index); i++)
					alloc.construct(newAlloc + i, _data[i]);

				alloc.construct(newAlloc + index, value);

				for (size_type i = index + 1; i <= _size; i++)
					alloc.construct(newAlloc + i, _data[i - 1]);

				for (size_type i = 0; i < _size; i++)
					alloc.destroy(&_data[i]);


				alloc.deallocate(_data, _capacity);

				_data = newAlloc;
				_capacity = new_cap;
			}else{
				for (size_type i = _size; i > index; i--){
					alloc.destroy(_data + i);
					alloc.construct(_data + i, *(_data + i -1));
				}
				alloc.destroy(_data + index);
				alloc.construct(_data + index, value);
			}

			_size++;
			return begin() + index;
		}


		void insert(iterator pos, size_type count, const T& value){
			size_type index = pos - begin();

			if (_size + count > _capacity){
				size_type new_cap = (_capacity * 2 >= _size + count ) ? _capacity * 2 : _size + count;
				value_type *newAlloc = alloc.allocate(new_cap);

				for (size_type i = 0; i < (_size - index); i++)
					alloc.construct(newAlloc + i, _data[i]);
				for (size_type i = 0; i < count; i++)
					alloc.construct(newAlloc + index + i, value);
				for (size_type i = index; i < _size; i++)
					alloc.construct(newAlloc + i + count, _data[i]);
				for (size_type i = 0; i < _size; i++)
					alloc.destroy(_data + i);
				if (_data)
					alloc.deallocate(_data, _capacity);

				_data = newAlloc;
				_capacity = new_cap;
			}else{
				for (size_type i = _size; i > index; i--){
					alloc.destroy(_data + i + count - 1);
					alloc.construct(_data + i + count - 1, _data[i -1]);
				}
				for (size_type i = index; i < index + count; i++){
					alloc.destroy(_data + i);
					alloc.construct(_data + i, value);
				}
			}
			_size += count;
		}

		template< class InputIt >
		void insert(iterator pos, InputIt first, InputIt last,
			typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type * = NULL){

			size_type index = pos - begin();
			size_type count = last - first;

			value_type *newAlloc;
			size_type new_cap = (_capacity * 2 >= _size + count) ? _capacity * 2 : _size + count;

			try{
				if (_size + count > _capacity) {
					newAlloc = alloc.allocate(new_cap);

					for (size_type i = 0; i < (_size - index); i++)
						alloc.construct(newAlloc + i, _data[i]);

					for (size_type i = 0; i < count; i++) {
						alloc.construct(newAlloc + index + i, *(first));
						first++;
					}
					for (size_type i = index; i < _size; i++)
						alloc.construct(newAlloc + i + count, _data[i]);

					for (size_type i = 0; i < _size; i++)
						alloc.destroy(_data + i);
					if (_data)
						alloc.deallocate(_data, _capacity);

					_data = newAlloc;
					_capacity = new_cap;
				} else {
					for (size_type i = _size; i > index; i--) {
						alloc.destroy(_data + i + count - 1);
						alloc.construct(_data + i + count - 1, _data[i - 1]);
					}
					for (size_type i = index; i < index + count; i++) {
						alloc.destroy(_data + i);
						alloc.construct(_data + i, *first);
						first++;
					}
				}
				_size += count;
			}catch(...) {
				for(int i = 0; i < count; i++)
					alloc.destroy(newAlloc + i +index);
				alloc.deallocate(newAlloc, new_cap);
				throw;
			}

		}

		iterator erase (iterator pos){
			size_type index = pos - begin();
			alloc.destroy(_data + index);

			for (size_type i = index; i < _size - 1; i++)
				alloc.construct(_data + i, _data[i + 1]);

			_size--;
			return iterator(_data + index);

		}

		iterator erase (iterator first, iterator last){
			size_type index = first - begin();
			size_type count = last - first;

			while (first != last){
				alloc.destroy(&(*first));
				first++;
			}

			size_type temp = index;

			while (last < this->end()){
				alloc.construct(_data + temp, *last);
				temp++;
				last++;
			}

			_size -= count;
			return iterator(_data + index);
		}




		void push_back (const value_type& val){
			if (_size == _capacity) {
				_capacity = (_capacity == 0) ? (_capacity + 1) : (_capacity * 2);
				this->reserve(_capacity);
			}
			this->alloc.construct(_data + _size, val);
			_size++;
		}

		void pop_back(){
			alloc.destroy(&_data[_size-1]);
			_size--;
		}

		void resize (size_type count, value_type val = value_type()){
			if (_size > count){
				for (size_type i = count; i > _size; i++)
					alloc.destroy(_data + i);
				_size = count;
			}else if (_size < count){
				if (_capacity < count) {
					size_type new_cap = (_capacity * 2 > count) ? _capacity * 2 : count;
					reserve(new_cap);
					}
				for (size_type i = _size; i < count; i++) {
					alloc.construct(_data + i, val);
					_size++;
				}
			}
		}

		void swap(vector &x){
			std::swap(this->_data, x._data);
			std::swap(this->_size, x._size);
			std::swap(this->_capacity, x._capacity);
			std::swap(this->alloc, x.alloc);

//			if (this == &x)
//				return;

//			value_type *temp_data = x._data;
//			size_type temp_size = x._size;
//			size_type temp_capacity = x._capacity;
//			allocator_type temp_alloc = x.alloc;
//
//			x._data = this->_data;
//			x._size = this->_size;
//			x._capacity = this->_capacity;
//			x.alloc = this->alloc;
//
//			this->_data = temp_data;
//			this->_size = temp_size;
//			this->_capacity = temp_capacity;
//			this->alloc = temp_alloc;


		}

	};

	/* * * * * * * * * * * * * * *
	* 	NON MEMBER FUNCTIONS
	* * * * * * * * * * * * * * */

	template < class T, class Alloc >
	bool operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ){

		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template < class T, class Alloc >
	bool operator!=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ){

		return !(lhs == rhs);
	}

	template < class T, class Alloc >
	bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ){

		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template < class T, class Alloc >
	bool operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ){

		return rhs < lhs;
	}

	template < class T, class Alloc >
	bool operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ){

		return !(lhs > rhs);
	}

	template < class T, class Alloc >
	bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ){

		return !(lhs < rhs);
	}

	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y){
		x.swap(y);
	}

}

#endif