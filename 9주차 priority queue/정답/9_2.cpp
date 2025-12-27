#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct compare {
	bool operator()(const int& e1, const int& e2) {
		int c1 = 1; 
		int c2 = 1;
		int a = e1;
		int b = e2;
		while (a >= 10) {
			a = a / 10; 
			c1++;
		}
		while (b >= 10) {
			b = b / 10;
			c2++;
		}
		if (c1 < c2) {
			return true;
		}
		else if (c1 > c2) {
			return false;
		}
		else if (c1 == c2) {
			return e1 > e2;
		}
	
	}
};
class unsortedSeqPQ {
private :
	vector<int> seq;
public :
	int size() {
		return seq.size();
	}
	bool empty() {
		return (seq.size() == 0);
	}
	void insert(int e) {
		seq.push_back(e);
	}
	int min() {
		if (empty()) return -1;
		compare C;
		int minVal = seq[0];

		for (int i = 0; i < seq.size(); i++) {
			if (C(seq[i], minVal)) {
				minVal = seq[i];
			}
		}
		return minVal;
	}
	void removeMin() {
		if (empty()) return;

		compare C;
		int minIdx = 0;

		for (int i = 0; i < seq.size(); i++) {
			if (C(seq[i], seq[minIdx])) {
				minIdx = i;
			}
		}
		seq.erase(seq.begin() + minIdx);
	}
};


int main() {
	unsortedSeqPQ uq;
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		
		cin >> n;
		for (int i = 0; i < n; i++) {
			int e;
			cin >> e;
			uq.insert(e);
		}
		cout << "Case #" << i <<"." << endl;
		for (int i = 0; i < n; i++) {
			cout << uq.min() << " ";
			uq.removeMin();
		}
		cout << endl;
	}
	return 0;
}