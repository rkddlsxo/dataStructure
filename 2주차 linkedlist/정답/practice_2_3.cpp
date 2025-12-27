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

	void print() {
		if (n == 0) {
			cout << "empty" << endl;
			return;
		}
		node* curnode = head;
		while (curnode != NULL) {
			cout << curnode->data << " ";
			curnode = curnode->next;
		}
		
		cout << endl;
		
	}

	void Append(int x) {
		node* newnode = new node;
		newnode->data = x;
		newnode->next = NULL;
		if (n == 0) {
			head = tail = newnode;
			n++;
		}
		else {
			tail->next = newnode;
			tail = newnode;
			n++;
		}
		print();
	}

	void deletenode(int idx) {
		
		if (idx >= n || n == 0) {
			cout << -1 << endl;
			return;
		}
		if (idx == 0) {
			node* curnode = head;
			head = head->next;
			cout << curnode->data << endl;
			delete curnode;
			n--;
			return;
		}
		node* curnode = head;
		node* prevnode = curnode;
		for (int i = 0; i < idx; i++) {
			prevnode = curnode;
			curnode = curnode->next;
		}
		prevnode->next = curnode->next;
		if (curnode == tail) {
			tail = prevnode;
		}
		int temp = curnode->data;
		delete curnode;
		n--;
		cout << temp << endl;
	}

	void Aftermin(int a) {
		if (n == 0 || a >= n) {
			cout << "error" << endl;
			return;
		}
		node* curnode = head;
		for (int i = 0; i < a; i++) {
			curnode = curnode->next;
		}
		int min = curnode->data;
		while (curnode != NULL) {
			if (min > curnode->data) {
				min = curnode->data;
			}
			curnode = curnode->next;
		}

		cout << min << endl;
	}

	void sum() {
		if (n == 0) {
			cout << 0 << endl;
			return;
		}
		int sum = 0;
		node* curnode = head;
		while (curnode != NULL) {
			sum += curnode->data;
			curnode = curnode->next;

		}
		cout << sum << endl;
		
	}
};


int main() {
	int t;
	int value;
	string str;
	sll asdf;
	cin >> t;
	while (t--) {
		cin >> str;
		if (str == "Print") {
			asdf.print();
		}
		else if (str == "Append") {
			cin >> value;
			asdf.Append(value);
		}
		else if (str == "Delete") {
			cin >> value;
			asdf.deletenode(value);
		}
		else if (str == "AfterMin") {
			cin >> value;
			asdf.Aftermin(value);
		}
		else if (str == "Sum") {
			asdf.sum();
		}
	}
}