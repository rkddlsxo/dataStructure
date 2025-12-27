#include <iostream>
using namespace std;

int arr[10001][10001] = {0,};
int vertexIdx[10001] = {0,};
int deg[10001] = { 0, };

int main() {

	int value;
	string str;
	int t;
	int ver = 0;
	int src, dst;
	int srcIdx = 0;
	int	dstIdx = 0;
	int num = 0;
	int count = 0;
	
	cin >> t;
	while (t--) {
		cin >> str;
		
		if (str == "insertVertex") {
			int v = 0;
			cin >> value;
			for (int i = 0; i < num; i++) {
				if (vertexIdx[i] == value) {
					v = 1;
					break;
				}
			}

			if (v == 1) {
				cout << "Exist" << endl;
			}
			else {
				vertexIdx[num] = value;
				num++;
				count++;
			}
		}
		if (str == "insertEdge") {
			
			cin >> src >> dst;
			for (int i = 0; i < num; i++) {
				if (vertexIdx[i] == src) {
					srcIdx = i;
					
					break;
				}
			}

			for (int i = 0; i < num; i++) {
				if (vertexIdx[i] == dst) {
					dstIdx = i;
					
					break;
				}
			}

			if (arr[srcIdx][dstIdx] == 1 || arr[dstIdx][srcIdx] == 1) {
				cout << "Exist" << endl;
			}
			else {
				arr[srcIdx][dstIdx] = 1;
				arr[dstIdx][srcIdx] = 1;
				deg[srcIdx]++;
				deg[dstIdx]++;
			}
		}
		if (str == "eraseEdge") {
			cin >> src >> dst;
			for (int i = 0; i < num; i++) {
				if (vertexIdx[i] == src) {
					srcIdx = i;		
					break;
				}
			}

			for (int i = 0; i < num; i++) {
				if (vertexIdx[i] == dst) {
					dstIdx = i;	
					break;
				}
			}

			if (arr[srcIdx][dstIdx] == 0 || arr[dstIdx][srcIdx] == 0) {
				cout << "None" << endl;
			}
			else {
				arr[srcIdx][dstIdx] = 0;
				arr[dstIdx][srcIdx] = 0;
				deg[srcIdx]--;
				deg[dstIdx]--;
			}
		}
		if (str == "eraseVertex") {
			cin >> value;
			for (int i = 0; i < num; i++) {
				if (vertexIdx[i] == value) {
					ver = i;
					vertexIdx[ver] = 0;
				}
			}

			for (int i = 0; i < num; i++) {
				if (arr[ver][i] == 1) {
					arr[ver][i] = 0;
					arr[i][ver] = 0;
					deg[i]--;
				}
			}

			count--;
		}

		if (str == "isAdjacent") {
			cin >> src >> dst;
			for (int i = 0; i < num; i++) {
				if (vertexIdx[i] == src) {
					srcIdx = i;
					break;
				}
			}

			for (int i = 0; i < num; i++) {
				if (vertexIdx[i] == dst) {
					dstIdx = i;
					break;
				}
			}
			
			if (arr[srcIdx][dstIdx] == 1) {
				cout << "True" << " ";
			}
			else {
				cout << "False" << " ";
			}

			if (deg[srcIdx] < deg[dstIdx]) {
				cout << src << endl;
			}
			else if (deg[srcIdx] > deg[dstIdx]) {
				cout << dst << endl;
			}
			else {
				if (src > dst) {
					cout << dst << endl;
				}
				else {
					cout << src << endl;
				}
			}
		}

		if (str == "minVertexInfo") {
			if (count == 0) {
				cout << -1 << endl;
			}
			else {
				int minIdx = 0;
				int minnum = 100001;
				for (int i = 0; i < num; i++) {
					if (vertexIdx[i] < minnum && vertexIdx[i]>0) {
						minnum = vertexIdx[i];
						minIdx = i;
					}
				}

				cout << minnum << " " << deg[minIdx] << endl;
			}
		}
	}
}