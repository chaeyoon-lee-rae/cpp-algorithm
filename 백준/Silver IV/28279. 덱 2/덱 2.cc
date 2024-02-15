#include <bits/stdc++.h>
using namespace std;  

int N, num, temp;
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    while (N--) {
        cin >> num;
        switch (num)
        {
        case 1:
            cin >> temp;
            dq.push_front(temp); break;
        case 2:
            cin >> temp;
            dq.push_back(temp); break;
        case 3:
            if (dq.size()) cout << dq.front() << '\n', dq.pop_front();
            else cout << -1 << '\n'; break;
        case 4:
            if (dq.size()) cout << dq.back() << '\n', dq.pop_back();
            else cout << -1 << '\n'; break;
        case 5:
            cout << dq.size() << '\n'; break;
        case 6:
            cout << (dq.empty() ? 1 : 0) << '\n'; break;
        case 7:
            if (dq.size()) cout << dq.front() << '\n';
            else cout << -1 << '\n'; break;
        case 8:
            if (dq.size()) cout << dq.back() << '\n';
            else cout << -1 << '\n'; break;
        default: break;
        }
    }

    return 0;
}
