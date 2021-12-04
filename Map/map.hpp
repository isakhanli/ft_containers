#ifndef MAP_HPP
#define MAP_HPP

#include "../Utils/RedBlackTree.hpp"
#include "../Utils/RBTree_iterator.hpp"

namespace ft{
	template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map{

			/* * * * * * * * * * * * * * *
 			* 		MEMBER TYPES
			* * * * * * * * * * * * * * */
	public:
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef ft::pair<const Key, T>					value_type;
		typedef std::size_t 							size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef Compare									key_compare;
		typedef Allocator								allocator_type;
		typedef value_type&								reference;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		typedef ft::rb_tree_iterator<value_type, RBNode<value_type> >		iterator;
		typedef ft::rb_tree_iterator<const value_type, RBNode<value_type> >	const_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;


		class value_compare{
		protected:
			key_compare comp;

		public:
			bool operator()(const value_type& lhs, const value_type& rhs) const{
				return comp(lhs.first, rhs.first);
			}
		};

	private:
		typedef RBTree<value_type, key_compare, allocator_type> _RBTree;


	public: //temporary for testing
		_RBTree			_data;
		key_compare		_compare;
		allocator_type 	_alloc;



		/* * * * * * * * * * * * * * *
		 * 		CONSTRUCTORS
		 * * * * * * * * * * * * * * */

	public:
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) {

		}

		template< class InputIt >
		map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()){

		}


		/* * * * * * * * * * * * * * *
 		* 		Iterators
 		* * * * * * * * * * * * * * */

		iterator		begin(){
			return       iterator(_data.getMin(), _data.getRoot(), _data.getNil());
		}

		iterator		end(){
			return       iterator(_data.getNil(), _data.getRoot(), _data.getNil());
		}

		reverse_iterator		rbegin(){
			return       	reverse_iterator(end());
		}

		reverse_iterator		rend(){
			return       	reverse_iterator(begin());
		}

		/* * * * * * * * * * * * * * *
 		* 		ELEMENT ACCESS
 		* * * * * * * * * * * * * * */

		T& operator[](const Key& key){
			insert(ft::make_pair(key, mapped_type()));
			iterator res = find(key);
			return res->second;
		}

		/* * * * * * * * * * * * * * *
 		* 		CAPACITY
 		* * * * * * * * * * * * * * */

		bool empty() const{
			return _data.isEmpty();
		}

		size_type size() const{
			return _data.size();
		}

		size_type max_size() const{
			return _data.max_size();
		}

		/* * * * * * * * * * * * * * *
 		* 		MODIFIERS
 		* * * * * * * * * * * * * * */

		void clear(){
			_data.clear();
		}

		ft::pair<iterator, bool> insert( const value_type& value ) {
			bool isInserted = _data.insert(value);
			return ft::make_pair(find(value.first), isInserted);
		}

		template< class InputIt >
		void insert( InputIt first, InputIt last ){
			while (first != last){
				insert(*first);
				first++;
			}
		}

		iterator insert(iterator hint, const value_type& value){
			(void)hint;
			insert(value);
			return find(value.first);
		}

		void swap(map& other ){

		}


		iterator find(const key_type &key){
			return iterator( _data.search(ft::make_pair(key, mapped_type())), _data.getRoot(), _data.getNil());
		}
	};


	};

#endif
