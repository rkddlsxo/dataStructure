#include <iostream>
using namespace std;

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

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
		this->value = value;
		valid = ISITEM;
	}

	void erase() {
		valid = AVAILABLE;
	}
};


//class hashTable {
//private:
//	entry* table;
//	int capacity;
//	int hashFuc(int key) {
//		return key % capacity;
//	}
//public:
//	hashTable(int n) {
//		capacity = n;
//		table = new entry[capacity];
//	}
//
//	void put(int key, string value) {
//		int index = hashFuc(key);
//		int probe = 1;
//		while (table[index].valid == ISITEM && probe <= capacity) {
//			index = hashFuc(index + 1);
//			probe++;
//		}
//
//		if (probe > capacity) {
//			return;
//		}
//		table[index] = entry(key, value);
//	}
//
//	void erase(int key) {
//		int index = hashFuc(key);
//		int probe = 1;
//		while (table[index].valid != NOITEM && probe <= capacity) {
//			if (table[index].valid == ISITEM && table[index].key == key) {
//				table[index].erase();
//				return;
//			}
//			index = hashFuc(index + 1);
//			probe++;
//		}
//	}
//
//	string find(int key) {
//		int index = hashFuc(key);
//		int probe = 1;
//
//		while (table[index].valid != NOITEM && probe <= capacity) {
//			if (table[index].valid == ISITEM && table[index].key == key) {
//				return table[index].value;
//			}
//			index = hashFuc(index + 1);
//			probe++;
//		}
//		return "";
//	}
//
//};
//
//


class doublehashTable {
private:
	entry* table;
	int capacity;
	int divisor;
	int hashFuc(int key) {
		return key % capacity;
	}

	int hashFuc2(int key) {
		return divisor - (key % divisor);
	}
public:
	doublehashTable(int n, int m) {
		divisor = m;
		capacity = n;
		table = new entry[capacity];
	}

	void put(int key, string value) {
		cout << hashFuc(key) << " ";
		int index = hashFuc(key);
		int probe = 1;
		while (table[index].valid == ISITEM && probe <= capacity) {
			index = hashFuc(index + hashFuc2(key));
			probe++;
		}

		if (probe > capacity) {
			cout << -1 << endl;
			return;
		}
		table[index] = entry(key, value);
		cout << index << endl;
	}

	void erase(int key) {
		int index = hashFuc(key);
		int probe = 1;
		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key) {
				cout << table[index].value << endl;
				table[index].erase();
				return;
			}
			index = hashFuc(index + hashFuc2(key));
			probe++;
		}
		cout << "None" << endl;
	}

	string find(int key) {
		int index = hashFuc(key);
		int probe = 1;

		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key) {
				return table[index].value;
			}
			index = hashFuc(index + hashFuc2(key));
			probe++;
		}
		return "None";
	}

	void vacant() {
		int count = 0;
		for (int i = 0; i < capacity; i++) {
			if (table[i].valid != ISITEM) {
				count++;
			}
		}
		cout << count << endl;
	}
};


int main() {
	int t;
	string str1;
	string str2;
	int k;
	int num;
	int m;
	cin >> t >> num >> m;
	doublehashTable hash(num, m);
	while (t--) {
		cin >> str1;
		if (str1 == "put") {
			cin >> k >> str2;
			hash.put(k, str2);
		}
		else if (str1 == "find") {
			cin >> k;
			cout << hash.find(k) << endl;
		}
		else if (str1 == "erase") {
			cin >> k;
			hash.erase(k);
		}
		else if (str1 == "vacant") {
			hash.vacant();
		}
	}
}
