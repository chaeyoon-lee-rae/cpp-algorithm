#include <bits/stdc++.h>
using namespace std;  

string s;
bool flag;
vector<bool> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        getline(cin, s);
        if (s==".") break;

        stack<char> stk;
        flag = false;
        for (char ch : s) {
            if (ch==')') {
                if (stk.empty() || stk.top()=='[') flag=true;
                else stk.pop();
            }
            else if (ch=='(') stk.push(ch);

            else if (ch==']') {
                if (stk.empty() || stk.top()=='(') flag=true;
                else stk.pop();
            }
            else if (ch=='[') stk.push(ch);

            if (flag) break;
        }

        if (flag || stk.size()) v.push_back(false);
        else v.push_back(true);
    }

    for (bool f : v) {
        if (f) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}