#include <iostream>
using namespace std;

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

struct entry {
	int key;
	string value;
	int valid;

	entry() {
		key = 0;
		value = "";
		valid = NOITEM;
	}

	entry(int a, string b) {
		key = a;
		value = b;
		valid = ISITEM;
	}

	void erase() {
		valid = AVAILABLE;
	}
};


class hashTable {
private:
	int capacity;
	entry* table;
	int hashfuc(int key) {
		return key % capacity;
	}
public:
	hashTable(int ca) {
		capacity = ca;
		table = new entry[capacity];
	}

	void put(int key, string value) {
		int probe = 1;
		int index = hashfuc(key);
		cout << index << " ";
		while (table[index].valid == ISITEM && probe <= capacity) {
			index = hashfuc(index + 1);
			probe++;
		}
		if (probe >= capacity) {
			cout << -1 << endl;
			return;
		}
		table[index] = entry(key, value);
		cout << index << endl;
	}

	void erase(int key) {
		int probe = 1;
		int index = hashfuc(key);
		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].key == key && table[index].valid == ISITEM) {
				table[index].erase();
				cout << table[index].value << endl;
				
				return;
			}
			index = hashfuc(index + 1);
			probe++;
		}
		cout << "None" << endl;
	}
	void find(int key) {
		int probe = 1;
		int index = hashfuc(key);
		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].key == key && table[index].valid == ISITEM) {
				
				cout << table[index].value << endl;

				return;
			}
			index = hashfuc(index + 1);
			probe++;
		}
		cout << "None" << endl;
	}

	void vacant() {
		int c = 0;
		for (int i = 0; i < capacity; i++) {
			if (table[i].valid != ISITEM) {
				c++;
			}
		}
		cout << c << endl;
	}

};

int main() {
	int t;
	int ca;
	cin >> t >> ca;
	hashTable aa(ca);
	while (t--) {
		string str;
		string value;
		int key;
		cin >> str;
		if (str == "put") {
			cin >> key >> value;
			aa.put(key, value);
		}
		if (str == "erase") {
			cin >> key;
			aa.erase(key);
		}
		if (str == "find") {
			cin >> key;
			aa.find(key);
		}
		if (str == "vacant") {
			aa.vacant();
		}
	}

}