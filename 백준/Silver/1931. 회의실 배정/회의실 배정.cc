#include <bits/stdc++.h>
using namespace std;

int from, to, n, idx = 0, ret = 1;  
vector<pair<int, int>> v; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> from >> to;
        v.push_back({to, from}); 
    }
    sort(v.begin(), v.end()); 

    to = v[0].first;   
    for(int i = 1; i < n; i++){
        if(to <= v[i].second) {
            to = v[i].first;
            ret++; 
        }
    } 

    cout << ret << '\n';
    return 0;
}
