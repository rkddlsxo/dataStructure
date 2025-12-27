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
	int count;
	int aa;
public:
	BST() {
		root = NULL;
		count = 0;
		aa = 0;
	}
	void reset() {
		count = 0;
		aa = 0;
	}
	void callC() {
		if (aa == 1) {
			cout << "empty" << endl;
			return;
		}
		
		cout << count << endl;
	}

	node* search_a(node* curnode, int key) {
		if (root == NULL) {
			aa = 1;
			return NULL;
		}
		if (curnode == NULL) {
			return NULL;
		}
		count++;
		if (curnode->key == key) {
			aa = 2;
			return curnode;
		}
		else if (curnode->key < key) {
			
			return search(curnode->right, key);
		}
		else {
			
			return search(curnode->left, key);
		}
	}

	node* search(node* curnode, int key) {
		if (root == NULL) {
			
			return NULL;
		}
		if (curnode == NULL) {
			return NULL;
		}
		if (curnode->key == key) {
			count++;
			return curnode;
		}
		else if (curnode->key < key) {
			count++;
			return search(curnode->right, key);
		}
		else {
			count++;
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
		int dep = 0;
		while (depnode != root) {
			dep++;
			depnode = depnode->parent;
		}
		cout << dep << endl;
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
	node* getroot() {
		return root;
	}

	void parent(int num) {
		node* curnode = search(root, num);
		if (curnode == NULL) {
			cout << -1 << endl;
			return;
		}
		else if (curnode == root) {
			cout << -2 << endl;
			return;
		}
		else {
			cout << curnode->parent->key << endl;
		}
	}

	void child(int num) {
		node* curnode = search(root, num);
		if (curnode == NULL) {
			cout << -1 << endl;
			return;
		}
		else if (curnode->left == NULL) {
			cout << -2 << endl;
			return;
		}
		else {
			cout << curnode->left->key << endl;
		}
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
				b.callC();
				b.reset();
			}
			else if (str == "search") {
				cin >> value;
				b.search_a(b.getroot(),value);
				b.callC();
				b.reset();
			}
			else if (str == "child") {
				cin >> value;
				b.child(value);
				b.reset();
			}
			else if (str == "parent") {
				cin >> value;
				b.parent(value);
				b.reset();
			}

		}
	}
}