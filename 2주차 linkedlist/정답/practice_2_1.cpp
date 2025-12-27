#include <iostream>
using namespace std;

struct node
{
	node* next;
	int data;
};

class link {
private:
	node* tail;
	node* head;
	int n;
public:

	link() {
		head = NULL;
		tail = NULL;
		n = 0;
	}
	
	void Print() {
		node* curnode = head;
		if (n == 0) {
			cout << "empty" << endl;
			return;
		}
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
		}
		else {
			tail->next = newnode;
			tail = newnode;
		}
		n++;
		Print();
	}

	void Delete(int x) {
		node* curnode = head;
		if (n == 0) {
			cout << -1 << endl;
			return;
		}
		if (x >= n) {
			cout << -1 << endl;
			return;
		}
		if (x == 0) {
			if (n == 1) {
				head = tail = NULL;
			}
			else {
				head = head->next;
			}
		}
		else {
			node* prenode = head;
			for (int i = 0; i < x; i++) {
				prenode = curnode;
				curnode = curnode->next;
			}
			prenode->next = curnode->next;
			if (curnode == tail) {
				tail = prenode;
			}
		}
		cout << curnode->data << endl;
		delete curnode;
		n--;
	}


	void AfterMax(int s) {
		if (n == 0) {
			cout << "error" << endl;
			return;
		}
		if (s >= n) {
			cout << "error" << endl;
			return;
		}
		node* curnode = head;
		for (int i = 0; i < s; i++) {
			curnode = curnode->next;
		}
		int max = 0;
		while (curnode != NULL) {
			if (curnode->data > max) {
				max = curnode->data;
			}
			curnode = curnode->next;
		}
		cout << max << endl;
	}

	void Sum() {
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
	string str;
	int value;
	link asdf;
	cin >> t;
	while (t--) {
		cin >> str;
		if (str == "Print") {
			asdf.Print();
		}
		else if (str == "Append") {
			cin >> value;
			asdf.Append(value);
		}
		else if (str == "Delete") {
			cin >> value;
			asdf.Delete(value);
		}
		else if (str == "AfterMax") {
			cin >> value;
			asdf.AfterMax(value);
		}
		else if (str == "Sum") {
			asdf.Sum();
		}
	}
}