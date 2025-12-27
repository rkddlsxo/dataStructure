#include <iostream>
#include <vector>
using namespace std;

struct node {
	node* parent;
	int data;
	vector<node*> childlist;
	int ddd;
	node(int a, node* b) {
		data = a;
		parent = b;

	}
};

class tree {
private:
	node* root;
	vector<node*> nodelist;
	int find(int data, vector<node*> list) {
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

	void insert(int par, int data) {
		if (find(data, nodelist) != -1) {
			return;
		}
		int idx = find(par, nodelist);
		if (idx == -1) {
			return;
		}
		node* parnode = nodelist[idx];
		node* newnode = new node(data, parnode);
		parnode->childlist.push_back(newnode);
		nodelist.push_back(newnode);
	}

	void setddd(int data, int dd) {
		int idx = find(data, nodelist);
		if (idx == -1) {
			return;
		}
		node* curnode = nodelist[idx];
		curnode->ddd = dd;
	}
	int dd(int data) {
		int idx = find(data, nodelist);
		if (idx == -1) {
			return 0;
		}
		node* nd = nodelist[idx];
		int dsum = nd->ddd;
		if (nd->childlist.size() == 0) {
			return nd->ddd;
		}
		else {
			for (int i = 0; i < nd->childlist.size(); i++) {
				dsum += dd(nd->childlist[i]->data);
			}
			return dsum;
		}
	}




};

int main() {
	int n;
	tree tt(1);
	int par, data;
	int value;
	int t;
	cin >> n >> t;
	for (int i = 1; i < n; i++) {
		cin >> par >> data;
		tt.insert(par, data);
	}
	for (int i = 0; i < n; i++) {
		cin >> data >> value;
		tt.setddd(data,value);
	}
	
	for (int i = 0; i < t; i++) {
		cin >> data;
		cout << tt.dd(data) << endl;
 	}
}