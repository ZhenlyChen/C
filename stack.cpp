#include <iostream>
#include <string>
using namespace std;

int main() {
    int caseCount;
    cin >> caseCount;
    while (caseCount--) {
        string str;
        char stack[100];
        int length = 0;
        int flag = 0;
        cin >> str;
        for (int i = 0; i < str.length(); i++) {
            switch (str[i]) {
            case '{':
            case '[':
            case '(':
                stack[length] = str[i];
                length++;
                break;
            case ')':
                if(length == 0 || stack[length - 1] != '(') {
                    flag = 1;
                } else {
                    length--;
                }
                break;
            case ']':
                if(length == 0 || stack[length - 1] != '[') {
                    flag = 1;
                } else {
                    length--;
                }
                break;
            case '}':
                if(length == 0 || stack[length - 1] != '{') {
                    flag = 1;
                } else {
                    length--;
                }
                break;
            default:
                break;
            }
            if(flag) break;
        }
        if(length != 0) flag = 1;
        if(flag){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}
