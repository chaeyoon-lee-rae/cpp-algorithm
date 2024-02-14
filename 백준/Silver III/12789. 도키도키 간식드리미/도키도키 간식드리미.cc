#include <bits/stdc++.h>
using namespace std;  

int N;
queue<int> q;
stack<int> stk;
bool flag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        q.push(temp);
    }

    int num=1;
    while(num<=N) {
        if (q.size()&&q.front()==num) q.pop(), ++num;
        else if (stk.size()&&stk.top()==num) stk.pop(), ++num;
        else {
            if (q.size()) stk.push(q.front()), q.pop();
            else ++num;
        } 
    }

    cout << (stk.size() ? "Sad" : "Nice") << '\n';
    
    return 0;
}
