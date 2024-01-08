#include <bits/stdc++.h>
using namespace std;  

int len, a[200001], num, ret;
stack<int> stk;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> len >> s;
    for (int i=0; i<len; ++i) {
        if (s[i]=='(') stk.push(i);
        else if (!stk.empty()) {
            a[i] = a[stk.top()] = 1;
            stk.pop();
        }
    }

    for (int i=0; i<len; ++i) {
        if (a[i]) ++num, ret = max(ret, num);
        else num=0;
    }

    cout << ret << '\n';


    return 0;
}