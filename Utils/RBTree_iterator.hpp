#ifndef RBTREE_ITERATOR_HPP
#define RBTREE_ITERATOR_HPP

#include "../Utils/RedBlackTree.hpp"
#include "RedBlackTree.hpp"

namespace ft{

	template<class Pair, class NodePointer>
	class rb_tree_iterator{


		/* * * * * * * * * * * * * * *
		*   	Member Types
		* * * * * * * * * * * * * * */


	public:
		typedef Pair       	value_type;
		typedef Pair&  		reference;
		typedef Pair* 		pointer;
		typedef NodePointer	node_pointer;


		typedef std::ptrdiff_t								difference_type;
		typedef typename std::bidirectional_iterator_tag	iterator_category;


	public:
		node_pointer ptr;
		node_pointer root;
		node_pointer nil;


		/* * * * * * * * * * * * * * *
		*   	Canonical Form
		* * * * * * * * * * * * * * */


	public:
		rb_tree_iterator() :
			ptr(NULL), root(NULL), nil(NULL){
		}

		rb_tree_iterator(node_pointer ptr, node_pointer root, node_pointer  nil) :
			ptr(ptr), root(root), nil(nil){
		}

		template <typename U, typename P1> rb_tree_iterator(const rb_tree_iterator<U,P1>& u) {
			ptr = u.ptr;
			root = u.root;
			nil = u.nil;
		}

		rb_tree_iterator(const rb_tree_iterator &copy){
			*this = copy;
		}

		rb_tree_iterator &operator=(const rb_tree_iterator &rbt){
			if (this == &rbt)
				return *this;
			this->ptr = rbt.ptr;
			this->root = rbt.root;
			this->nil = rbt.nil;
			return *this;
		}

		~rb_tree_iterator(){
		};


//		// const conversion
//		operator	rb_tree_iterator<const T, Node> (void){
//			return rb_tree_iterator<const T, Node>(ptr, root, nil);
//		}

		/* * * * * * * * * * * * * * *
		*      Operator overloads
		* * * * * * * * * * * * * * */


		bool operator==(const rb_tree_iterator &rbt) const{
			return ptr == rbt.ptr;
		}

		bool operator!=(const rb_tree_iterator &rbt) const{
			return ptr != rbt.ptr;
		}

		reference operator*() const{
			return ptr->val;
		}

		pointer operator->() const{
			return &ptr->val;
		}

		rb_tree_iterator &operator++(){
			if (ptr == getMax(root)){
				ptr = nil;
				return *this;
			}else if (ptr == nil){
				ptr = NULL;
				return *this;
			}else
				ptr = findNext(ptr);
			return *this;
		}

		rb_tree_iterator operator++(int){
			rb_tree_iterator 	tmp = *this;
			operator++();
			return tmp;
		}

		rb_tree_iterator &operator--(){
			if (ptr == nil){
				ptr = getMax(root);
				return *this;
			}
			ptr = findPrevious(ptr);
			return *this;
		}

		rb_tree_iterator operator--(int){
			rb_tree_iterator 	tmp = *this;
			operator--();
			return tmp;
		}


		/* * * * * * * * * * * * * * *
		*     HELPER FUNCTIONS
		* * * * * * * * * * * * * * */

		//while (ndptr)
		node_pointer getMax(node_pointer ndptr){
			while (ndptr && ndptr->right != nil)
				ndptr = ndptr->right;
			return ndptr;
		}

		node_pointer getMin(node_pointer ndptr){
			while (ndptr && ndptr->left != nil)
				ndptr = ndptr->left;
			return ndptr;
		}

		node_pointer findNext(node_pointer ndptr){
			if (ndptr->right != nil)
				return getMin(ndptr->right);

			node_pointer temp = ndptr->parent;
			while (temp != nil && ndptr == temp->right){
				ndptr = temp;
				temp = temp->parent;
			}
			return temp;
		}

		node_pointer findPrevious(node_pointer ndptr){
			if (ndptr->left != nil)
				return getMax(ndptr->left);

			node_pointer tmp = ndptr->parent;
			while (tmp != nil && ndptr == tmp->left){
				ndptr = tmp;
				tmp = tmp->parent;
			}
			return tmp;
		}

		node_pointer getPtr(){
			return ptr;
		}
	};
}

#endif
