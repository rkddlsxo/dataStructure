#include <iostream>
using namespace std;

#define LOGIN 3
#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

int pow(int a, int b) {
	int temp = a;
	if (b == 0) {
		return 1;
	}
	for (int i = 1; i < b; i++) {
		temp *= a;
	}
	return temp;
}

int calculator(string str) {
	int temp = 0;
	for (int i = 0; i < str.size(); i++) {
		temp += (str[i] - 'a') * pow(26, i);
	}
	return temp;
}

struct entry
{
	int key;
	string value;
	int valid;
	
	entry() {
		key = 0;
		value = "";
		valid = NOITEM;
	}

	entry(int key, string value) {
		this->key = key;
		this->valid = ISITEM;
		this->value = value;
	}

	void erase() {
		this->valid = AVAILABLE;
	}
};

class Hash {
private:
	int capacity;
	entry* table;
	int hashfuc(int key) {
		return key % capacity;
	}
	int* idList;
	int n;
	int onlineCount;

public:
	Hash(int capa) {
		this->capacity = capa;
		table = new entry[capacity];
		idList = new int[capacity];
		n = 0;
		onlineCount = 0;
	}
	bool find(int key) {
		int index = hashfuc(key);
		int probe = 1;
		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].key == key) {
				return false;
			}
			index = hashfuc(index + 1);
			probe++;
		}
		return true;
	}
	void signUp(int key, string pw) {
		
		if (find(key) == false) {
			cout << "Invalid" << endl;
			return;
		}

		int index = hashfuc(key);
		int probe = 1;
		while (table[index].valid == ISITEM && probe <= capacity) {
			
			index = hashfuc(index + 1);
			probe++;
		}

		if (probe >= capacity) {
			cout << "Invalid" << endl;
			return;
		}
		table[index] = entry(key, pw);
		cout << "Submit" << endl;
	} 

	void login(int key, string pw) {
		if (find(key) == true) {
			cout << "Invalid" << endl;
			return;
		}

		int index = hashfuc(key);
		int probe = 1;
		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].key == key && table[index].value == pw) {
				if (table[index].valid == LOGIN) {
					cout << "Already" << endl;
					return;
				}
				else {
					table[index].valid = LOGIN;
					cout << "Submit" << endl;
					onlineCount++;
					return;
				}
			}
			index = hashfuc(index + 1);
			probe++;
		}
		if (probe >= capacity) {
			return;
		}
		cout << "Invalid" << endl;
	}

	void logout(int key) {
		int index = hashfuc(key);
		int probe = 1;
		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].key == key) {
				table[index].valid = ISITEM;
				cout << "Submit" << endl;
				onlineCount--;
				return;
			}
			index = hashfuc(index + 1);
			probe++;
		}
	}

	void online() {
		cout << onlineCount << endl;
	}

};


int main() {
	Hash aa(400001);
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		string id;
		string pw;
		if (str == "signup") {
			cin >> id >> pw;
			int key = calculator(id);
			aa.signUp(key, pw);
		}
		if (str == "login") {
			cin >> id >> pw;
			int key = calculator(id);
			aa.login(key, pw);
		}
		if (str == "logout") {
			cin >> id;
			int key = calculator(id);
			aa.logout(key);
		}
		if (str == "online") {
			aa.online();
		}
	}
}