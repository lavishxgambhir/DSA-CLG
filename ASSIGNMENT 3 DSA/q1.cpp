#include <iostream>
using namespace std;

class stimp {
    int st[10];
    int current;  
public:
    stimp() : current(-1) {}   

    int top() {
        if (current == -1) {
            cout << "Stack is empty!" << endl;
            return -1;  
        }
        return st[current];
    }

    void push(int x) {
        if (current == 9) { 
            cout << "Stack is full!" << endl;
        } else {
            st[++current] = x;
        }
    }

    void pop() {
        if (current == -1) {
            cout << "There is no element in the stack to pop!" << endl;
        } else {
            current--;
        }
    }

    int size() {
        return current + 1;
    }

    bool empty() {
        return current == -1;
    }
};

int main() {
    stimp st;
    st.push(100);
    st.push(5);
    cout << "Top: " << st.top() << endl;
    st.pop();
    cout << "Top after pop: " << st.top() << endl;
    return 0;
}
