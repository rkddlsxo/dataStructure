#include <iostream>
using namespace std;

struct node {
	node* next;
	int data;
};


class listqueue {
private:
	int n;
	node* frontnode;
	node* rearnode;


public:
	listqueue() {
		n = 0;
		frontnode = NULL;
		rearnode = NULL;
	}

	int size() {
		return n;
	}

	void isEmpty() {
		if (n == 0) {
			cout << "True" << endl;
			return;
		}
		else {
			cout << "False" << endl;
			return;
		}
	}
	int front() {
		if (n == 0) {	
			return -1;
		}
		return frontnode->data;
	}

	
	void enqueue(int value) {
		node* newnode = new node;
		newnode->data = value;
		newnode->next = NULL;
		if (n == 0) {
			frontnode = rearnode = newnode;
		}

		else {
			rearnode->next = newnode;
			rearnode = newnode;
		}
		n++;
	}

	void dequeue() {
		node* curnode = frontnode;
		if (n == 0) {
			return;
		}
		else if (n == 1) {		
			frontnode = rearnode = NULL;				
		}
		else {		
			frontnode = frontnode->next;
		}
		delete curnode;
		n--;
	}
	void print() {
		if (n == 0) {
			cout << "Empty" << endl;
			return;
		}
		node* curnode = frontnode;
		while (!(curnode == NULL)) {
			cout << curnode->data << " ";
			curnode = curnode->next;
		}
		cout << endl;
	}
	
	void getpoint(int num) {
		if (frontnode->next == NULL) {
			return;
		}
		else {
			frontnode->next->data += num;
		}
	}
};




int main() {
	int n;
	int t;
	int value;
	
	listqueue player1;
	listqueue player2;

	cin >> t;
	while (t--) {
		
		cin >> n;
		int score1 = 0;
		int score2 = 0;
		int n1 = 0;
		for (int i = 0; i < n; i++) {
			cin >> value;
			player1.enqueue(value);
		}
		for (int i = 0; i < n; i++) {
			cin >> value;
			player2.enqueue(value);
		}
		for (int i = 0; i < n; i++) {
			if (i == n - 1) {
				cout << "Round" << i + 1 << " ";
				if (player1.front() > player2.front()) {
					score1++;
					player1.getpoint(player1.front() - player2.front());
					cout << player1.front() << ">" << player2.front() << " ";
					if (score1 == score2) {
						cout << score1 << ":" << score2 << endl;
						cout << "Winner P1" << endl;
						n1++;
					}
				}
				else if (player1.front() < player2.front()) {
					score2++;
					player2.getpoint(player2.front() - player1.front());
					cout << player1.front() << "<" << player2.front() << " ";
					if (score1 == score2) {
						cout << score1 << ":" << score2 << endl;
						cout << "Winner P2" << endl;
						n1++;
					}
				}
				else if (player1.front() == player2.front()) {
					cout << player1.front() << "=" << player2.front() << " ";
					if (score1 == score2) {
						cout << score1 << ":" << score2 << endl;
						cout << "Draw" << endl;
						n1++;
					}
				}

				
				player1.dequeue();
				player2.dequeue();
				
			}
			else {
				cout << "Round" << i + 1 << " ";
				if (player1.front() > player2.front()) {
					score1++;
					player1.getpoint(player1.front() - player2.front());
					cout << player1.front() << ">" << player2.front() << " ";
				}
				else if (player1.front() < player2.front()) {
					score2++;
					player2.getpoint(player2.front() - player1.front());
					cout << player1.front() << "<" << player2.front() << " ";
				}
				else if (player1.front() == player2.front()) {
					cout << player1.front() << "=" << player2.front() << " ";
				}

				cout << score1 << ":" << score2 << endl;
				player1.dequeue();
				player2.dequeue();

				
			}
			
		}
		if (n1 == 0) {
			cout << score1 << ":" << score2 << endl;
			if (score1 > score2) {
				cout << "Winner P1" << endl;
			}
			else if (score1 < score2) {
				cout << "Winner P2" << endl;
			}
			if (score1 == score2) {

				cout << "Draw" << endl;
			}
		}
		
		

		


	}

}

