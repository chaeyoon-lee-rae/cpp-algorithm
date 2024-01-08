#include <bits/stdc++.h>
using namespace std;  

int num, temp;
string s1, s2, ret;
int v1[10001], v2[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s1 >> s2;
    for (int i=0; i<s1.size(); ++i) {
        v1[i]=s1[s1.size()-i-1]-'0';
    }
    for (int i=0; i<s2.size(); ++i) {
        v2[i]=s2[s2.size()-i-1]-'0';
    }

    num = max(s1.size(), s2.size());
    for (int i=0; i<num+1; ++i) {
        if (i==num && temp==0) break;
        temp += v1[i] + v2[i];
        ret += (temp % 10) + '0';
        temp /= 10;
    }

    reverse(ret.begin(), ret.end());
    cout << ret << '\n';

    return 0;
}