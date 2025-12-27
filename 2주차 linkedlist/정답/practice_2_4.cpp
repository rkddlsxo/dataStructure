#include <iostream>
using namespace std;

struct node {
	node* next;
	int data;

};

class sll {
private:
	int n;
	node* head;
	node* tail;
public:
	sll() {
		head = tail = NULL;
		n = 0;
	}

	void append(int x) {
		node* newnode = new node;
		newnode->data = x;
		newnode->next = NULL;
		if (n == 0) {
			head = tail = newnode;
		}
		else {
			tail->next = newnode;
			tail = newnode;
		}
		n++;
	}
	void print() {
		node* curnode = head;
		while (curnode != NULL) {
			cout << curnode->data << " ";
			curnode = curnode->next;
		}
		cout << endl;
	}
	void del(int data) {
		node* curnode = head;
		node* prenode = curnode;
		while(curnode->data != data) {
			prenode = curnode;
			curnode = curnode->next;
		}

		if (curnode == head) {
			head = head->next;
			delete curnode;
			n--;
		}
		else {
			prenode->next = curnode->next;
			delete curnode;
			n--;
		}
	}

	void idx(int data) {
		node* curnode = head;
		int i = 0;
		while (curnode->data != data) {
			i++;
			curnode = curnode->next;
		}
		cout << i << endl;
	}

	void merge(sll n2) {
		tail->next = n2.head;
		tail = n2.tail;
		n += n2.n;
	}

};


int main() {
	int t;
	int n1;
	int value;
	int n2;
	int deldata;
	int k;
	cin >> t;
	while (t--) {
		sll m1;
		sll m2;
		cin >> n1;
		for (int i = 0; i < n1; i++) {
			cin >> value;
			m1.append(value);
		}
		cin >> n1;
		for (int i = 0; i < n1; i++) {
			cin >> value;
			m2.append(value);
		}
		m1.merge(m2);
		m1.print();
		cin >> deldata;
		m1.del(deldata);
		m1.print();
		cin >> k;
		m1.idx(k);
	}
}