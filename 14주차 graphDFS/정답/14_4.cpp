#include <iostream>
#include <vector>
using namespace std;

const int N = 1005;
vector<int> edge[N];
bool visit[N];
int ca = 0;
void reset() {
	for (int i = 0; i < N; i++) {
		visit[i] = false;
		
	}
	ca = 0;
}

void insertEdge(int s, int d) {
	edge[s].push_back(d);
	edge[d].push_back(s);
}

void DFS(int c) {
	ca++;
	visit[c] = true;
	for (int i = 0; i < edge[c].size(); i++) {
		if (visit[edge[c][i]] != true) {
			DFS(edge[c][i]);
		}
	}
}


int main() {
	int t;
	int b;
	int s;
	int d;
	int n;
	cin >> n >> b >> t;
	for (int i = 0; i < b; i++) {
		cin >> d >> n;
		insertEdge(d, n);
	}
	for (int i = 0; i < t; i++) {
		cin >> s;
		DFS(s);
		cout << ca << endl;
		reset();
	}
}