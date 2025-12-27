#include <iostream>
#include <vector>
using namespace std;


const int N = 1005;
vector<int> edge[N];
bool visit[N];
int aa = 0;
int arr[N] = { 0, };

void insertEdge(int srcId, int dstId) {
	edge[srcId].push_back(dstId);
	edge[dstId].push_back(srcId);

}

void DFS(int curId) {
	visit[curId] = true;
	arr[curId] = 1;
	
	for (int i = 0; i < edge[curId].size(); i++) {
		if (visit[edge[curId][i]] != true) {
			DFS(edge[curId][i]);
		}
	}
}

void reset() {
	for (int i = 0; i < N; i++) {
		edge[i].clear();
		visit[i] = false;
	}


}

int main() {
	int t;

	
	

		int n, m;
		int num;
		cin >> n >> m >> num;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			insertEdge(x, y);
		}

		for (int i = 0; i < num; i++) {
			int f;
			int f2;
			cin >> f >> f2;
			DFS(f);
			int v = 0;
			int v2 = 0;
			for (int o = 0; o < N; o++) {
				if (arr[o] == 1) {
					v = o;
					break;
				}
			}

			for (int k = 0; k < N; k++) {
				visit[k] = false;

			}
			for (int k = 0; k < N; k++) {
				arr[k] = 0;
			}

			DFS(f2);
			for (int o = 0; o < N; o++) {
				if (arr[o] == 1) {
					v2 = o;
					break;
				}
			}

			for (int k = 0; k < N; k++) {
				visit[k] = false;

			}
			for (int k = 0; k < N; k++) {
				arr[k] = 0;
			}

			if (v == v2) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}

		reset();

	


}

