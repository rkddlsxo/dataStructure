#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct compare {
	bool operator()(const int& e1, const int& e2) const {
		if (e1 % 2 != 0) {
			if (e2 % 2 == 0) {
				return true;
			}
			else {
				return e1>e2;
			}
		}
		else if (e1 % 2 == 0) {
			if (e2 % 2 != 0) {
				return false;
			}
			else {
				return e1 < e2;
			}
		}
		
	}
};

class heap {
private:
	vector<int> arr;

	void swap(int idx1, int idx2) {
		arr[0] = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = arr[0];
	}
	void upHeap(int idx) {
		if (idx == 1) {
			return;
		}
		compare C;
		int parent = idx / 2;
		if (C(arr[idx], arr[parent])) {
			swap(parent, idx);
			upHeap(parent);
		}
	}
	void downHeap(int idx) {
		int left = 2 * idx;
		int right = 2 * idx + 1;
		int child;
		compare C;

		if (left > size()) {
			return;
		}
		else if (left == size()) {
			child = left;
		}
		else {
			if (C(arr[left], arr[right])) {
				child = left;
			}
			else {
				child = right;
			}
		}

		if (C(arr[child], arr[idx])) {
			swap(child, idx);
			downHeap(child);
		}

	}
public:
	heap() {
		arr.push_back(0);
	}
	void insert(int e) {
		arr.push_back(e);
		upHeap(size());
	}
	int size() {
		return arr.size() - 1;
	}
	bool empty() {
		return (arr.size() == 1);
	}
	int min() {
		if (empty()) {
			return -1;
		}
		return arr[1];
	}
	void removeMin() {
		if (empty()) {
			cout << -1 << endl;
			return;
		}
		cout << arr[1] << endl;
		swap(1, size());
		arr.pop_back();
		downHeap(1);
	}

	void pop() {
		if (empty()) {
			return;
		}
		swap(1, size());
		arr.pop_back();
		downHeap(1);
	}


	void print() {
		if (empty()) {
			cout << -1 << endl;
			return;
		}
		for (int i = 1; i <= size(); i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void second() {
		if (size() < 2) {
			cout << "Error" << endl;
			return;
		}
		int temp = min();
		pop();
		cout << min() << endl;
		insert(temp);


	}
};

int main() {
	int value, num;

	int t;
	cin >> t;
	while (t--) {
		heap h;
		cin >> num;
		for (int i = 0; i < num; i++) {
			cin >> value;
			h.insert(value);
		}

		while (h.size() != 0) {
			cout << h.min() << " ";
			h.pop();
		}
		cout << endl;
	}
}