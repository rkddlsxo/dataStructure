#include <iostream>
#include <string>
using namespace std;

struct node {
    int data;
    node* next;
    
};

class listStack {
public:
    listStack();
    bool empty();
    int size();
    int top();
    void push(int data);
    void pop();
    int outmax();
private:
    node* topNode;
    int listSize;
    int max;
};


int listStack::outmax() {
    return max;
}
listStack::listStack() {
    topNode = NULL;
    listSize = 0;
    max = 0;
}

bool listStack::empty() {
    if (listSize == 0) {
        return true;
    }
    else { return false; }
}

int listStack::size() {
    return listSize;
}

int listStack::top() {
    if (empty()) {
        return -1;
    }
    return topNode->data;
}

void listStack::push(int data) {
    node* newNode = new node();
    newNode->data = data;
    newNode->next = topNode;
    topNode = newNode;
    listSize++;
}

void listStack::pop() {
    if (max < size()) {
        max = size();
    }
    else {
        max = max;
    }
    if (empty()) {
        return;
    }
    node* curNode = new node();
    curNode = topNode;
    topNode = topNode->next;
    delete curNode;
    listSize--;
}


//isdigit(a[0]) 등 사용해 문자열 스택으로도 풀어보기 

void postfixToinfix(string a) {
    listStack stack;
    for (int i{ 0 }; i < a.size(); i++) {
        if (a[i] == '+' || a[i] == '-') { //연산자라면
            while (!stack.empty()) {
                if (stack.top() == 1) { cout << "+"; }
                if (stack.top() == 2) { cout << "-"; }
                if (stack.top() == 3) { cout << "*"; }

                stack.pop();
            }
            if (a[i] == '+') { stack.push(1); }
            if (a[i] == '-') { stack.push(2); }
        }
        else if (a[i] == '*') {
            while (stack.top() == 3) {
                cout << "*";
                stack.pop();
            }
            stack.push(3);
        }
        else if (a[i] != '(' && a[i] != ')') { //피연산자라면
            cout << a[i];
        }
    }
    while (!stack.empty()) {
        if (stack.top() == 1) { cout << "+"; }
        if (stack.top() == 2) { cout << "-"; }
        if (stack.top() == 3) { cout << "*"; }
        stack.pop();
    }
    cout  << " " << stack.outmax() << endl;;
}

int main() {
    // 중위표기법 -> 후위표기법 출력
    int t{ 0 };
    cin >> t;
    string postFix;
    for (int i{ 0 }; i < t; i++) {
        cin >> postFix;
        postfixToinfix(postFix);
        
    }
}