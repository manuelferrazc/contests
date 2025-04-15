#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<vector<int>> adj(1001);
set<int> ans, q;
int tg, cnt;

void dfs(int v, int p=-1) {
    if(tg==cnt) return;

    q.insert(v);
    if(ans.count(v)) cnt++;
    
    for(int u:adj[v]) {
        if(u==p) continue;
        dfs(u,v);
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) ans.insert(i+1);

    for(int emaneru=1;emaneru<n;emaneru++) {
        int gg, cabessa; // sla kkk
        cin >> gg >> cabessa;
        adj[gg].push_back(cabessa);
        adj[cabessa].push_back(gg);
    }

    while(ans.size()>1ULL) {
        tg = ans.size()/2;
        cnt=0;
        q.clear();

        dfs(1);
        cout << "? " << q.size() << ' ';
        for(int i:q) cout << i << ' ';
        cout << '\n';
        cout.flush();
        
        int x;
        cin >> x;
        if(x>=0) {
            auto it = ans.begin();
            while(it!=ans.end()) {
                if(((int)q.count(*it))!=x) {
                    int e = *it;
                    it++;
                    ans.erase(e);
                } else it++;
            }
        } else return 0;
    }

    cout << "! " << *ans.begin() << '\n';
    cout.flush();

    return 0;
}
