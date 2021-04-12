#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack<int> s(1);
    for (int i = 0; i < 5; ++i){
        s.push(i);
    }
    while (!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}