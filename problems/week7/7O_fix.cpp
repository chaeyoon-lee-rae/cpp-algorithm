#include <bits/stdc++.h>
using namespace std;  

struct stat {int y,x,dir;};
int n, k, turn, a[13][13], dy[]={0,0,-1,1}, dx[]={1,-1,0,0};
vector<int> v[13][13];
vector<stat> s;
bool flag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i=0; i<k; ++i) {
        int y,x,dir; cin >> y >> x >> dir;
        --y; --x; --dir;
        v[y][x].push_back(i);
        s.push_back({y,x,dir});
    }

    while (turn<=1000) {
        ++turn;
        for (int ord=0; ord<k; ++ord) {
            int y=s[ord].y, x=s[ord].x, &dir=s[ord].dir;
            int ny=y+dy[dir], nx=x+dx[dir];
            
            if (ny<0||nx<0||ny>=n||nx>=n||a[ny][nx]==2) {
                dir^=1;
                ny = y+dy[dir]; nx = x+dx[dir];
                if (ny<0||nx<0||ny>=n||nx>=n||a[ny][nx]==2) continue;
            }
            vector<int> &hereV = v[y][x];
            vector<int> &nextV = v[ny][nx];

            auto pos = find(hereV.begin(),hereV.end(),ord);
            if (a[ny][nx]==1) reverse(pos, hereV.end());
            for (auto it=pos; it!=hereV.end(); ++it) {
                nextV.push_back(*it);
                s[*it].y=ny;
                s[*it].x=nx;
            }
            if (nextV.size()>=4) { flag=true; break; }
            hereV.erase(pos, hereV.end());
        }
        if (flag) break;
    }

    cout << (flag ? turn : -1) << '\n';

    return 0;
}
