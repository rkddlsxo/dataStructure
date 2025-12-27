#include <iostream>
using namespace std;

class arrayqueue {
private:
	int n;
	int frontIndex;
	int rearIndex;
	int capacity;
	int* arr;

public:
	arrayqueue(int capacity) {
		frontIndex = rearIndex = 0;
		n = 0;
		this->capacity = capacity;
		arr = new int[capacity];
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

	bool full() {
		if (n == capacity) {
			return true;
		}
		else {
			return false;
		}
	}

	void front() {
		if (isEmpty()) {
			cout << "Empty" << endl;
		}
		else {
			cout << arr[frontIndex] << endl;
		}
	}

	void enqueue(int value) {
		if (full()) {
			cout << "Full" << endl;
			return;
		}
		else {
			arr[rearIndex] = value;
			rearIndex = (rearIndex + 1) % capacity;
			n++;
		}
	}

	void dequeue() {
		if (isEmpty()) {
			cout << "Empty" << endl;
			return;
		}
		else {
			int temp;
			temp = arr[frontIndex];
			cout << temp << endl;
			frontIndex = (frontIndex + 1) % capacity;
			n--;
		}
	}

	void rearNsum(int value) {
		int sum = 0;
		if (isEmpty()) {
			cout << "Empty" << endl;
			return;
		}
		else if (value > n) {
			cout << "error" << endl;
			return;
		}
		else {
			if (rearIndex > frontIndex) {
				for (int i = 1; i < value+1; i++) {
					sum += arr[rearIndex - i];
				}
				
			}
			else {
				for (int i = 1; i < value + 1; i++) {
					if (rearIndex - i < 0) {
						sum += arr[rearIndex + capacity - i];
					}
					else {
						sum += arr[rearIndex - 1];
					}
					
				}
			}
			cout << sum << endl;
		}
	}



};


int main() {
	int t;
	int capacity;
	string str;
	int value;
	cin >> capacity;
	cin >> t;
	arrayqueue queue(capacity);
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
		if (str == "full") {
			if (queue.full()) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		else if (str == "size") {
			cout << queue.size() << endl;
		}
		else if (str == "front") {
			queue.front();
		}
		else if (str == "enqueue") {
			cin >> value;
			queue.enqueue(value);
		}
		else if (str == "dequeue") {
			queue.dequeue();
		}
		else if (str == "rearNsum") {
			cin >> value;
			queue.rearNsum(value);
		}
	}
}
