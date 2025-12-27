#include <iostream>
#include <string>
using namespace std;

class arraystack {
private:
    int* arr;
    int capacity;
    int topindex;
public:
    arraystack(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        topindex = -1;
    }
    bool empty() {
        return (topindex == -1);
    }
    int size() {
        return topindex + 1;
    }
    int top() {
        if (empty()) {
            return -1;
        }
        return arr[topindex];
    }
    void push(int data) {
        if (size() == capacity) {
            return;
        }
        arr[++topindex] = data;
    }
    void pop() {
        if (empty()) {
            return;
        }
        topindex--;
    }
};

struct node {
    int data;
    node* next;
};
class liststack {
private:
    node* topnode;
    int n;
public:
    liststack() {
        topnode = NULL;
        n = 0;
    }
    bool empty() {
        return(n == 0);
    }
    int size() {
        return n;
    }
    int top(int k) {
        if (empty()) {
            cout << -1 << endl;
            return 0;
        }
        if (topnode->data < 0) {
            return -(topnode->data) % k;
        }

        return topnode->data % k;
    }
    void push(int data) {
        node* newnode = new node;
        newnode->data = data;
        newnode->next = topnode;
        topnode = newnode;
        n++;
    }
    int pop() {
        if (empty()) {
            return -1;
        }
        node* curNode = topnode;
        topnode = topnode->next;
        int num = curNode->data;
        delete curNode;
        n--;
        return num;
    }


    void dustks(string a, int k) {
        int p1, p2, value = 0;
        char ch;
        liststack stack;
        int len = a.length();
        for (int i = 0; i < len; i++) {
            ch = a[i];
            if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
                value = ch - '0';
                stack.push(value);

            }
            else {

                p2 = stack.pop();

                p1 = stack.pop();


                switch (ch)
                {
                case'+':
                    stack.push(p1 + p2);

                    break;
                case'-':
                    stack.push(p1 - p2);

                    break;
                case'*':
                    stack.push(p1 * p2);

                    break;
                case'/':
                    stack.push(p1 / p2);

                    break;
                }

            }
        }
        cout << stack.top(k) << endl;
    }
};

int main() {
    liststack ls;
    string a;
    int num;
    int k;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> a;
        cin >> k;
        ls.dustks(a, k);
    }



    return 0;
}