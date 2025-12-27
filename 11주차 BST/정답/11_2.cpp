#include <iostream>
using namespace std;

struct node {
	int key;
	node* parent;
	node* left;
	node* right;
	node(int key) {
		this->key = key;
		parent = left = right = NULL;
	}
	
};


class BST {
private:
	node* root;
	int asdf;
	int value;
public:
	BST() {
		root = NULL;
		asdf = 0;
		value = -1;
	}

	node* search(node* curnode, int key) {
		if (curnode == NULL) {
			return NULL;
		}
		if (curnode->key == key) {
			return curnode;
		}
		else if (curnode->key < key) {
			return search(curnode->right, key);
		}
		else {
			return search(curnode->left, key);
		}
	}

	void insert(int key) {
		if (search(root, key) != NULL) {
			return;
		}
		node* newnode = new node(key);
		if (root == NULL) {
			root = newnode;
			return;

		}
		node* curnode = root;
		node* parnode = NULL;

		while (curnode != NULL) {
			parnode = curnode;
			if (curnode->key < key) {
				curnode = curnode->right;
			}
			else {
				curnode = curnode->left;
			}
		}

		newnode->parent = parnode;
		if (parnode->key < key) {
			parnode->right = newnode;
		}
		else {
			parnode->left = newnode;
		}

		node* depnode = newnode;

	}

	void remove(int key) {
		node* delnode = search(root, key);
		node* depnode = delnode;
		if (delnode == NULL) {
			return;
		}
		node* parnode = delnode->parent;
		node* childnode;

		if (delnode->left == NULL && delnode->right == NULL) {
			childnode = NULL;
		}
		else if (delnode->left == NULL && delnode->right != NULL) {
			childnode = delnode->right;
		}
		else if (delnode->left != NULL && delnode->right == NULL) {
			childnode = delnode->left;
		}
		else {
			childnode = delnode->right;
			while (childnode->left != NULL) {
				childnode = childnode->left;
			}
			delnode->key = childnode->key;
			delnode = childnode;
			parnode = delnode->parent;
			childnode = delnode->right;
		}

		if (parnode == NULL) {
			root = childnode;
			if (root != NULL) {
				root->parent = NULL;
			}
		}
		else if (delnode == parnode->left) {
			parnode->left = childnode;
			if (childnode != NULL) {
				childnode->parent = parnode;
			}
		}
		else {
			parnode->right = childnode;
			if (childnode != NULL) {
				childnode->parent = parnode;
			}
		}
		delete delnode;
	}
	void inorder(node* curnode,int num) {
		if (curnode == NULL) {
			return;
		}
		inorder(curnode->right, num);
		asdf++;
		if (asdf == num && value == -1) {
			cout << curnode->key << endl;
			value = 0;
		}
		inorder(curnode->left, num);
		
	}
	void reset() {
		asdf = 0;
		value = -1;
	}
	int height(node* curnode) {
		if (curnode == NULL) {
			return -1;
		}
		return max(height(curnode->left), height(curnode->right)) + 1;
	}

	node* getroot() {
		return root;
	}
};


int main() {
	int t;
	string str;
	int value;
	int num;
	cin >> t;
	
	while (t--) {
		cin >> num;
		BST b;
		while (num--) {
			cin >> str;
			if (str == "insert") {
				cin >> value;
				b.insert(value);
			}
			else if (str == "delete") {
				cin >> value;
				b.remove(value);
			}
			else if (str == "max") {
				cin >> value;
				b.inorder(b.getroot(), value);
				b.reset();
			}
			
		}
	}   
}