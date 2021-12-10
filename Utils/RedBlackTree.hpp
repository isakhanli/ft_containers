#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include <iostream>
#include "../Utils/utility.hpp"
#include "../Utils/RBTree_iterator.hpp"
#include "../Utils/reverse_iterator.hpp"
#include  <algorithm>
#include <iomanip>
#include <memory>
#include <iostream>

enum Color{
	BLACK,
	RED
};

template <class T>
class RBNode{
public:
	typedef T		value_type;
	RBNode 			*left;
	RBNode 			*right;
	RBNode 			*parent;
	value_type 		val;
	int 			color;


			/* * * * * * * * * * * * * * * * * * *
			* 		   Canonical Forn
			* * * * * * * * * * * * * * * * * * */


	RBNode(): left(NULL), right(NULL), parent(NULL), val(), color(BLACK){

	}

	RBNode(const value_type &data) : left(NULL), right(NULL), val(data), color(BLACK){

	}

	RBNode(const value_type &val, RBNode *left, RBNode *right, RBNode *parent, int color)
		: left(left), right(right), parent(parent), val(val), color(color){

	}

	~RBNode(){};

	RBNode(const RBNode &other)
		: left(other.left), right(other.right), parent(other.parent), val(other.val), color(other.color){
	}

	RBNode& operator=(const RBNode &other){
		if (this == &other)
			return *this;
		this->left = other->left;
		this->right = other->right;
		this->parent = other->parent;
		this->val = other->val;
		this->color = other->color;
	}
};


template <class ValueType, class Key, class Compare, class Allocator>
class RBTree{
public:
	typedef ValueType														value_type;
	typedef Key																key_type;
	typedef RBNode<value_type>												Node;
	typedef std::size_t														size_type;
	typedef Compare															key_compare;
	typedef typename Allocator::template rebind<RBNode<value_type> >::other	allocator_type;
	typedef typename allocator_type::pointer								pointer;
	typedef typename allocator_type::const_pointer							const_pointer;

	typedef ft::rb_tree_iterator<value_type, pointer>						iterator;
	typedef ft::rb_tree_iterator<const value_type, const_pointer>			const_iterator;
	typedef ft::reverse_iterator<iterator>									reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;

	pointer 			root;
	pointer 			nil;
	size_type			_size;
	allocator_type 		alloc;
	key_compare 		comp;


		/* * * * * * * * * * * * * * * * * * *
		* 		  Canonical Form
		* * * * * * * * * * * * * * * * * * */


	RBTree(key_compare const& cmp = key_compare()) : comp(cmp){
		_size = 0;
		nil = alloc.allocate(1);
		alloc.construct(nil, Node());
		root = nil;
	}

	~RBTree(){
	}

	RBTree (const RBTree &other){
		*this = other;
	}

	RBTree& operator=(const RBTree& other){
		if (this == &other)
			return *this;

		clear();
		deallocateNil();
		this->alloc = other.alloc;
		this->comp = other.comp;
		nil = alloc.allocate(1);
		alloc.construct(nil, Node());
		root = nil;
		deepCopy(other.root, other.nil);
		return *this;
	}

	void deepCopy(pointer rootPtr, pointer nilPtr){
		if (rootPtr != nilPtr){
			insert(rootPtr->val);
			deepCopy(rootPtr->right, nilPtr);
			deepCopy(rootPtr->left, nilPtr);
		}
	}


		/* * * * * * * * * * * * * * * * * * *
		* 		    Iterators
		* * * * * * * * * * * * * * * * * * */


		iterator		begin(){
			return       iterator(getMin(), root, nil);
		}

		const_iterator		begin() const{
			return       const_iterator(getMin(), root, nil);
		}

		iterator		end(){
			return       iterator(nil, root, nil);
		}

		const_iterator		end() const{
			return       const_iterator(nil, root, nil);
		}

		reverse_iterator		rbegin(){
			return       	reverse_iterator(end());
		}

		const_reverse_iterator		rbegin() const{
			return       	const_reverse_iterator(end());
		}

		reverse_iterator		rend(){
			return       	reverse_iterator(begin());
		}

		const_reverse_iterator		rend() const{
			return       	const_reverse_iterator(begin());
		}


		/* * * * * * * * * * * * * * * * * * *
		* 		   Other Methods
		* * * * * * * * * * * * * * * * * * */


		pointer find(const value_type &key) const{

		pointer tmp = root;
			while (tmp != nil){
				if (comp(key, tmp->val))
					tmp = tmp->left;
				else if(comp(tmp->val, key))
					tmp = tmp->right;
				else
					return tmp;
			}
			return nil;
		}

		size_type size() const{
			return _size;
		}

		size_type max_size() const{
			return alloc.max_size();
		}

		void clear(){
			if (root != nil)
				recursiveCleer(root);
			_size = 0;
			root = nil;
		}

		void swap(RBTree &other){
			std::swap(root, other.root);
			std::swap(nil, other.nil);
			std::swap(_size, other._size);
			std::swap(alloc, other.alloc);
			std::swap(comp, other.comp);
		}


		/* * * * * * * * * * * * * * * * * * *
		* 		   Lower/Upper Bounds
		* * * * * * * * * * * * * * * * * * */


		iterator lower_bound(const value_type& key){
			pointer temp = root;
			iterator result;

			iterator endit = end();
			endit--;

			while (temp != nil){
				if (!comp(temp->val, key)){
					result = iterator(temp, root, nil);
					temp = temp->left;
				}else
					temp = temp->right;
			}
			if (!comp(key, *endit))
				return iterator(nil, root, nil);

			return result;
		}

		const_iterator lower_bound(const value_type& key) const{
			pointer temp = root;
			const_iterator result;

			const_iterator endit = end();
			endit--;

			while (temp != nil){
				if (!comp(temp->val, key)){
					result = const_iterator(temp, root, nil);
					temp = temp->left;
				}else
					temp = temp->right;
			}
			if (!comp(key, *endit))
				return const_iterator(nil, root, nil);

			return result;
		}

		iterator upper_bound(const value_type& key){
			pointer temp = root;
			iterator result;

			iterator endit = end();
			endit--;

			while (temp != nil){
				if (comp(key, temp->val)){
					result = iterator(temp, root, nil);
					temp = temp->left;
				}else
					temp = temp->right;
			}
			if (!comp(key, *endit))
				return iterator(nil, root, nil);

			return result;
		}

		const_iterator upper_bound(const value_type& key) const{
			pointer temp = root;
			const_iterator result;

			const_iterator endit = end();
			endit--;

			while (temp != nil){
				if (comp(key, temp->val)){
					result = const_iterator(temp, root, nil);
					temp = temp->left;
				}else
					temp = temp->right;
			}
			if (!comp(key, *endit))
				return const_iterator(nil, root, nil);

			return result;
		}


		/* * * * * * * * * * * * * * * * * * *
		* 		   	Insert
		* * * * * * * * * * * * * * * * * * */


		bool insert( const value_type& value ) {
			pointer newNode = createNode(value);

			pointer y = NULL;
			pointer x = this->root;
			while (x != nil) {
				y = x;
				if (comp(newNode->val, x->val))
					x = x->left;
				else if (comp(x->val, newNode->val))
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
			else if (comp(newNode->val, y->val))
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


		/* * * * * * * * * * * * * * * * * * *
		* 		     Delete
		* * * * * * * * * * * * * * * * * * */


		bool erase(const value_type &key){
			pointer node = root;
			pointer x, y, z;
			z = nil;

			//find the node to be deleted
			while (node != nil){
				if (comp(node->val, key))
					node = node->right;
				else if (comp(key, node->val))
					node = node->left;
				else {
					z = node;
					break;
				}
			}

			//not a node with such key
			if (z == nil)
				return false;

			y = z;
			int originalColor = y->color;

			if (y->left == nil){
				x = z->right;
				rbReplace(z, z->right);
			}else if (z->right == nil){
				x = z->left;
				rbReplace(z, z->left);
			}else{
				y = getMin(z->right);
				originalColor = y->color;
				x = y->right;

				/*
					 z = 200
					 y = 300

					 CASE 1
								100
								/ \
							  50   200     	<- node to be deleted (200)
									/\
								 150   300
					 CASE 2

								100
								 / \
							   50   200     	<- node to be deleted (200)
									/\
								 150   300
										/\
									250	  350


					 */

				if (y->parent == z)  			// CASE 1
					x->parent = y;
				else{							// CASE 2
					rbReplace(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}

				rbReplace(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}

			alloc.destroy(z);
			alloc.deallocate(z, 1);

			if(originalColor == BLACK)
				fixDeletion(x);

			_size--;
			return true;
		}

	void fixDeletion(pointer node){
		pointer sibling;

		while (node != root && node->color == BLACK){
			if (node == node->parent->left){
				sibling = node->parent->right;
				if (sibling->color == RED){
					sibling->color = BLACK;
					node->parent->color = RED;
					leftRotate(node->parent);
					sibling = node->parent->right;
				}
				if (sibling->color == BLACK && sibling->right->color == BLACK){
					sibling->color = RED;
					node = node->parent;
				}else{
					if (sibling->right->color == BLACK){
						sibling->left->color = BLACK;
						sibling->color = RED;
						rightRotate(sibling);
						sibling = node->parent->right;
					}
					sibling->color = node->parent->color;
					node->parent->color = BLACK;
					sibling->right->color = BLACK;
					leftRotate(node->parent);
					node = root;
				}
			}else{
				sibling = node->parent->left;
				if (sibling->color == RED){
					sibling->color = BLACK;
					node->parent->color = RED;
					rightRotate(node->parent);
					sibling = node->parent->left;
				}

				if (sibling->left->color == BLACK && sibling->right->color == BLACK){
					sibling->color = BLACK;
					node = node->parent;
				}else{
					if (sibling->left->color == BLACK){
						sibling->right->color = BLACK;
						sibling->color = RED;
						leftRotate(sibling);
						sibling = node->parent->left;
					}

					sibling->color = node->parent->color;
					node->parent->color = BLACK;
					sibling->left->color = BLACK;
					rightRotate(node->parent);
					node = root;
				}

			}
		}
		node->color = BLACK;
	}


		/* * * * * * * * * * * * * * * * * * *
		* 	 		Helper Functions
		* * * * * * * * * * * * * * * * * * */


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

	// to replace node to be deleted with one of its children
	void rbReplace(pointer x, pointer y){

		/*
			Case 1
		 	x = 100
		 	y = 150
		 			100 			150
					/\       =>     /\
				  50  150         50  150

			Case 2
		 	x = 50
		 	y = 70

		           100                 100
		           /\                  /\
		         50  150     =>      70  150
		         /\                  /\
		       20  70              20  70


		    Case 3
		 	x = 150
		 	y = 170

		           100                 100
		           /\                  /\
		         50  150     =>      70  170
		              /\                  /\
		           120  170           120   170

		 */


		if (x->parent == NULL)				//Case1
			root = y;
		else if (x == x->parent->left)		//Case2
			x->parent->left = y;
		else								//Case3
			x->parent->right = y;

		y->parent = x->parent;
	}

	pointer getMin(pointer node){
		if (node == nil || node == NULL)
			return nil;

		while (node->left != nil)
			node = node->left;

		return node;
	}

	pointer getMin() const{
		if (root == NULL || root == nil)
			return nil;

		pointer temp = root;
		while (temp->left != nil)
			temp = temp->left;
		return temp;
	}

	void recursiveCleer(pointer root){
		if (root != nil){
			recursiveCleer(root->left);
			recursiveCleer(root->right);
			alloc.destroy(root);
			alloc.deallocate(root, 1);
		}
	}

	pointer createNode(const value_type &val){
		pointer newNode = alloc.allocate(1);
		alloc.construct(newNode, Node(val, nil, nil, NULL, RED));
		return newNode;
	}

	void deallocateNil(){
		alloc.destroy(nil);
		alloc.deallocate(nil, 1);
	}


	pointer getRoot() const{
		return root;
	}

	pointer getNil() const{
		return nil;
	}
};



#endif