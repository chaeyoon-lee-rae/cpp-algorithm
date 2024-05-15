#include <bits/stdc++.h>
using namespace std;  

int a,b,c,d;
map<pair<int,int>,int> mp;
queue<pair<int,int>> q;

void queueOp(int _a, int _b, int cnt) {
    if (mp[{_a,_b}]) return;
    mp[{_a,_b}]=cnt+1;
    q.push({_a,_b});
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c >> d;

    q.push({0,0});
    mp[{0,0}]=1;
    while (q.size()) {
        int _a, _b; 
        tie(_a, _b) = q.front(); q.pop();

        queueOp(_a, b, mp[{_a,_b}]);
        queueOp(a, _b, mp[{_a,_b}]);
        queueOp(_a, 0, mp[{_a,_b}]);
        queueOp(0, _b, mp[{_a,_b}]);
        queueOp(min(_a+_b,a), max(0, _a+_b-a), mp[{_a,_b}]);
        queueOp(max(0, _a+_b-b), min(_a+_b,b), mp[{_a,_b}]);
    }
    
    cout << (mp[{c,d}] ? mp[{c,d}]-1 : -1) << '\n';

    return 0;
}
