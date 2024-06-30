#include <bits/stdc++.h>
using namespace std;  

int n, num, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while(n--) {
        cin >> num; ret=0;
        for(int f=5; f<=num; f*=5) ret+=num/f;
        cout << ret << '\n';
    }

    return 0;
}
