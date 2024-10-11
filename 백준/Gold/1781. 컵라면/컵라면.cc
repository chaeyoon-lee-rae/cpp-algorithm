#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, day, ramen, ret;
vector<int> v[200001];
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> day >> ramen;
        v[day].push_back(ramen);
    }

    for (int i = n; i >= 1; --i) {
        for (int r : v[i]) 
            pq.push(r);
        if (pq.size())
            ret += pq.top(), pq.pop();
    }
    
    cout << ret << "\n";

    return 0;
}
