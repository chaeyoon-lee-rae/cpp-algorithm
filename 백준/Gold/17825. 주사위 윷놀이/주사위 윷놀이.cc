#include <bits/stdc++.h>
using namespace std;  

int board[33], dir[33], dice[10], blueDir[33], ret, horse[4];
bool vis[33];

void go(int cnt, int sum) {
    if (cnt==10) {
        ret = max(ret, sum);
        return;
    }
    for (int i=0; i<4; ++i) {
        if (horse[i]<32) {
            int here=0; int org=horse[i];
            if (blueDir[horse[i]]) here=blueDir[horse[i]];
            else here=dir[horse[i]];
            for (int i=0; i<dice[cnt]-1 && here<32; ++i) here=dir[here];
            if (here<32 && vis[here]) continue;
            horse[i]=here; vis[here]=1; vis[org]=0;
            go(cnt+1, sum+board[here]);
            horse[i]=org; vis[here]=0; vis[org]=1;
        }
    }
}

void boardSet() {
    for (int i=1; i<=19; ++i) {
        board[i]=i*2;
        dir[i-1]=i;
    }
    blueDir[5]=20;
    blueDir[10]=23;
    blueDir[15]=25;
    
    dir[19]=31; 
    dir[20]=21; dir[21]=22; dir[22]=28; dir[23]=24; 
    dir[24]=28; dir[25]=26; dir[26]=27; dir[27]=28; 
    dir[28]=29; dir[29]=30; dir[30]=31; dir[31]=32;
    board[20]=13; board[21]=16; board[22]=19; board[23]=22; 
    board[24]=24; board[25]=28; board[26]=27; board[27]=26; 
    board[28]=25; board[29]=30; board[30]=35; board[31]=40;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    boardSet();
    for (int i=0; i<10; ++i) {
        scanf("%d", &dice[i]);
    }
    go(0,0);
    printf("%d\n", ret);

    return 0;
}
