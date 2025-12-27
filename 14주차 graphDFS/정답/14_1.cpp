#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
	int arr[4000][4000] = { 0, };
	int vertexIdx[4000] = { 0, };
	int n;

public:
	Graph() {
		n = 0;
	}

	void InsertVertex(int s) {
		for (int i = 0; i < n; i++) {
			if (vertexIdx[i] == s) {
				cout << "ERRORCODE 01" << endl;
				return;
			}
		}
		vertexIdx[n] = s;
		n++;
	}

	void InsertEdge(int s, int d) {
		int srcIdx = -1;
		int dstIdx = -1;
		for (int i = 0; i < n; i++) {
			if (vertexIdx[i] == s) {
				srcIdx = i;
			}
			if (vertexIdx[i] == d) {
				dstIdx = i;
			}
		}

		if (srcIdx == -1 || dstIdx == -1) {
			cout << "ERRORCODE 03" << endl;
			return;
		}

		if (arr[srcIdx][dstIdx] == 1 || arr[dstIdx][srcIdx] == 1) {
			cout << "ERRORCODE 02" << endl;
			return;
		}
		arr[srcIdx][dstIdx] = 1;
		arr[dstIdx][srcIdx] = 1;

	}

	void EraseVertex(int s) {
		int verIdx = -1;
		for (int i = 0; i < n; i++) {
			if (vertexIdx[i] == s) {
				verIdx = i;
			}
		}
		if (verIdx == -1) {
			cout << "ERRORCODE 03" << endl;
			return;
		}

		for (int i = 0; i < n; i++) {
			arr[i][verIdx] = 0;
			arr[verIdx][i] = 0;
		}

		vertexIdx[verIdx] = 0;
	}

	void EraseEdge(int s, int d) {
		int srcIdx = -1;
		int dstIdx = -1;
		for (int i = 0; i < n; i++) {
			if (vertexIdx[i] == s) {
				srcIdx = i;
			}
			if (vertexIdx[i] == d) {
				dstIdx = i;
			}
		}

		if (srcIdx == -1 || dstIdx == -1) {
			cout << "ERRORCODE 03" << endl;
			return;
		}

		if (arr[srcIdx][dstIdx] == 0 || arr[dstIdx][srcIdx] == 0) {
			cout << "ERRORCODE 04" << endl;
			return;
		}
		arr[srcIdx][dstIdx] = 0;
		arr[dstIdx][srcIdx] = 0;
	}


	void PrintAdjSum(int s) {
		int verIdx = -1;
		for (int i = 0; i < n; i++) {
			if (vertexIdx[i] == s) {
				verIdx = i;
			}
		}
		if (verIdx == -1) {
			cout << "ERRORCODE 03" << endl;
			return;
		}

		int count = 0; 
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[verIdx][i] == 1) {
				count++;
				sum += vertexIdx[i];
			}
		}

		cout << count << " " << sum << endl;
	}

	void PrintAdjMin(int s) {
		int verIdx = -1;
		for (int i = 0; i < n; i++) {
			if (vertexIdx[i] == s) {
				verIdx = i;
			}
		}
		if (verIdx == -1) {
			cout << "ERRORCODE 03" << endl;
			return;
		}

		int count = 0;
		int min = 1000001;
		for (int i = 0; i < n; i++) {
			if (arr[verIdx][i] == 1) {
				count++;
				if (min > vertexIdx[i]) {
					min = vertexIdx[i];
				}
			}
		}
		if (count == 0) {
			cout << -1 << endl;
		}
		else {
			cout << min << endl;
		}
	}
};


int main() {
	Graph* GID[101];
	for (int i = 0; i < 101; i++) {
		GID[i] = NULL;
	}

	int t;
	cin >> t;
	while (t--) {
		string str;
		int s;
		int g;
		int d;
		cin >> str;
		if (str == "Graph") {
			cin >> g;
			Graph* a = new Graph;
			GID[g] = a;
		}
		if (str == "InsertVertex") {
			cin >>g >> s;
			GID[g]->InsertVertex(s);
		}
		if (str == "EraseVertex") {
			cin >> g >> s;
			GID[g]->EraseVertex(s);
		}
		if (str == "InsertEdge") {
			cin >> g >> s >> d;
			GID[g]->InsertEdge(s, d);
		}
		if (str == "EraseEdge") {
			cin >> g >> s >> d;
			GID[g]->EraseEdge(s, d);
		}
		if (str == "PrintAdjSum") {
			cin >> g >> s;
			GID[g]->PrintAdjSum(s);
		}
		if (str == "PrintAdjMin") {
			cin >> g >> s;
			GID[g]->PrintAdjMin(s);
		}
	}
}