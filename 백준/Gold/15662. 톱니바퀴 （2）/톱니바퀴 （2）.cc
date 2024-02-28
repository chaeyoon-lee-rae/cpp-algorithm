#include <bits/stdc++.h>
using namespace std;  

int N, K, gearIdx, dir, ret;
bool rot[1001];

void rotateGear(int dir, int idx, vector<vector<bool>> &v) {
    if (dir==1) rotate(v[idx].rbegin(), v[idx].rbegin()+1, v[idx].rend());
    else rotate(v[idx].begin(), v[idx].begin()+1, v[idx].end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d", &N);
    vector<vector<bool>> v(N, vector<bool>(8));
    for (int i=0; i<N; ++i) {
        for (int j=0; j<8; ++j) {
            int temp; scanf("%1d", &temp);
            v[i][j]=temp;
        }
    }
    scanf("%d", &K);
    while(K--) {
        memset(rot, 0, sizeof(rot));
        scanf("%d %d", &gearIdx, &dir);
        --gearIdx;
        for (int i=gearIdx-1; i>=0; --i) {
            if (v[i][2]!=v[i+1][6]) rot[i]=1;
            else break;
        }
        for (int i=gearIdx+1; i<N; ++i) {
            if (v[i][6]!=v[i-1][2]) rot[i]=1;
            else break;
        }
        rotateGear(dir, gearIdx, v);
        
        if (gearIdx%2) dir *= -1; 
        for (int i=0; i<N; ++i) {
            if (i==gearIdx) continue;
            if (rot[i]) rotateGear(dir*(pow(-1,i)), i, v);
        }
    }

    for (auto val:v) ret+=val[0];
    printf("%d\n", ret);

    return 0;
}
