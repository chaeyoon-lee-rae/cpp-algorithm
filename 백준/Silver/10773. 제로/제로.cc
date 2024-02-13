#include <bits/stdc++.h>
using namespace std;  

int k, sum;
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    while (k--) {
        int temp; cin >> temp;
        if (temp) stk.push(temp), sum += temp;
        else sum -= stk.top(), stk.pop(); 
    }
    cout << sum << '\n';

    return 0;
}
