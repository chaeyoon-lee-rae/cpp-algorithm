#include <bits/stdc++.h>
using namespace std;  

string s, sub;
int cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;
    for (int i=0; i<s.size(); ++i) {
        bool flag=0;
        if (i+2<s.size()) {
            sub = s.substr(i,3);
            if (sub=="dz=") ++cnt, i+=2, flag=1;
        }
        if (!flag&&i+1<s.size()) {
            sub = s.substr(i,2);
            if (sub=="c="||sub=="c-"||sub=="d-"||sub=="lj"||sub=="nj"||sub=="s="||sub=="z=") ++cnt, ++i, flag=1;
        }
        if (!flag) ++cnt;
    }
    cout << cnt << '\n';

    return 0;
}
