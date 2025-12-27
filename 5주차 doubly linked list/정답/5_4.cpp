#include <iostream>
using namespace std;

struct node
{
	string data;
	node* next;
	node* prev;
};

class table {
private:
	node* header;
	node* trailer;
	int n;
	node* pos;
public:

	table() {
		header = new node;
		trailer = new node;
		header->next = trailer;
		trailer->prev = header;
		pos = header;
		n = 0;
	}

	void up(int x) {
		if (n == 0) {
			return;
		}
		for (int i = 0; i < x; i++) {
			pos = pos->prev;
			if (pos == header) {
				pos = header->next;
			}
		}
	}

	void down(int x) {
		if (n == 0) {
			return;
		}
		for (int i = 0; i < x; i++) {
			pos = pos->next;
			if (pos == trailer) {
				pos = trailer->prev;
			}
		}
	}

	void cut() {
		if (n == 0 || pos == NULL) {
			return;
		}
		node* apos = pos;
		/*if (pos == header->next)
		{
			pos = pos->next;
		}
		else
		{
			pos = pos->prev;
		}
		apos->prev->next = apos->next;
		apos->next->prev = apos->prev;
		n--;
		delete apos;
		*/


		if (pos == header->next) {
			pos = pos->next;
		}
		else {
			pos = pos->prev;
		}
		apos->prev->next = apos->next;
		apos->next->prev = apos->prev;
		delete apos;
		n--;
	}

	void append1(string name) {
		
		node* newnode = new node;
		newnode->data = name;
		newnode->next = pos->next;
		newnode->prev = pos;
		pos->next->prev = newnode;
		pos->next = newnode;
		pos = pos->next;
		n++;
	}
	void append(string name) {
		if (n == 0) {
			pos = header;
		}
		node* newnode = new node;
		newnode->data = name;
		newnode->next = pos->next;
		newnode->prev = pos;
		pos->next->prev = newnode;
		pos->next = newnode;
		n++;
		if (n == 1) {
			pos = header->next;
		}
	}
	void begin() {
		pos = header->next;
	}
	void nextP() {
		if (pos->next == trailer) {
			return;
		}
		pos = pos->next;
	}
	void print() {
		if (n == 0) {
			cout << "And Then There Were None" << endl;
		}
		else {
			node* curnode = header->next;
			for (int i = 0; i < n; i++) {
				cout << curnode->data << " ";
				curnode = curnode->next;
			}
			cout << endl;
		}
	}
};


int main() {
	int t;
	int n;
	int k;
	int t2;
	string name;
	int value;
	string str;
	cin >> t;

	while (t--)
	{
		table asdf;
		cin >> n >> t2 >> k;
		for (int i = 0; i < n; i++) {
			cin >> name;
			asdf.append1(name);
		}
		asdf.begin();
		for (int i = 0; i < k; i++) {
			asdf.nextP();
		}
		for (int i = 0; i < t2; i++) {
			cin >> str;
			if (str == "up") {
				cin >> value;
				asdf.up(value);
			}
			else if (str == "down") {
				cin >> value;
				asdf.down(value);
			}
			else if (str == "cut") {
				asdf.cut();
			}
			if (str == "append") {
				cin >> name;
				asdf.append(name);
			}
		}
		asdf.print();
	}
}