#include <bits/stdc++.h>
using namespace std;  

int N, val;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> s;
        val = 0;
        for (char ch : s) {
            if (ch=='(') val++;
            if (ch==')') val--;
            if (val < 0) break;
        }
        if (val==0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}