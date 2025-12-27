#include <iostream>
#include <vector>
using namespace std;

struct compare
{
	bool operator()(const int& lhs, const int& rhs) {
		return lhs > rhs;

	}

};

class upq {
private:
	compare C;
	vector<int> arr;

public:
	int size() {
		return arr.size();
	}

	void push(int e) {
		arr.push_back(e);
	}

	int top() {
		if (arr.size() == 0) {
			return -1;
		}
		int minidx = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (C(arr[i], arr[minidx])) {
				minidx = i;
			}
		}
		return arr[minidx];

	}

	void pop() {
		if (arr.size() == 0) {
			return;
		}

		int minidx = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (C(arr[i], arr[minidx])) {
				minidx = i;
			}
		}

		arr.erase(arr.begin() + minidx);
	}

	void print() {
		for (int i = 0; i < arr.size(); i++) {
			cout << arr[i] << " ";
		}
	}
};


int main() {
	int t;
	cin >> t;
	int value;
	int num;
	int s;

	while (t--) {
		vector<int> brr;
		upq aa;
		cin >> num;
		for (int i = 0; i < num; i++) {
			cin >> value;
			brr.push_back(value);
		}
		cin >> s;
		if (s <= num) {
			for (int i = 0; i < s; i++) {
				aa.push(brr[i]);

			}
			cout << "S : ";
			for (int i = s; i < num; i++) {
				cout << brr[i] << " ";
			}
			cout << endl;
			cout << "PQ : ";
			aa.print();
			cout << endl;

		}

		else {
			for (int i = 0; i < num; i++) {
				aa.push(brr[i]);
			}
			cout << "S : ";
			for (int i = 0; i < s - num; i++) {
				cout << aa.top() << " ";
				aa.pop();
			}
			cout << endl;
			cout << "PQ : ";
			aa.print();
			cout << endl;
		}
	}
}
