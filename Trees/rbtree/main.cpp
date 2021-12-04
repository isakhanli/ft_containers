#include "binarytree.hpp"

#include <iostream>

enum color{
	BLACK,
	RED
};


class rbtree{
public:
	nodePtr *root;
	nodePtr *TNULL;

	rbtree(){
		TNULL = new nodePtr;
		TNULL->color = 0;
		TNULL->left = NULL;
		TNULL->right = NULL;
		root = TNULL;
	}


	void initializeNULLNode(nodePtr *node, nodePtr *parent) {
		node->val = 0;
		node->parent = parent;
		node->left = NULL;
		node->right = NULL;
		node->color = BLACK;
	}

	void leftRotate(nodePtr *x){
		nodePtr *y = x->right;
		x->right = y->left;

		if (y->left != TNULL)
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

	void rightRotate(nodePtr *x){
		nodePtr *y = x->left;
		x->left = y->right;

		if (y->right != TNULL)
			y->right->parent = x;

		y->parent = x->parent;

		if (x->parent == NULL)
			this->root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;

		x->parent = y;
		y->right = x;
	}

	void insertFix(nodePtr *node){
		nodePtr *uncleNode;
		while (node->parent->color == RED){
			if (node->parent == node->parent->parent->right){
				uncleNode = node->parent->parent->left;
				if (uncleNode->color == RED){
					uncleNode->color = BLACK;
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					node = node->parent->parent;
				}else{
					if (node == node->parent->left){
						node = node->parent;
						rightRotate(node);
					}
					node->parent->color = BLACK;
					node->parent->parent->color = RED;
					leftRotate(node->parent->parent);
				}
			}else{
				uncleNode = node->parent->parent->right;
				if (uncleNode->color == RED){
					uncleNode->color = BLACK;
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

	void insert(int key) {
		nodePtr *node = new nodePtr ;
		node->parent = NULL;
		node->val = key;
		node->left = TNULL;
		node->right = TNULL;
		node->color = RED;

		nodePtr *y = NULL;
		nodePtr *x = this->root;

		while (x != TNULL) {
			y = x;
			if (node->val < x->val) {
				x = x->left;
			} else {
				x = x->right;
			}
		}

		node->parent = y;
		if (y == NULL) {
			root = node;
		} else if (node->val < y->val) {
			y->left = node;
		} else {
			y->right = node;
		}

		if (node->parent == NULL) {
			node->color = BLACK;
			return;
		}

		if (node->parent->parent == NULL) {
			return;
		}

		insertFix(node);
	}


};



int main(){
	rbtree tr;
	tr.insert(21);
	tr.insert(15);
	tr.insert(31);
	tr.insert(40);
	tr.insert(50);
	tr.insert(16);
	tr.insert(17);
	std::cout << tr.root->val << std::endl;
	std::cout << tr.root->right->val << std::endl;
	std::cout << tr.root->left->val << std::endl;

	showTree(tr.root);
}