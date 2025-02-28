#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define LOOP 1
#define SAI -1
#define ANALISE 3

int ans=0;
int n, m;

void dfs(vector<string> &v, vector<vector<int>> &s, int i, int j) {
    if((i==0 and v[i][j]=='U') or (i==n-1 and v[i][j]=='D') or (j==0 and v[i][j]=='L') or (j==m-1 and v[i][j]=='R'))
        {s[i][j] = SAI;return;}

    if(v[i][j]=='U') { // vai pra cima
        if(s[i-1][j]==ANALISE) {s[i][j]=LOOP;ans++;}
        else if(v[i-1][j]=='?'){
            ans+=2;
            v[i-1][j] = 'D';
            s[i][j] = s[i-1][j] = LOOP;
        } else {
            if(s[i-1][j]) {
                s[i][j] = s[i-1][j];
                if(s[i][j]==LOOP) ans++;
            } else if (v[i-1][j]=='D') {
                ans += 2;
                s[i-1][j] = s[i][j] = LOOP;
            } else {
                s[i][j] = ANALISE;
                dfs(v,s,i-1,j);
                s[i][j] = s[i-1][j];
                if(s[i][j]==LOOP) ans++;
            }
        }
    } else if(v[i][j]=='D') { // vai pra baixo
        if(s[i+1][j]==ANALISE) {s[i][j]=LOOP;ans++;}
        else if(v[i+1][j]=='?'){
            ans+=2;
            v[i+1][j] = 'U';
            s[i][j] = s[i+1][j] = LOOP;
        } else {
            if(s[i+1][j]) {
                s[i][j] = s[i+1][j];
                if(s[i][j]==LOOP) ans++;
            } else if(v[i+1][j]=='U') {
                ans+=2;
                s[i+1][j]=s[i][j]=LOOP;
            } else {
                s[i][j] = ANALISE;
                dfs(v,s,i+1,j);
                s[i][j] = s[i+1][j];
                if(s[i][j]==LOOP) ans++;
            }
        }
    } else if(v[i][j]=='L') { // vai pra esquerda
        if(s[i][j-1]==ANALISE) {s[i][j]=LOOP;ans++;}
        else if(v[i][j-1]=='?'){
            ans+=2;
            v[i][j-1] = 'R';
            s[i][j] = s[i][j-1] = LOOP;
        } else {
            if(s[i][j-1]) {
                s[i][j] = s[i][j-1];
                if(s[i][j]==LOOP) ans++;
            } else if(v[i][j-1]=='R') {
                ans+=2;
                s[i][j]=s[i][j-1]=LOOP;
            } else {
                s[i][j] = ANALISE;
                dfs(v,s,i,j-1);
                s[i][j] = s[i][j-1];
                if(s[i][j]==LOOP) ans++;
            }
        }
    } else if(v[i][j]=='R') { // vai pra direita
        if(s[i][j+1]==ANALISE) {s[i][j]=LOOP;ans++;}
        else if(v[i][j+1]=='?'){
            ans+=2;
            v[i][j+1] = 'L';
            s[i][j] = s[i][j+1] = LOOP;
        } else {
            if(s[i][j+1]) {
                s[i][j] = s[i][j+1];
                if(s[i][j]==LOOP) ans++;
            } else if(v[i][j+1]=='L') {
                ans+=2;
                s[i][j]=s[i][j+1]=LOOP;
            } else {
                s[i][j] = ANALISE;
                dfs(v,s,i,j+1);
                s[i][j] = s[i][j+1];
                if(s[i][j]==LOOP) ans++;
            }
        }
    }
}

void solve() {
    ans=0;
    cin >> n >> m;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    vector<vector<int>> s(n,vector<int>(m,0));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(v[i][j]!='?' and not s[i][j]) dfs(v,s,i,j);

    pair<int,int> d[4] = {{1,0},{-1,0},{0,1},{0,-1}};
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        if(v[i][j]=='?') {
            for(auto p:d) {
                if(v[i][j]!='?') break;
                int x=i+p.ff,y=j+p.ss;
                if(x>=0 and x<n and y>=0 and y<m) {
                    if(s[x][y]==LOOP) {
                        ans++;
                        s[i][j] = s[x][y];
                        if(x==i+1) v[i][j] = 'D';
                        else if(x) v[i][j] = 'U';
                        else if(y==j+1) v[i][j] = 'R';
                        else v[i][j] = 'L';
                    } else if (v[x][y]=='?') {
                        ans+=2;
                        s[x][y] = s[i][j] = LOOP;
                        if(x==i+1) v[i][j] = 'D',v[x][y] = 'U';
                        else if(x) v[i][j] = 'U', v[x][y] = 'D';
                        else if(y==j+1) v[i][j] = 'R', v[x][y] = 'L';
                        else v[i][j] = 'L', v[x][y] = 'R';
                    }
                }
            }
            if(not s[i][j]) s[i][j] = SAI,v[i][j]='U';
        }
    }
    // for(auto i:v) cout << i << '\n';
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
