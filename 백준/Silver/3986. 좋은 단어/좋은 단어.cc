#include <bits/stdc++.h>
using namespace std;  

int N, ret;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while(N--) {
        cin >> s;
        stack<char> stk;
        for (int j=0; j<s.size(); ++j) {
            if (stk.empty()) stk.push(s[j]);
            else {
                if (stk.top()==s[j]) stk.pop();
                else stk.push(s[j]);
            }
        }
        if (stk.empty()) ++ret;
    }
    cout << ret << '\n';

    return 0;
}
