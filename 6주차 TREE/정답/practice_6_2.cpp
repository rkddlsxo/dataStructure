#include <iostream>
#include <vector>
using namespace std;

struct node {
	node* parent;
	int data;
	vector<node*> childlist;
	node(int data, node* a) {
		this->data = data;
		parent = a;
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
	tree(int d) {
		root = new node(d, NULL);
		nodelist.push_back(root);
		
	}

	void append(int par, int data) {
		if(find(data, nodelist) != -1){
			cout << -1 << endl;
			return;
		}
		int idx = find(par, nodelist);
		if (idx == -1) {
			cout << -1 << endl;
			return;
		}
		node* parnode = nodelist[idx];
		node* newnode = new node(data, parnode);
		parnode->childlist.push_back(newnode);
		nodelist.push_back(newnode);
	}

	void depth(int data1, int data2) {
		if (find(data1, nodelist) == -1|| find(data2, nodelist) == -1) {
			cout << "error" << endl;
			return;
		}

		int dep1 = 0;
		int dep2 = 0;
		int i1 = find(data1, nodelist);
		int i2 = find(data2, nodelist);

		node* c1 = nodelist[i1];
		node* c2 = nodelist[i2];
		while (c1 != root) {
			dep1++;
			c1 = c1->parent;
		}
		while (c2 != root) {
			dep2++;
			c2 = c2->parent;
		}

		if (dep1 > dep2) {
			cout << dep1 << " " << dep2 << " " << dep1 - dep2 << endl;
		}
		else {
			cout << dep1 << " " << dep2 << " " << dep2 - dep1 << endl;
		}


	}
};

int main() {
	int t;
	int n;
	int x, y;
	tree aaa(1);
	cin >> t >> n;
	for (int i = 0; i < t; i++) {
		cin >> x >> y;
		aaa.append(x, y);
	}
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		aaa.depth(x, y);
	}

}