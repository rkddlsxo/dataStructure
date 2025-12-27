#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

class linkqueue {
private:
	node* frontnode;
	node* rearnode;
	int n;


public:
	linkqueue() {
		n = 0;
		frontnode = rearnode = NULL;
	}

	int size() {
		return n;
	}

	bool isEmpty() {
		if (n == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void rear() {
		if (isEmpty()) {
			cout << "Empty" << endl;
			return;
		}
		else {
			cout << rearnode->data << endl;;
			return;
		}
	}
	void enqueue(int value) {
		node* newnode = new node;
		newnode->data = value;
		newnode->next = NULL;
		if (isEmpty()) {
			frontnode = rearnode = newnode;
		}
		else {
			rearnode->next = newnode;
			rearnode = newnode;
		}
		n++;
		return;
	}

	void dequeue() {
		int temp;
		if (isEmpty()) {
			cout << "Empty" << endl;
			return;
		}
		else if(n==1){
			node* curnode = frontnode;
			temp = curnode->data;
			frontnode = rearnode = NULL;
			delete curnode;
		}
		else {
			node* curnode = frontnode;
			temp = curnode->data;
			frontnode = frontnode->next;
			delete curnode;
		}
		cout << temp << endl;
		n--;
	}

	void frontNsum(int num) {
		if (isEmpty()) {
			cout << "Empty" << endl;
			return;
		}
		else if (num > n) {
			cout << "error" << endl;
			return;
		}
		
		else {
			int sum = 0;
			node* curnode = frontnode;
			for (int i = 0; i < num; i++) {
				sum += curnode->data;
				curnode = curnode->next;
			}
			cout << sum << endl;
		}
	}

};


int main() {
	int t;
	string str;
	int value;
	linkqueue queue;
	cin >> t;
	while (t--) {
		cin >> str;
		if (str == "isEmpty") {
			if (queue.isEmpty()) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		else if (str == "size") {
			cout << queue.size() << endl;
		}
		else if (str == "rear") {
			queue.rear();
		}
		else if (str == "enqueue") {
			cin >> value;
			queue.enqueue(value);
		}
		else if (str == "dequeue") {
			queue.dequeue();
		}
		else if (str == "frontNsum") {
			cin >> value;
			queue.frontNsum(value);
		}
	}
}