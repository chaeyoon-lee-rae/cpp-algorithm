#include <bits/stdc++.h>
using namespace std;  

int x, cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x;
    int i=1, dir=-1, n=2;
    while(--x) {
        if(dir==1) {
            if (n-i==1) {
                ++i, ++n, dir*=-1;
            }
            else i+=dir;
        }
        else if (dir==-1) {
            if (i==1) {
                ++n, dir*=-1;
            }
            else i+=dir;
        }
    }
    cout<< i << '/' << n-i << '\n';


    return 0;
}
