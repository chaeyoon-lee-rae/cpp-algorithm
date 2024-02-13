#include <bits/stdc++.h>
using namespace std;  

int N;
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while (N--) {
        int op; cin >> op;
        switch (op)
        {
        case 1:
            int num; cin >> num;
            stk.push(num); break;
        case 2:
            if (stk.size()) cout << stk.top() << '\n', stk.pop();
            else cout << -1 << '\n'; break;
        case 3:
            cout << stk.size() << '\n'; break;
        case 4:
            cout << (stk.empty() ? 1 : 0) << '\n'; break;
        case 5:
            cout << (stk.size() ? stk.top() : -1) << '\n'; break;
        default: break;
        }
    }    

    return 0;
}
