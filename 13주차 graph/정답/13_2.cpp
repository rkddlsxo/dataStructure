#include <iostream>
using namespace std;

int edge[501][501] = { 0, };
int deg[501];
int connection[501][501] = { 0, };

int main() {
	int t;
	int userNum;
	int connectNum;
	cin >> userNum >> t >> connectNum;
	for (int i = 0; i < connectNum; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		connection[num1][num2] = 1;
		connection[num2][num1] = 1;
		deg[num1]++;
		deg[num2]++;
	}

	for (int i = 1; i <= userNum; i++) {
		for (int k = 1; k <= userNum; k++) {
			int value;
			cin >> value;
			edge[i][k] = value;
		}
	}

	while (t--) {

		
		int user, F;
		int point = 0;
		int friendNum = 0;
		cin >> user >> F;
		if (F == 1) {
			int ff[501] = { 0, };

			for (int i = 1; i <= userNum; i++) {
				if (edge[user][i] == 1) {
					ff[i] = 3;
				}
			}
			
			for (int i = 1; i <= userNum; i++) {
				if (ff[i] != 0) {
					for (int k = 1; k <= userNum; k++) {
						if (connection[i][k] == 1 && ff[k] == 0) {
							ff[k] = 1;
						}
					}
				}
			}

			ff[user] = 0;
			for (int i = 1; i <= userNum; i++) {
				if (ff[i] != 0 && connection[i][user] == 1) {
					ff[i] = 0;
				}
			}

			for (int i = 1; i <= userNum; i++) {
				if (ff[i] == 3) {
					friendNum++;
					point += 3;
				}
				else if (ff[i] == 2) {
					friendNum++;
					point += 2;
				}
				else if (ff[i] == 1) {
					friendNum++;
					point += 1;
				}
			}

			if (friendNum == 0) {
				cout << -1 << endl;
			}
			else {
				cout << friendNum << " " << point << endl;
			}
		}

		if (F == 2) {
			int ff[501] = { 0, };
			
			for (int i = 1; i <= userNum; i++) {
				if (edge[user][i] == 1) {
					ff[i] = 3;
				}
			}
			ff[user] = 0;
			for (int i = 1; i <= userNum; i++) {
				if (ff[i] != 0) {
					for (int k = 1; k <= userNum; k++) {
						if (edge[i][k] == 1 && ff[k] == 0) {
							ff[k] = 2;
						}
					}
				}
			}
			ff[user] = 0;

			for (int i = 1; i <= userNum; i++) {
				if (ff[i] != 0) {
					for (int k = 1; k <= userNum; k++) {
						if (connection[i][k] == 1 && ff[k] == 0) {
							ff[k] = 1;
						}
					}
				}
			}
			ff[user] = 0;
			for (int i = 1; i <= userNum; i++) {
				if (ff[i] != 0 && connection[i][user] == 1) {
					ff[i] = 0;
				}
			}


			for (int i = 1; i <= userNum; i++) {
				if (ff[i] == 3) {
					friendNum++;
					point += 3;
				}
				else if (ff[i] == 2) {
					friendNum++;
					point += 2;
				}
				else if (ff[i] == 1) {
					friendNum++;
					point += 1;
				}
			}

			if (friendNum == 0) {
				cout << -1 << endl;
			}
			else {
				cout << friendNum << " " << point << endl;
			}

		}
	}
}