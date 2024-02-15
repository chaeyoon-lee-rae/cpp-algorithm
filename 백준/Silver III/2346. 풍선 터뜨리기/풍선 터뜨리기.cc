#include <bits/stdc++.h>
using namespace std;  

int N, temp;
deque<pair<int,int>> dq;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=1; i<=N; ++i) {
        cin >> temp;
        dq.push_back({i,temp});
    }

    while(dq.size()) {
        int num = dq.front().second;
        v.push_back(dq.front().first);
        dq.pop_front();
        if (num>0) {
            while(--num) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            while(num++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }
    for (int val:v) cout << val << ' ';

    return 0;
}
