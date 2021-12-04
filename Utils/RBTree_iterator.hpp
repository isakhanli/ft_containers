#ifndef RBTREE_ITERATOR_HPP
#define RBTREE_ITERATOR_HPP

#include "../Utils/RedBlackTree.hpp"
#include "RedBlackTree.hpp"

namespace ft{

	template<class T, class Node>
	class rb_tree_iterator{

	public:
		typedef T       value_type;
		typedef T&  	reference;
		typedef T* 		pointer;
		typedef Node*	node_pointer;


		typedef std::ptrdiff_t									difference_type;
		typedef typename std::bidirectional_iterator_tag	iterator_category;


		/* * * * * * * * * * * * * * *
		*   	Canonical Form
		* * * * * * * * * * * * * * */

	public:
		rb_tree_iterator() :
			ptr(NULL), root(NULL), nil(NULL){
		}

		rb_tree_iterator(node_pointer ptr, node_pointer root, node_pointer nil) :
			ptr(ptr), root(root), nil(nil){
		}

		rb_tree_iterator(const rb_tree_iterator &copy) :
			ptr(copy.ptr), root(copy.root), nil(copy.nil){
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

		/* * * * * * * * * * * * * * *
		*      Operator overloads
		* * * * * * * * * * * * * * */


		bool operator==(const rb_tree_iterator &rbt) const{
			return ptr == rbt.ptr;
		}

		bool operator!=(const rb_tree_iterator &rbt) const{
			return ptr != rbt.ptr;
		}


		reference operator*(){
			return ptr->val;
		}

		pointer operator->(){
			return &ptr->val;
		}

		node_pointer getMax(node_pointer ndptr){
			while (ndptr->right != nil)
				ndptr = ndptr->right;
			return ndptr;
		}

		node_pointer getMin(node_pointer ndptr){
			while (ndptr->left != nil)
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




//		pointer findNext(){
//
//		}

	private:
		node_pointer ptr;
		node_pointer root;
		node_pointer nil;




	};
}

#endif
