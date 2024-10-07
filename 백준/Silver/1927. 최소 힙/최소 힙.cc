#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    int x;
    while (n--) {
        cin >> x;
        if (x) {
            pq.push(x);
        }
        else {
            if (pq.size()) {
                cout << pq.top() << "\n";
                pq.pop();
            }
            else
                cout << 0 << "\n";
        }
    }

    return 0;
}
