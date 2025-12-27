#include <iostream>
#include <vector>
using namespace std;

struct node {
	node* parent;
	vector<node*> childlist;
	int data;
	node(int data, node* parent) {
		this->data = data;
		this->parent = parent;
	}
};

class tree {
private:
	int n;
	node* root;
	vector<node*> nodelist;
	int find(int data, vector<node*>& list) {
		for (int i = 0; i < list.size(); i++) {
			if (data == list[i]->data) {
				return i;
			}
		}
		return -1;
	}

public:
	tree(int data) {
		root = new node(data, NULL);
		nodelist.push_back(root);
		n = 0;
	}

	void insert(int pardata, int data) {
		if (find(data, nodelist) != -1) {
			cout << -1 << endl;
			return;
		}
		int idx = find(pardata, nodelist);
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		node* parnode = nodelist[idx];
		node* newnode = new node(data, parnode);
		parnode->childlist.push_back(newnode);
		nodelist.push_back(newnode);
		n++;
	}

	void deletenode(int data) {
		int idx = find(data, nodelist);
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		node* delnode = nodelist[idx];
		node* parnode = delnode->parent;

		for (int i = 0; i < delnode->childlist.size(); i++) {
			parnode->childlist.push_back(delnode->childlist[i]);
			delnode->childlist[i]->parent = parnode;
		}
		parnode->childlist.erase(parnode->childlist.begin() + find(data, parnode->childlist));
		nodelist.erase(nodelist.begin() + idx);
		n--;
	}

	void parent(int x) {
		int idx = find(x, nodelist);
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		node* curnode = nodelist[idx];
		cout << curnode->parent->data << endl;
	}

	void child(int x) {
		int idx = find(x, nodelist);
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}

		node* curnode = nodelist[idx];
		if (curnode->childlist.size() == 0) {
			cout << -1 << endl;
			return;
		}
		for (int i = 0; i < curnode->childlist.size(); i++) {
			cout << curnode->childlist[i]->data << " ";
		}
		cout << endl;
	}

	void min_maxChild(int x) {
		int idx = find(x, nodelist);
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		node* curnode = nodelist[idx];
		if (curnode->childlist.size() == 0) {
			cout << -1 << endl;
			return;
		}
		int max = curnode->childlist[0]->data;
		int min = curnode->childlist[0]->data;
		for (int i = 0; i < curnode->childlist.size(); i++) {
			if (curnode->childlist[i]->data > max) {
				max = curnode->childlist[i]->data;
			}
			if (curnode->childlist[i]->data < min) {
				min = curnode->childlist[i]->data;
			}
		}

		if (max == min) {
			cout << max << endl;
			return;
		}
		else {
			cout << max - min << endl;
			return;
		}
	}
};


int main() {
	int t;
	int parvalue;
	int value;
	tree te(1);
	string str;
	cin >> t;
	while (t--) {
		cin >> str;
		if (str == "insert") {
			cin >> parvalue >> value;
			te.insert(parvalue, value);
		}
		else if (str == "parent") {
			cin >> value;
			te.parent(value);
		}
		else if (str == "child") {
			cin >> value;
			te.child(value);
		}
		else if (str == "min_maxChild") {
			cin >> value;
			te.min_maxChild(value);
		}
		else if (str == "delete") {
			cin >> value;
			te.deletenode(value);
		}
	}
}