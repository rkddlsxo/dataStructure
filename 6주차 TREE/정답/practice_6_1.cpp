#include <iostream>
#include <vector>
using namespace std;

struct node {
	int data;
	node* parent;
	vector<node*> childlist;
	node(int data, node* parent) {
		this->data = data;
		this->parent = parent;
	}
};

class Tree {
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
	Tree(int data) {
		node* newnode = new node(data, NULL); 
		root = newnode;
		nodelist.push_back(root);
		
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
		nodelist.push_back(newnode);
		parnode->childlist.push_back(newnode);
		
	}

	void deletenode(int x) {
		int idx = find(x, nodelist);
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
		
		parnode->childlist.erase(parnode->childlist.begin() + find(x, parnode->childlist));
		nodelist.erase(nodelist.begin() + idx);
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
			if(curnode->childlist[i]->data > max){
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
			cout << max + min << endl;
		}
	}
};

int main() {
	int t;
	Tree tree(1);
	string str;
	int parvalue;
	int value;
	cin >> t; 
	while (t--) {
		cin >> str;
		if (str == "insert") {
			cin >> parvalue >> value;
			tree.insert(parvalue, value);
		}
		else if (str == "delete") {
			cin >> value;
			tree.deletenode(value);
		}
		else if (str == "parent") {
			cin >> value;
			tree.parent(value);
		}
		else if (str == "child") {
			cin >> value;
			tree.child(value);
		}
		else if (str == "min_maxChild") {
			cin >> value;
			tree.min_maxChild(value);
		}
	}
}

