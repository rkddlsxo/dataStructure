#include <iostream>
#include <vector>
using namespace std;

struct node {
	node* parent;
	int data;
	vector<node*> childlist;
	node(int a, node* b) {
		data = a;
		parent = b;
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

	tree(int x) {
		node* newnode = new node(x, NULL);
		root = newnode;
		nodelist.push_back(newnode);
	}

	void append(int pardata, int data) {
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

	void ch(int data) {
		int idx = find(data, nodelist);
		if (idx == -1) {
			return;
		}
		node* curnode = nodelist[idx];
		
		if (curnode->childlist.size() == 0) {
			int d = 0;
			while (curnode != root) {
				d++;
				curnode = curnode->parent;
			}
			cout << d << " ";
			return;
		}
		else {
			int min = curnode->childlist[0]->data;
			for (int i = 0; i < curnode->childlist.size(); i++) {
				if (min > curnode->childlist[i]->data) {
					min = curnode->childlist[i]->data;
				}
			}
			cout << min << " ";
			return;
		}
	}


	void post(node* a) {
		for (int i = 0; i < a->childlist.size(); i++) {
			post(a->childlist[i]);
		}
		ch(a->data);
	}
	node* getroot() {
		return root;
	}
};


int main() {
	int t;
	cin >> t;
	int value, parvalue, num;
	while (t--) {
		cin >> num;
		tree asdf(1);
		for (int i = 1; i < num; i++) {
			cin >> parvalue >> value;
			asdf.append(parvalue, value);
		}
		asdf.post(asdf.getroot());
		cout << endl;
	}
}
