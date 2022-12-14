#include<cstdlib>
#include<iostream>

using namespace std;

class Node {
	friend class BS_tree;  // for tree encapsulation
private:
	int key;
	Node* left, * right;
public:
	Node() :left(NULL), right(NULL), key(0) {  }; // constructor
	Node(int a) :left(NULL), right(NULL), key(a) { }; // constructor
};

class BS_tree {
private:
	Node* root;
public:
	BS_tree() :root(NULL) {}; // constructor
	void inOrder() { inOrder(root); }
	void inOrder(Node* root);
	void preOrder() { preOrder(root); }
	void preOrder(Node* root);
	void postOrder() { postOrder(root); }
	void postOrder(Node* root);
	void insert(int key) { root = insert(root, key); }
	Node* insert(Node* root, int key);

};

void print(int data){
	cout << data << ' ';
}

//根據B.S.T特性，經過中序排序後必定為從小排到大

void BS_tree::inOrder(Node* node_p) {
	if(node_p != NULL){
		inOrder(node_p->left);
		// print(node_p->key);
		cout << node_p->key << ' ';
		inOrder(node_p->right);
	}
}


void BS_tree::preOrder(Node* node_p) {
	if(node_p != NULL){
		// print(node_p->key);
		cout << node_p->key << ' ';
		preOrder(node_p->left);
		preOrder(node_p->right);
	}
}

void BS_tree::postOrder(Node* node_p) {
	if(node_p != NULL){
		postOrder(node_p->left);
		postOrder(node_p->right);
		// print(node_p->key);
		cout << node_p->key << ' ';
	}
}

Node* BS_tree::insert(Node* node, int key) {
	if(node == 0){
		return new Node(key);
	}
	if(key < node->key){
		node->left = insert(node->left, key);
	}
	if(key > node->key){
		node->right = insert(node->right, key);
	}
	return node;
}

int main(void) {
	BS_tree tree;
	int val;
	
	int nums[9] = {12,7,24,11,15,3,37,22,14};
	for (int i = 0; i < 9; i++) {
		tree.insert(nums[i]);
	}

	cout << "InOrder:\t";
	tree.inOrder();  // inorder encapsulation
	cout << "\nPreOrder:\t";
	tree.preOrder();  // inorder encapsulation
	cout << "\nPostOrder:\t";
	tree.postOrder();  // inorder encapsulation
	return 0;
}
