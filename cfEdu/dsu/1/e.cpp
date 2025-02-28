#include <any>
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
#define left 1
#define right 2
typedef long long ll;
typedef unsigned long long ull;

int get(vector<int> &p, int a) {
    return p[a] = (p[a]==a ? a : get(p,p[a]));
}

void Union(vector<vector<int>> &v, vector<int> &ans, vector<int> &p, vector<int> &size, int second, int a, int b) {
    a = get(p,a);
    b = get(p,b);
    if(a==b) return;
    
    if(size[b]>size[a]) swap(a, b);
    int root = get(p,0);
    if(a==root) {
        for(auto i:v[b]) ans[i] = second;
    } else if(b==root) {
        for(auto i:v[a]) ans[i] = second;
    }

    size[a]+=size[b];
    for(auto i:v[b]) v[a].push_back(i);
    v[b].clear();
    p[b] = a;
}

int main() { _
    int n,m;
    cin >> n >> m;

    vector<pair<int,int>> monkeys(n);
    
    for(auto &i: monkeys) {
        cin >> i.ff >> i.ss;
        if(i.ff!=-1) i.ff--;
        if(i.ss!=-1) i.ss--;
    }
    vector<int> ans(n,-1), size(n,1), p(n);
    vector<vector<int>> v(n);
    for(int i=0;i<n;i++) {
        p[i] = i;
        v[i].push_back(i);
    }
    
    vector<pair<bool,bool>> releases(n,make_pair(false,false));
    vector<pair<int,int>> queries(m);

    for(auto &i:queries) {
        cin >> i.ff >> i.ss;
        i.ff--;
        if(i.ss==left) releases[i.ff].ff = true;
        else releases[i.ff].ss = true;
    }
    
    
    for(int i=0;i<n;i++) {
        if((not releases[i].ff) and monkeys[i].ff!=-1) 
            Union(v,ans,p,size,-1,i,monkeys[i].ff);

        if((not releases[i].ss) and monkeys[i].ss!=-1) 
            Union(v,ans,p,size,-1,i,monkeys[i].ss);
    }
    
    for(int i=m-1;i>=0;i--) {
        if(queries[i].ss==left) Union(v,ans,p,size,i,queries[i].ff,monkeys[queries[i].ff].ff);
        else Union(v,ans,p,size,i,queries[i].ff,monkeys[queries[i].ff].ss);
    }

    for(auto i:ans) cout << i << '\n';

    return 0;
}
