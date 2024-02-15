#include <bits/stdc++.h>
using namespace std;  

deque<int> dq;
int N, M, temp;
bool a[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> a[i];
    }
    for (int i=0; i<N; ++i) {
        cin >> temp;
        if (!a[i]) dq.push_front(temp);
    }
    cin >> M;
    while (M--) {
        cin >> temp;
        dq.push_back(temp);
        cout << dq.front() << ' ';
        dq.pop_front();
    }
    
    return 0;
}
