#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
	node* prev;

};

class link {
private:
	node* header;
	node* trailer;
	int n;

public:
	link() {
		header = new node;
		trailer = new node;
		header->next = trailer;
		trailer->prev = header;
		header->prev = trailer->next = NULL;
		n = 0;
	}


	bool empty() {
		if (n == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	node* begin() {
		return header->next;
	}

	node* end() {
		return trailer;
	}
	void insert(int idx, int e) {
		if (idx<0 || idx>n) {
			cout << "out_of_range" << endl;
			return;
		}

		node* newnode = new node;
		newnode->data = e;
		node* curnode = begin();

		for (int i = 0; i < idx; i++) {
			curnode = curnode->next;
		}
		newnode->prev = curnode->prev;
		newnode->next = curnode;
		curnode->prev->next = newnode;
		curnode->prev = newnode;
		n++;
	}
	/*void insert(node* p, int e) {
		node* newnode = new node;
		newnode->data = e;
		newnode->prev = p->prev;
		newnode->next = p;
		p->prev->next = newnode;
		p->prev = newnode;
		n++;
	}*/

	/*node* erase(node* p) {
		if (n == 0) {
			cout << "Empty" << endl;
			return p;
		}
		if (p == end()) {
			return p;
		}
		else {
			p->next->prev = p->prev;
			p->prev->next = p->next;
			delete p;
			n--;
			return begin();
		}
	}*/

	void erase(int idx) {
		if (idx < 0) {
			cout << "out_of_range" << endl;
			return;
		}
		if (idx >= n) {
			cout << "out_of_range" << endl;
			return;
		}
		node* curnode = begin();
		for (int i = 0; i < idx; i++) {
			curnode = curnode->next;
		}
		curnode->next->prev = curnode->prev;
		curnode->prev->next = curnode->next;
		delete curnode;
		n--;

	}
	node* nextP(node* p) {
		if (p == end()) {
			return p;
		}
		return p->next;
	}
	node* prevP(node* p) {
		if (p == begin()) {
			return p;
		}
		return p->prev;
	}

	void print(int k) {
		if (k == 0) {
			if (n == 0) {
				cout << "Empty" << endl;
				return;
			}
			node* curnode = begin();
			for (int i = 0; i < n; i++) {
				cout << curnode->data << " ";
				curnode = curnode->next;
			}
			cout << endl;
		}
		else if (k == 1) {
			if (n == 0) {
				cout << "Empty" << endl;
				return;
			}
			node* curnode = end()->prev;
			for (int i = 0; i < n; i++) {
				cout << curnode->data << " ";
				curnode = curnode->prev;
			}
			cout << endl;
		}
	}
	void size() {
		cout << n << endl;
	}
	void upper(int e) {
		int s = 0;
		node* curnode = begin();
		for (int i = 0; i < n; i++) {
			if (curnode->data > e) {
				cout << i << " ";
				s++;
			}
			curnode = curnode->next;
		}
		if (s == 0) {
			cout << -1 << endl;
			return;
		}
		cout << endl;
	}





	void find(int e) {
		int s = 0;
		node* curnode = trailer->prev;
		for (int i = 0; i < n; i++) {
			if (curnode->data == e) {
				cout << i << " ";
				s++;
				break;
			}
			curnode = curnode->prev;
		}
		if (s == 0) {
			cout << "not_found" << endl;
			return;
		}
		cout << endl;
	}
};


int main() {
	int t;
	int value;
	int idx;
	string str;
	link list;
	node* p = list.begin();

	cin >> t;
	while (t--) {

		cin >> str;
		if (str == "begin") {
			p = list.begin();
		}
		else if (str == "end") {
			p = list.end();
		}
		else if (str == "insert") {
			cin >> idx;
			cin >> value;
			list.insert(idx, value);
		}

		else if (str == "erase") {
			cin >> idx;
			list.erase(idx);
		}
		else if (str == "empty") {
			if (list.empty()) {
				cout << "true" << endl;
			}
			else {
				cout << "false" << endl;
			}
		}

		else if (str == "nextP") {
			p = list.nextP(p);
		}
		else if (str == "prevP") {
			p = list.prevP(p);
		}
		else if (str == "print") {
			cin >> value;
			list.print(value);
		}
		else if (str == "upper") {
			cin >> value;
			list.upper(value);
		}
		else if (str == "find") {
			cin >> value;
			list.find(value);
		}
		else if (str == "size") {
			list.size();
		}


	}
}