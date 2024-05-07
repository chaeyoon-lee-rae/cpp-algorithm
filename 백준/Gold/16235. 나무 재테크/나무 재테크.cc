#include <bits/stdc++.h>
using namespace std;  

vector<int> land[11][11];
int n, m, k, a[11][11], nutri[11][11], x, y, z, ret,
dy[]={0,-1,-1,-1,0,1,1,1}, dx[]={-1,-1,0,1,1,1,0,-1};

void springSummer(int y, int x) {
    sort(land[y][x].begin(), land[y][x].end());
    int &nut=nutri[y][x], dead=0, i;
    for (i=0; i<land[y][x].size(); ++i) {
        int &age=land[y][x][i]; 
        if (nut<age) break;
        else nut-=age, age++;
    }
    for (int j=i; j<land[y][x].size(); ++j) {
        dead+=land[y][x][j]/2;
    }
    nutri[y][x]+=dead;
    land[y][x].erase(land[y][x].begin()+i, land[y][x].end());
}

void fall(int y, int x) {
    for (int age:land[y][x]) {
        if (!(age%5)) {
            for (int i=0; i<8; ++i) {
                int ny=y+dy[i];
                int nx=x+dx[i];
                if (ny<0||nx<0||ny>=n||nx>=n) continue;
                land[ny][nx].push_back(1);
            }
        }
    }
}

void winter() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            nutri[i][j]+=a[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&nutri[0][0], &nutri[0][0]+11*11, 5);

    cin >> n >> m >> k;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i=0; i<m; ++i) {
        cin >> y >> x >> z;
        land[--y][--x].push_back(z);
    }

    while(k--) {
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (land[i][j].size()) springSummer(i, j);
            }
        }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (land[i][j].size()) fall(i, j);
            }
        }
        winter();
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            ret+=land[i][j].size();
        }
    }
    cout << ret << '\n';

    return 0;
}
