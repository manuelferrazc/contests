#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n,m;
    cin >> n >> m;

    string v[n];
    for(int i=0;i<n;i++) cin >> v[i];
    int qtd[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) qtd[i][j] = 0;

    vector<pair<int,int>> v1,v2;
    vector<pair<int,int>> *pact = &v1, *pnext = &v2;

    const pair<int,int> d[] = {{1,0},{-1,0},{0,1},{0,-1}};
    int ans=0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(v[i][j]=='.') {
                for(auto [a,b]:d) {
                    int x=i+a,y=j+b;
                    if(x<n and x>=0 and y>=0 and y<m and v[x][y]=='#') qtd[i][j]++;
                }
                if(qtd[i][j]==1) {
                    pact->push_back({i,j});
                    ans++;
                    v[i][j] = 'b';
                    qtd[i][j] = 5;
                }
            } else ans++;
        }
    }


    while(pact->size()) {
        for(auto [i,j]:*pact) { // célula branca q virou preta
            for(auto [a,b]:d) { // branca candidata a virar preta
                int x=i+a,y=j+b;
                if(x<n and x>=0 and y>=0 and y<m and v[x][y]=='.') {
                    if(qtd[x][y]>4) continue;
                    qtd[x][y]++;
                }
            }
        }

        for(auto [i,j]:*pact) {
            for(auto [a,b]:d) {
                int x=i+a,y=j+b;
                if(x<n and x>=0 and y>=0 and y<m and v[x][y]=='.' and qtd[x][y]==1) {
                    pnext->push_back({x,y});
                    qtd[x][y] = 100;
                    ans++;
                    v[x][y] = 'b';
                }
            }
        }

        pact->clear();
        swap(pact,pnext);
    }


    cout << ans << '\n';

    return 0;
}
