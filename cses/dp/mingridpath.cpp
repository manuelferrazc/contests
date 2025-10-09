#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n;
    cin >> n;

    string v[n];
    for(int i=0;i<n;i++) cin >> v[i];

    if(n==1) {
        cout << v[0][0] << '\n';
        return 0;
    }

    string ans;
    ans.push_back(v[0][0]);

    vector<pair<int,int>> m[26];
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    m[v[0][1]-'A'].push_back({0,1});
    m[v[1][0]-'A'].push_back({1,0});
    
    for(int d=1;d<=2*n-2;d++) {
        vector<pair<int,int>> st;

        for(int i=0;i<26;i++) {
            if(m[i].size()) {
                st = m[i];
                ans.push_back((char)(i+'A'));
                break;
            }
        }

        for(int i=0;i<26;i++) m[i].clear();

        for(int i=0;i<=1;i++) {
            for(auto [x,y]:st) {
                x+=i;
                y+=1-i;

                if(x<n and y<n and not vis[x][y]) {
                    m[v[x][y]-'A'].push_back({x,y});
                    vis[x][y] = true;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
