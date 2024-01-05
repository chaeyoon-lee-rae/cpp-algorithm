#include <bits/stdc++.h>
using namespace std;  

int T, num_arr;
string func, arr;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--) {
        cin >> func >> num_arr >> arr;
        int num=0; deque<int> d;
        for (char ch : arr) {
            if (ch=='['||ch==']') continue;
            if (ch>='0'&&ch<='9') num = num*10 + (ch-'0');
            else {
                if (num) d.push_back(num);
                num=0;
            } 
        }
        if (num) d.push_back(num);

        bool flag=0, rev=0;
        for (char ch : func) {
            if (ch=='R') rev = !rev;
            else {
                if (d.empty()) {flag=1; break;}
                if (rev) d.pop_back();
                else d.pop_front();
            }
        }

        if (flag) cout << "error" << '\n';
        else {
            if (rev) reverse(d.begin(),d.end());
            cout << '[';
            for (int i=0; i<d.size(); ++i) {
                cout << d[i];
                if (i<d.size()-1) cout << ',';
            }
            cout << ']' << '\n';
        }
    }

    return 0;
}