#include <iostream>
#include <vector>
using namespace std;

struct node {
	int data;
	char ll;
	node* parent;
	vector<node*> childlist;
	node(int data, node* parent) {
		this->data = data;
		this->parent = parent;
	}
};

class tree {
private:
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
		node* newnode = new node(1, NULL);
		root = newnode;
		nodelist.push_back(root);
	}

	void insert(int pardata, int data) {
		if (find(data, nodelist) != -1) {
			return;
		}
		int idx = find(pardata, nodelist);
		if (idx == -1) {
			return;
		}
		node* parnode = nodelist[idx];
		node* newnode = new node(data, parnode);
		parnode->childlist.push_back(newnode);
		nodelist.push_back(newnode);
	}

	void sum(int data) {
		int idx = find(data, nodelist);
		if (idx == -1) {
			return;
		}
		char asdf;
		node* curnode = nodelist[idx];
		if (curnode->childlist.size() == 0) {
			asdf = 'D';
		}
		else {
			asdf = 'F';
		}

		int sum = 0;
		if (curnode == root) {
			cout << "F 0" << endl;
			return;
		}
		while (curnode != root) {
			curnode = curnode->parent;
			sum += curnode->data;
		}
		cout << asdf << " " << sum << endl;
	}
};


int main() {
	int t;
	int value;
	int parvalue;
	int num;
	tree t1(1);
	cin >> num >> t;
	for (int i = 1; i < num; i++) {
		cin >> parvalue >> value;
		t1.insert(parvalue, value);
	}

	for (int k = 0; k < t; k++) {
		cin >> value;
		t1.sum(value);
	}
}