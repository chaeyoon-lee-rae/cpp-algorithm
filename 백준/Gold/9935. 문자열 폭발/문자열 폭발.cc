#include <bits/stdc++.h>
using namespace std;  

string s, rm;
stack<char> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> rm;
    for (int i=0; i<s.size(); ++i) {
        stk.push(s[i]);
        if (stk.size()>=rm.size()&&stk.top()==rm.back()) {
            string temp="";
            for (int j=0; j<rm.size(); ++j) {
                temp+=stk.top(); stk.pop();
            }
            reverse(temp.begin(), temp.end());
            if (temp!=rm) {
                for (char c:temp) stk.push(c);
            }
        }
    }

    if (stk.empty()) cout << "FRULA" << '\n';
    else {
        string ret="";
        while(stk.size()) {
            ret+=stk.top(); stk.pop();
        }
        reverse(ret.begin(), ret.end());
        cout << ret << '\n';
    }

    return 0;
}
