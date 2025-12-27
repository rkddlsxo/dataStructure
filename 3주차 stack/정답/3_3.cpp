#include <iostream>
#include <string>
using namespace std;

struct node {
	int data;
	node* link;
};

class liststack {
private:
	node* topnode;
	int stacksize;

public:
	liststack() {
		topnode = NULL;
		stacksize = 0;
	}

	void size() {
		cout << stacksize << endl;	
	}

	bool empty() {
		if (stacksize == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void top() {
		if (empty()) {
			cout << -1 << endl;
		}
		else {
			cout << topnode->data << endl;
		}
	}

	void push(int value) {

		node* newNode = new node();
		newNode->data = value;
		newNode->link = topnode;
		topnode = newNode;
		stacksize++;

		
	}
	
	void pop(int num) {

		if (empty()) {
			cout << -1;
		}

		else if (num > stacksize) {
			while (!empty()) {
				node* curnode = new node();
				curnode = topnode;
				topnode = topnode->link;
				cout << curnode->data << " ";
				delete curnode;
				stacksize--;
			}
		}

		else {
			for (int i = 0; i < num; i++) {
				node* curnode = new node();
				curnode = topnode;
				topnode = topnode->link;
				cout << curnode->data << " ";
				delete curnode;
				stacksize--;
			}
		}
		cout << endl;
	}
};

int main() {
	int t;
	int value;
	string str;
	cin >> t;
	liststack stack;
	for (int k = 0; k < t; k++) {
		
		cin >> str;
		if (str == "size") {
			stack.size();
		}

		else if(str == "empty") {
			if (stack.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}

		else if (str == "top") {
			stack.top();
		}

		else if (str == "push") {
			cin >> value;
			stack.push(value);
		}

		else if (str == "pop") {
			cin >> value;
			stack.pop(value);
		}
	}
}