#include <bits/stdc++.h>
using namespace std;  

int N;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin>>s) {
        if (s.size()) ++N;
    }
    cout << N << '\n';
    

    return 0;
}
