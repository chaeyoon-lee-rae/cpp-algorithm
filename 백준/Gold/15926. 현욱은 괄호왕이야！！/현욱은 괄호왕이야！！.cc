#include <bits/stdc++.h>
using namespace std;  

int len, num, ret;
string s;
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> len >> s;
    stk.push(-1);
    for (int i=0; i<len; ++i) {
        if (s[i]=='(') stk.push(i);
        else {
            stk.pop();
            if (stk.size()) {
                ret = max(ret, i - stk.top());
            }
            else stk.push(i);
        }
    }
    cout << ret << '\n';

    return 0;
}