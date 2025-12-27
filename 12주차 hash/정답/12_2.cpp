#include <iostream>
using namespace std;

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

int pow(int a, int b) { //걍 숫자 제곱해주는거
	int temp = a;
	if (b == 0) return 1;
	for (int i = 1; i < b; i++) {
		a *= temp;
	}
	return a;
}

int valueCalculator(string value) { // string-> int로 바꿔주는거 
	int temp = 0;
	for (int i{ 0 }; i < value.size(); i++) {
		temp += (value[i] - 'a') * pow(26, i);
	}
	return temp;
}

// 학번이 key, 이름을 저장하기
struct entry2
{
	int key;
	string value;
	int valid;

	entry2() {
		key = 0;
		value = "";
		valid = NOITEM;
	}

	entry2(int key, string value) {
		this->key = key;
		this->value = value;
		valid = ISITEM;
	}

	void erase() {
		valid = AVAILABLE;
	}
};  

class gkrqjs {
private:
	entry2* table;
	int capacity;
	int hashFuc(int key) {
		return key % capacity;
	}
public:
	gkrqjs(int n) {
		capacity = n;
		table = new entry2[capacity];
	}

	void put(int key, string value) {
		int index = hashFuc(key);
		int probe = 1;
		while (table[index].valid == ISITEM && probe <= capacity) {
			index = hashFuc(index + 1);
			probe++;
		}

		if (probe > capacity) {
			return;
		}
		table[index] = entry2(key, value);
	}

	void erase(int key) {
		int index = hashFuc(key);
		int probe = 1;
		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key) {
				table[index].erase();
				return;
			}
			index = hashFuc(index + 1);
			probe++;
		}
	}

	string find(int key) {
		int index = hashFuc(key);
		int probe = 1;

		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key) {
				return table[index].value;
			}
			index = hashFuc(index + 1);
			probe++;
		}
		return "";
	}

};




//이름이 key이고 string -> int valuecalculator 이용해서 변환 학번찾기 key, value 둘다 int형이기때문에 다 바꿔줘야댐

struct entry
{
	int key;
	int value;
	int valid;
	int pre;
	entry() {
		key = 0;
		value =0;
		valid = NOITEM;
		pre = 0;
	}

	entry(int key, int value) {
		this->key = key;
		this->value = value;
		valid = ISITEM;
		pre = 0;
	}

	void erase() {
		valid = AVAILABLE;
		pre = 0;
	}
};
class hashTable {
private:
	entry* table;
	int capacity;
	int hashFuc(int key) {
		return key % capacity;
	}
	
public:
	hashTable(int n) {
		capacity = n;
		table = new entry[capacity];
		
	}

	void put(int key, int value) {
		int index = hashFuc(key);
		int probe = 1;
		while (table[index].valid == ISITEM && probe <= capacity) {
			index = hashFuc(index + 1);
			probe++;
		}

		if (probe > capacity) {
			return;
		}
		table[index] = entry(key, value);
	}

	void erase(int key) {
		int index = hashFuc(key);
		int probe = 1;
		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key) {
				table[index].erase();
				return;
			}
			index = hashFuc(index + 1);
			probe++;
		}
	}

	int find(int key) {
		int index = hashFuc(key);
		int probe = 1;

		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key) {
				return table[index].value;
			}
			index = hashFuc(index + 1);
			probe++;
		}
		return 0;
	}

	void present(int key) {
		int index = hashFuc(key);
		int probe = 1;

		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key) {
				table[index].pre++;
				cout <<table[index].pre << endl;
				return ;
			}
			index = hashFuc(index + 1);
			probe++;
		}
		cout << -1 << endl;
		
	}

	void co(int key) {
		int index = hashFuc(key);
		int probe = 1;

		while (table[index].valid != NOITEM && probe <= capacity) {
			if (table[index].valid == ISITEM && table[index].key == key) {
				cout << table[index].pre << endl;
				return;
			}
			index = hashFuc(index + 1);
			probe++;
		}
		cout << -1 << endl;
		
	}
};



int main() {
	gkrqjs gkr(400000);
	hashTable hash(400000);
	string str;
	string str2;
	int t;
	int num;
	cin >> t;
	while (t--) {
		cin >> str;
		if (str == "add") {
			cin >> num >> str2;
			gkr.put(num, str2);
			hash.put(valueCalculator(str2), num);   // 넣을때 이름보고 학번찾기, 학번보고 이름찾기 둘다 가능하게. 대신 학번줬을때는 grkqjs클래스 이름찾는데만 씀
		}

		if (str == "name") { //학번줘서 학번보고 이름찾는거
			cin >> num;
			cout << gkr.find(num) << endl;
		}
		if (str == "delete") { //이것도 학번만 줌
			cin >> num;
			string aa = gkr.find(num); // 학번으로 이름만 찾고 두개 다에서 지워줘야댐
			gkr.erase(num);
			hash.erase(valueCalculator(aa));
		}
		if (str == "number") { // 이름줘가지고 학번찾는거
			cin >> str2;
			cout << hash.find(valueCalculator(str2)) << endl;
		}

		if (str == "present") { // hash클래스 안에 pre변수 이용해서 횟수세기 
			cin >> str2;
			hash.present(valueCalculator(str2));
		}

		if (str == "count") { // 학번줘서 학번으로 이름찾고 똑같이 pre출력
			cin >> num;
			string aa = gkr.find(num);
			hash.co(valueCalculator(aa));
		}
	}
}
