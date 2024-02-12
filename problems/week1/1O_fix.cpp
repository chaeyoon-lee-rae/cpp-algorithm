#include <bits/stdc++.h>
using namespace std;  

int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin>>N) {
        long long t=1; int ret=1;
        while (1) {
            if (t%N==0) {
                cout << ret << '\n';
                break;
            }
            else {
                ++ret;
                t = t*10 + 1;
                t %= N;
            }
        }
    }

    return 0;
}
