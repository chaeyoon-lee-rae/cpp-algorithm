#include <bits/stdc++.h>
using namespace std;  

int t, cnt; 
string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        stack<char> stk;
        cin >> str;
        for (char ch:str) {
            if (stk.size()&&stk.top()==ch)
                stk.pop();
            else stk.push(ch);
        }
        if (stk.empty()) ++cnt;
    }
    cout << cnt << '\n';

    return 0;
}
