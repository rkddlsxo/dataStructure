#include <iostream>
using namespace std;

int edge[501][501] = { 0, };

int connection[501] = { 0, };

int main() {
	int t;
	int userNum;
	int NconnectNum;
	cin >> userNum >> t >> NconnectNum;
	for (int i = 0; i < NconnectNum; i++) {
		int num1;
		cin >> num1;
		connection[num1] = 1;	
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

			ff[user] = 0;
			for (int i = 1; i <= userNum; i++) {
				if (ff[i] != 0 && connection[i] == 1) {
					ff[i] = 0;
				}
			}

			for (int i = 1; i <= userNum; i++) {
				if (ff[i] == 3) {
					friendNum++;
					point += 2;
				}
				else if (ff[i] == 2) {
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
				if (ff[i] != 0 && connection[i] == 1) {
					ff[i] = 0;
				}
			}


			for (int i = 1; i <= userNum; i++) {
				if (ff[i] == 3) {
					friendNum++;
					point += 2;
				}
				else if (ff[i] == 2) {
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