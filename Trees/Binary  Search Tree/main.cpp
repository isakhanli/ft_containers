#include <iostream>
#include <queue>
#include "binarytree.hpp"
#include <map>

//typedef struct node{
//	int key;
//	struct node *left;
//	struct node *right;
//}				Node;

TreeNode* createNode(int key){
	TreeNode *newNode = new TreeNode;
	newNode->val = key;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

bool search(TreeNode *root, int val){
	if (root == NULL) return false;
	else if (root->val == val) return true;
	else if (val <= root->val) return search(root->left, val);
	else return search(root->right, val);
}


TreeNode *insert(TreeNode* root, int key){
	if (root == NULL)
		return createNode(key);
	if (key < root->val)
		root->left = insert(root->left, key);
	else if (key > root->val)
		root->right = insert(root->right, key);

	return root;

}

TreeNode* findMin(TreeNode* root){
	while (root->left != NULL)
		root = root->left;
	return root;
}

TreeNode *Delete(TreeNode* root, int key){
	if (root == NULL)
		return root;
	else if (root->val > key)
		root->left = Delete(root->left, key);
	else if (root->val < key)
		root->right = Delete(root->right, key);
	else{
		if (root->right == NULL && root->left == NULL){
			delete root;
			root = NULL;
		}
		else if (root->left == NULL){
			TreeNode *temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right == NULL){
			TreeNode *temp = root;
			root = root->left;
			delete temp;
		}
		else{
			TreeNode *temp = findMin(root->right);
			root->val = temp->val;
			root->right = Delete(root->right, temp->val);
		}
	}

	return root;
}


int main(){

//	TreeNode *root = createNode(30);
	TreeNode *root = NULL;
	root = insert(root, 20);
	root = insert(root, 10);
	root = insert(root, 50);
	root = insert(root, 60);
	root = insert(root, 15);
	root = insert(root, 5);
	root = insert(root, 3);
	root = insert(root, 1);
	root = insert(root, 4);
	root = insert(root, 40);
	root = insert(root, 8);
	root = insert(root, 6);
	root = insert(root, 49);
	root = insert(root, 9);
	root = insert(root, 13);
	root = insert(root, 7);

//	 Delete(root, 15);
//	 Delete(root, 40);
//	 Delete(root, 7);
//	 Delete(root, 5);

	showTree(root);

	std::map<int, int> a;


}
