#include <iostream>
using namespace std;

struct node {
	node* next;
	int data;
};

class link {
private:
	int n;
	node* head;
	node* tail;

public:
	link() {
		head = NULL;
		tail = NULL;
		n = 0;
	}

	void append(int data) {
		node* newnode = new node;
		newnode->data = data;
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
	}

	void mer(link aa) {
		node* curnode = tail;
		curnode->next = aa.head;
		tail = aa.tail;
		n += aa.n;
	}

	void insert(int p, int data) {
		node* newnode = new node;
		newnode->data = data;
		newnode->next = NULL;
		node* curnode = head;
		node* prenode = head;
		int i = 0;
		while (curnode->data != p) {
			prenode = curnode;
			curnode = curnode->next;
			i++;
			if (i == n) {
				break;
			}
		}
		if (i == 0) {
			newnode->next = head;
			head = newnode;
			n++;
			return;
		}
		prenode->next = newnode;
		newnode->next = curnode;
		n++;
	}

	void print() {
		node* curnode = head;

		while (curnode != NULL) {
			cout << curnode->data << " ";
			curnode = curnode->next;
		}
		cout << "\n";
	}
};



int main() {
	int t;
	cin >> t;
	while (t--) {
		link a;
		link b;
		int num1; 
		int num2;
		int value;
		cin >> num1;
		for (int i = 0; i < num1; i++) {
			cin >> value;
			a.append(value);
		}
		cin >> num2;
		for (int i = 0; i < num2; i++) {
			cin >> value;
			b.append(value);
		}
		
		a.mer(b);
		a.print();
		cin >> num1 >> num2;
		a.insert(num1, num2);
		a.print();
	}
}