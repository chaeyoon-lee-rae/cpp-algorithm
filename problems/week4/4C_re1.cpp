#include <bits/stdc++.h>
using namespace std;  

const int INF=1e6;
int N, pop[11], ret=INF, gary[11];
vector<vector<int>> v;
bool visited[11];

int calcPop(vector<int> v) {
    int sum=0;
    for (int val:v) sum+=pop[val];
    return sum;
}

void go(int here, int num) {
    visited[here]=1;
    for (int val:v[here]) {
        if (!visited[val]&&gary[val]==num) go(val, num);
    }
    return;
}

bool check(vector<int> &v) {
    memset(visited, 0, sizeof(visited));
    go(v[0], gary[v[0]]);
    for (int val: v) {
        if (visited[val]==0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> pop[i];
    }
    for (int i=0; i<N; ++i) {
        int temp; cin >> temp;
        vector<int> vTemp;
        for (int j=0; j<temp; ++j) {
            int num; cin >> num; --num;
            vTemp.push_back(num);
        }
        v.push_back(vTemp);
    }

    for (int i=1; i<(1<<N)-1; ++i) {
        vector<int> v1, v2;
        memset(gary, 0, sizeof(gary));
        for (int j=0; j<N; ++j) {
            if (i&(1<<j)) v1.push_back(j), gary[j]=1;
            else v2.push_back(j);
        }
        if (check(v1)&&check(v2)) {
            ret = min(ret, abs(calcPop(v1)-calcPop(v2)));
        }
    }
    cout << (ret==INF ? -1 : ret) << '\n';

    return 0;
}
