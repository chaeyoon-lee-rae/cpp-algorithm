#include <bits/stdc++.h>
using namespace std;  

vector<int> tree[11][11];
int a[11][11], nut[11][11], n, m, k, dy[]={-1,-1,-1,0,0,1,1,1}, dx[]={-1,0,1,-1,1,-1,0,1}, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> nut[i][j];
        }
    }
    for (int i=0; i<m; ++i) {
        int y, x, age; cin >> y >> x >> age;
        tree[--y][--x].push_back(age);
    }

    fill(&a[0][0], &a[0][0]+11*11, 5);
    while(k--) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                vector<int> temp; int dead=0;
                sort(tree[i][j].begin(), tree[i][j].end());
                for (int t:tree[i][j]) {
                    if (t > a[i][j]) {
                        dead+=t/2;
                    } else {
                        a[i][j]-=t;
                        temp.push_back(t+1);
                    }
                }
                tree[i][j]=temp;
                a[i][j]+=dead;
            }
        }

        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                for (int t:tree[i][j]) {
                    if (t%5) continue;
                    for (int k=0; k<8; ++k) {
                        int ny=i+dy[k];
                        int nx=j+dx[k];
                        if (ny<0||nx<0||ny>=n||nx>=n) continue;
                        tree[ny][nx].push_back(1);
                    }
                }
            }
        }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                a[i][j]+=nut[i][j];
            }
        }
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            ret+=tree[i][j].size();
        }
    }
    cout << ret << '\n';
    

    return 0;
}
