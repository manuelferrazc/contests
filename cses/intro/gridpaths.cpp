#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool vis[9][9];
string s;
int ans = 0;

void brute(int i, int j, int st, int dir) {
    // cout << i << ' ' << j << '\n';
    // cout << st << '\n';
    if(i==7 and j==1) {
        if(st==49) ans++;
        return;
    }

    if(vis[i+1][j] and vis[i-1][j] and vis[i][j-1] and vis[i][j+1]) return;

    vis[i][j] = true;
    
    bool front = false, rig = false, lef = false;

    if(dir==0) { // vim de cima
        front = vis[i+1][j];
        rig = vis[i][j+1];
        lef = vis[i][j-1];

        if(front and not (rig or lef)) {
            vis[i][j] = false;
            return;
        }

        if((not front) and (s[st-1]=='?' or s[st-1]=='D')) brute(i+1,j,st+1,0);
        if((not lef) and (s[st-1]=='?' or s[st-1]=='L')) brute(i,j-1,st+1,1);
        if((not rig) and (s[st-1]=='?' or s[st-1]=='R')) brute(i,j+1,st+1,2);
    } else if(dir==1) { // vim da direita
        front = vis[i][j-1];
        lef = vis[i+1][j];
        rig = vis[i-1][j];

        if(front and not (rig or lef)) {
            vis[i][j] = false;
            return;
        }

        if((not front) and (s[st-1]=='?' or s[st-1]=='L')) brute(i,j-1,st+1,1);
        if((not lef) and (s[st-1]=='?' or s[st-1]=='D')) brute(i+1,j,st+1,0);
        if((not rig) and (s[st-1]=='?' or s[st-1]=='U')) brute(i-1,j,st+1,3);
    } else if(dir==2) { // vim da esquerda
        front = vis[i][j+1];
        lef = vis[i-1][j];
        rig = vis[i+1][j];

        // cout << front << ' ' << rig << ' ' << lef << '\n';

        if(front and not (rig or lef)) {
            vis[i][j] = false;
            return;
        }

        if((not front) and (s[st-1]=='?' or s[st-1]=='R')) brute(i,j+1,st+1,2);
        if((not lef) and (s[st-1]=='?' or s[st-1]=='U')) brute(i-1,j,st+1,3);
        if((not rig) and (s[st-1]=='?' or s[st-1]=='D')) brute(i+1,j,st+1,0);
    } else { // vim de baixo
        front = vis[i-1][j];
        rig = vis[i][j+1];
        lef = vis[i][j-1];
        // cout << front << ' ' << rig << ' ' << lef << '\n';
        if(front and not (rig or lef)) {
            vis[i][j] = false;
            return;
        }
        
        if((not front) and (s[st-1]=='?' or s[st-1]=='U')) brute(i-1,j,st+1,3);
        if((not lef) and (s[st-1]=='?' or s[st-1]=='L')) brute(i,j-1,st+1,1);
        if((not rig) and (s[st-1]=='?' or s[st-1]=='R')) brute(i,j+1,st+1,2);
    }

    vis[i][j] = false;
}

int main() { _
    for(int i=0;i<9;i++) for(int j=0;j<9;j++) vis[i][j] = i==0 or i==8 or j==0 or j==8;
    
    cin >> s;
    
    vis[1][1] = true;
    
    if(s[0]=='R' or s[0]=='?') brute(1,2,2,2);
    if(s[0]=='D' or s[0]=='?') brute(2,1,2,0);

    cout << ans << '\n';

    return 0;
}
