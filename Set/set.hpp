#ifndef SET_HPP
#define SET_HPP

#include "../Utils/RedBlackTree.hpp"

namespace ft{
	template< class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
	class set{


			/* * * * * * * * * * * * * * *
			* 		MEMBER TYPES
			* * * * * * * * * * * * * * */


	public:
		typedef Key															key_type;
		typedef Key															value_type;
		typedef std::size_t 												size_type;
		typedef std::ptrdiff_t												difference_type;
		typedef Compare														key_compare;
		typedef Compare														value_compare;
		typedef Allocator													allocator_type;
		typedef value_type&													reference;
		typedef const value_type&											const_reference;
		typedef typename Allocator::pointer									pointer;
		typedef typename Allocator::const_pointer							const_pointer;

	private:
		typedef RBTree<value_type, key_type, key_compare, allocator_type> rbTree;

	public:
		typedef typename rbTree::iterator 		 							iterator;
		typedef typename rbTree::const_iterator 							const_iterator;
		typedef typename rbTree::reverse_iterator 							reverse_iterator;
		typedef typename rbTree::const_reverse_iterator 					const_reverse_iterator;

	private:
		rbTree		 		_rbTree;
		allocator_type		_alloc;
		key_compare			_compare;


			/* * * * * * * * * * * * * * * * *
			* 	CONSTRUCTORS & OTHER METHODS
			* * * * * * * * * * * * * * * * */


	public:

		explicit set(const Compare& comp = key_compare(), const Allocator& alloc = Allocator())
		: _rbTree(), _alloc(alloc), _compare(comp){

		}

		template< class InputIt >
		set(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()){
			_alloc = alloc;
			_compare = comp;
			while (first != last) {
				_rbTree.insert(*first);
				first++;
			}
		}

		set(const set& other){
			*this = other;
		}

		~set(){
			clear();
			_rbTree.deallocateNil();
		}

		set& operator=(const set& other){
			if (this == &other)
				return *this;

			_rbTree = other._rbTree;
			_compare = other._compare;
			_alloc = other._alloc;
			return *this;
		}

		allocator_type get_allocator() const{
			return _alloc;
		}

			/* * * * * * * * * * * * * * * * *
			* 		     ITERATORS
			* * * * * * * * * * * * * * * * */

		iterator					begin() {return	_rbTree.begin(); }
		const_iterator 				begin() const {return	_rbTree.begin(); }
		iterator					end() {return	_rbTree.end(); }
		const_iterator				end() const {return	_rbTree.end(); }
		reverse_iterator 			rbegin() {return	_rbTree.rbegin(); }
		const_reverse_iterator 		rbegin() const {return	_rbTree.rbegin(); }
		reverse_iterator			rend() {return	_rbTree.rend(); }
		const_reverse_iterator		rend() const {return	_rbTree.rend(); }


			/* * * * * * * * * * * * * * * * *
			* 		     CAPACITY
			* * * * * * * * * * * * * * * * */


		bool empty() const{
			return (size() == 0);
		}

		size_type size() const{
			return _rbTree.size();
		}

		size_type max_size() const{
			return _rbTree.max_size();
		}


			/* * * * * * * * * * * * * * * * *
			* 		     MODIFIERS
			* * * * * * * * * * * * * * * * */

		void clear(){
			_rbTree.clear();
		}

		ft::pair<iterator, bool> insert(const value_type& value){
			bool isInserted = _rbTree.insert(value);
			return ft::make_pair(find(value), isInserted);
		}

		iterator insert(iterator hint, const value_type& value){
			(void)hint;
			insert(value);
			return find(value);
		}

		template< class InputIt >
		void insert(InputIt first, InputIt last){
			while (first != last){
				insert(*first);
				first++;
			}
		}

		void erase(iterator pos){
			erase(*pos);
		}

		void erase(iterator first, iterator last ){
			while(first != last){
				first = find(*first);
				erase(*(first++));
			}
		}

		size_type erase(const Key& key){
			return _rbTree.erase(key);
		}

		void swap(set& other){
			_rbTree.swap(other._rbTree);
		}


			/* * * * * * * * * * * * * * * * *
			* 		     LOOKUP
			* * * * * * * * * * * * * * * * */

		size_type count( const Key& key ) const{
			return (find(key) != end());
		}

		iterator find(const Key& key){
			return iterator(_rbTree.find(key), _rbTree.getRoot(), _rbTree.getNil());
		}

		const_iterator find( const Key& key ) const{
			return const_iterator(_rbTree.find(key), _rbTree.getRoot(), _rbTree.getNil());
		}

		iterator lower_bound(const Key& key){
			return _rbTree.lower_bound(key);
		}

		const_iterator lower_bound(const Key& key) const{
			return _rbTree.lower_bound(key);
		}

		iterator upper_bound(const Key& key){
			return _rbTree.upper_bound(key);
		}

		const_iterator upper_bound(const Key& key) const{
			return _rbTree.upper_bound(key);
		}

		ft::pair<iterator,iterator> equal_range(const Key& key){
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}

		ft::pair<const_iterator,const_iterator> equal_range(const Key& key) const{
			return ft::make_pair(lower_bound(key), upper_bound(key));
		}


			/* * * * * * * * * * * * * * * * *
			* 		     OBSERVERS
			* * * * * * * * * * * * * * * * */

		key_compare key_comp() const{
			return key_compare();
		}

		value_compare value_comp() const{
			return key_compare();
		}



	};


			/* * * * * * * * * * * * * * * * *
			* 		NON MEMBER FUNCTIONS
			* * * * * * * * * * * * * * * * */

		template< class Key, class Compare, class Alloc >
		bool operator==( const ft::set<Key,Compare,Alloc>& lhs,
						 const ft::set<Key,Compare,Alloc>& rhs ){
			return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}

		template< class Key, class Compare, class Alloc >
		bool operator!=( const ft::set<Key,Compare,Alloc>& lhs,
						 const ft::set<Key,Compare,Alloc>& rhs ){
			return !(lhs == rhs);
		}

		template< class Key, class Compare, class Alloc >
		bool operator<( const ft::set<Key,Compare,Alloc>& lhs,
						const ft::set<Key,Compare,Alloc>& rhs ){
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

		template< class Key, class Compare, class Alloc >
		bool operator<=( const ft::set<Key,Compare,Alloc>& lhs,
						 const ft::set<Key,Compare,Alloc>& rhs ){
			return !(rhs < lhs);
		}

		template< class Key, class Compare, class Alloc >
		bool operator>( const ft::set<Key,Compare,Alloc>& lhs,
						const ft::set<Key,Compare,Alloc>& rhs ){
			return rhs < lhs;

		}
		template< class Key, class Compare, class Alloc >
		bool operator>=( const ft::set<Key,Compare,Alloc>& lhs,
						 const ft::set<Key,Compare,Alloc>& rhs ){
			return !(rhs > lhs);
		}

		template< class Key, class Compare, class Alloc >
		void swap( ft::set<Key,Compare,Alloc>& lhs,
				   ft::set<Key,Compare,Alloc>& rhs ){
			lhs.swap(rhs);
		}
}


#endif
