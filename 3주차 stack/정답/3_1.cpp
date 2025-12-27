#include <iostream>
#include <string>
using namespace std;

class arraystack {
private:
	int topindex;
	int* arr;
	int capacity;
public:
	arraystack(int capacity) {
		this->capacity = capacity;
		arr = new int[capacity];
		topindex = -1;
	}

	bool empty() {
		if (topindex == -1) {
			return true;
		}

		else {
			return false;
		}
	}

	void size() {
		cout << topindex + 1 << endl;;
	}

	void top(){
		if (topindex == -1) {
			cout << -1 ;
		}
		else {
			cout << arr[topindex];
		}
		cout << endl;
	}

	void push(int value) {
		if (topindex+1 == capacity) {
			cout << "FULL" << endl;
			return;
		}
		else {
			arr[++topindex] = value;
		}
	}

	void popsum(int num) {
		int sum = 0;
		if (topindex == -1) {
			cout << -1 << endl;
			return;
		}
		else if(topindex < num){
			while (topindex != -1) {
				sum += arr[topindex];
				topindex--;
			}
		}
		else {
			for (int i = 0; i < num; i++) {
				sum += arr[topindex];
				topindex--;
			}
		}
		cout << sum << endl;
		return;
	}
};


int main() {
	int t;
	int value;
	int capacity;
	string str;
	cin >> capacity >> t;
	arraystack stack(capacity);
	for (int k = 0; k < t; k++) {

		cin >> str;
		if (str == "size") {
			stack.size();
		}

		else if (str == "empty") {
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

		else if (str == "popsum") {
			cin >> value;
			stack.popsum(value);
		}
	}
}