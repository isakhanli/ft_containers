#include <iostream>
#include <queue>

struct Node{
	int key;
	Node *left;
	Node *right;
};

Node* createNode(int key){
	Node *newNode = new Node();
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node *search(Node *root, int key){
	if (root == NULL || root->key == key)
		return root;

	std::queue<Node*> q;
	Node *node = NULL;
	q.push(root);
	while (!q.empty()){
		Node *temp = q.front();
		q.pop();

		if (temp->key == key){
			node = temp;
			std::cout << "hit" << std::endl;
		}
		if (temp->left != NULL)
			q.push(temp->left);
		if (temp->right != NULL)
			q.push(temp->right);
	}

	return node;

}

void insert(Node** root, int key){
	std::queue<Node*> q;
	q.push(*root);

	while (!q.empty()){
		Node *temp = q.front();
		q.pop();

		if (temp->left == NULL) {
			temp->left = createNode(key);
			return;
		}
		else
			q.push(temp->left);

		if (temp->right == NULL) {
			temp->right = createNode(key);
			return;
		}
		else
			q.push(temp->right);

	}
}

int main(){
	Node *root = createNode(1);
//	std::cout << root->key << std::endl;

	root->left = createNode(2);
	root->left->left = createNode(4);
	root->right = createNode(3);
	root->right->left = createNode(5);

	//		   1
	//       /   \
	//		2     3
	//	   /       \
	//    4         5

//	Node *nd = search(root, 1);
//	std::cout << nd->key << std::endl;

	insert(&root, 20);
	std::cout << root->left->right->key << std::endl;



}
