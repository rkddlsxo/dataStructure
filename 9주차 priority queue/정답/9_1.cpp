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
		int idx;
		for (idx = 0; idx < arr.size(); idx++) {
			if (C(arr[idx], e)) {
				break;
			}
		}
		arr.insert(arr.begin() + idx, e);
	}

	int top() {
		if (arr.size() == 0) {
			return -1;
		}
		return arr.back();

	}

	void pop() {
		if (arr.size() == 0) {
			return;
		}
		arr.pop_back();
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
