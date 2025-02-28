#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define x first
#define y second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

bool is_inside(pii const &p1,pii const &p2,pii const &r) {
    return p1.x<=r.x and r.x <=p2.x/* and min(p1.y,p2.y)<=r.y and r.y<=max(p1.y,p2.y)*/;
}

int main() { _
    int n, ans = 0;
    cin >> n;

    vector<pii> v(n);
    for(int i=0;i<n;i++) cin >> v[i].x >> v[i].y;

    sort(v.begin(),v.end());

    for(int i=0;i<n-1;i++) {
        vb vi(n,true);

        for(int j = i+1;j<n;j++) {
            if(!vi[j]) continue;
            ans++;

            for(int k = j+1;k<n;k++) 
                if(vi[k] and min(v[i].y,v[k].y)<=v[j].y and v[j].y<=max(v[i].y,v[k].y)) vi[k] = !is_inside(v[i], v[k], v[j]);
        }
    }

    cout << ans << '\n';
    return 0;
}
