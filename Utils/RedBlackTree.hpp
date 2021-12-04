#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include <iostream>
#include "../Utils/utility.hpp"
#include "../Utils/RBTree_iterator.hpp"
#include "../Utils/reverse_iterator.hpp"

enum Color{
	BLACK,
	RED
};

template <class T>
class RBNode{
public:
	typedef T	value_type;

	RBNode 			*left;
	RBNode 			*right;
	RBNode 			*parent;
	value_type 		val;
	int 			color;

	RBNode():
		left(NULL), right(NULL), parent(NULL), val(), color(BLACK){}

	RBNode(const value_type &data) : left(), right(), val(data), color(BLACK){

	}

	RBNode(const value_type &data, RBNode *left, RBNode *right, RBNode *parent, int color)
		: left(left), right(right), val(data), color(color){

	}

	~RBNode(){};
};

template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
class RBTree{
public:
	typedef T														value_type;
	typedef std::size_t												size_type;
	typedef Compare													key_compare;
//	typedef Allocator												_alloc;
	typedef typename Allocator::template rebind<RBNode<T> >::other	_alloc;

	typedef typename _alloc::pointer								pointer;
	typedef ft::rb_tree_iterator<value_type, RBNode<value_type> >						iterator;
	typedef ft::rb_tree_iterator<const value_type, RBNode<value_type> >					const_iterator;
	typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;


//	typedef RBNode<value_type> *pointer;


	pointer 			root;
	pointer 			nil;
	size_type			_size;
	_alloc 				alloc;
	key_compare 		comp;


	RBTree(key_compare const& cmp = key_compare()) : comp(cmp){
		_size = 0;
		nil = alloc.allocate(1);
		alloc.construct(nil, RBNode<T>());
//		nil->parent = NULL;
//		nil->right = NULL;
//		nil->left = NULL;
//		nil->color = BLACK;
		root = nil;
		_size = 0;
	}


	pointer getRoot(){
		return root;
	}

	pointer getNil(){
		return nil;
	}

	pointer getMin(){
		if (root == NULL || root == nil)
			return nil;

		pointer temp = root;
		while (temp->left != nil)
			temp = temp->left;
		return temp;
	}

	pointer search_helper(pointer node, const value_type &key) const{
		if (node == nil)
			return node;
		else if(comp(key.first, node->val.first ))
			return search_helper(node->left, key);
		else if (comp(node->val.first, key.first))
			return search_helper(node->right, key);
		else
			return node;
	}


	pointer search(const value_type &key){
//		return search_helper(root, key);

		pointer tmp = root;
		while (tmp != nil){
			if (comp(key.first, tmp->val.first))
				tmp = tmp->left;
			else if(comp(tmp->val.first, key.first))
				tmp = tmp->right;
			else
				return tmp;
		}
		return NULL;
	}

	pointer craeteNode(const value_type &val){
		pointer newNode = alloc.allocate(1);
//		alloc.construct(newNode, val);
		alloc.construct(newNode, RBNode<T>(val, nil, nil, NULL, RED));
//		newNode->parent = NULL;
//		newNode->right = nil;
//		newNode->left = nil;
//		newNode->color = RED;

		return newNode;
	}

	void leftRotate(pointer x){
		pointer  y = x->right;
		x->right = y->left;
		if (y->left != nil)
			y->left->parent = x;
		y->parent = x->parent;
		if (x->parent == NULL)
			this->root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;

		y->left = x;
		x->parent = y;
	}

	void rightRotate(pointer x){
		pointer  y = x->left;
		x->left = y->right;
		if (y->right != nil)
			y->right->parent = x;
		y->parent = x->parent;
		if (x->parent == NULL)
			this->root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;

		y->right = x;
		x->parent = y;
	}

	void fixInsertion(pointer node){
		pointer uncle;
		while (node->parent->color == RED){
			if (node->parent == node->parent->parent->right) {
				uncle = node->parent->parent->left;
				if (uncle->color == RED) {
					uncle->color = BLACK;
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				} else {
					if (node == node->parent->left){
						node = node->parent;
						rightRotate(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					leftRotate(node->parent->parent);
				}
			} else{
				uncle = node->parent->parent->right;
				if (uncle->color == RED){
					uncle->color = BLACK;
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				}else{
					if (node == node->parent->right){
						node = node->parent;
						leftRotate(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					rightRotate(node->parent->parent);
				}
			}
			if (node == root)
				break;
		}
		root->color = BLACK;
	}



	bool insert( const value_type& value ) {
		pointer newNode = craeteNode(value);

		pointer y = NULL;
		pointer x = this->root;
		while (x != nil) {
			y = x;
			if (comp(newNode->val.first, x->val.first))
				x = x->left;
			else if (comp(x->val.first, newNode->val.first))
				x = x->right;
			else{
				alloc.destroy(newNode);
				alloc.deallocate(newNode, 1);
				return false;
			}
		}

		newNode->parent = y;

		if (y == NULL)
			root = newNode;
		else if (comp(newNode->val.first, y->val.first))
			y->left = newNode;
		else
			y->right = newNode;

		_size++;

		if (newNode->parent == NULL) {
			newNode->color = BLACK;
			return true;
		}

		if (newNode->parent->parent == NULL)
			return true;

		fixInsertion(newNode);
		return  true;
	}

	bool isEmpty() const{
		return (_size == 0);
	}

	bool size() const{
		return _size;
	}

	size_type max_size() const{
		return alloc.max_size();
	}

	void recursiveCleer(pointer root){
		if (root != nil){
			recursiveCleer(root->left);
			recursiveCleer(root->right);
			alloc.destroy(root);
			alloc.deallocate(root, 1);
		}
	}

	void clear(){
		if (root != nil)
			recursiveCleer(root);
		_size = 0;
		root = nil;
	}





};



#endif