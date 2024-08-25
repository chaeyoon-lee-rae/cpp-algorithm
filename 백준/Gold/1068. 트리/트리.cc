#include <bits/stdc++.h>
using namespace std;  

int N, temp, root, rm, ret;
vector<int> v[54];

void dfs(int start) {
    int count=v[start].size();
    for (int there:v[start]) {
        if (rm==there) {count--; continue;}
        dfs(there);
    }
    if (!count) ret++;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> temp;
        if (temp==-1) root=i;
        else v[temp].push_back(i);
    }
    cin >> rm;

    if (rm==root) ret = 0;
    else dfs(root);

    cout << ret << '\n';

    return 0;
}