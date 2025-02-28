#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void clear(map<int,pair<int,int>> &m, vector<int> &v, int &s, int t) {
    for(int i=s;i<=t;i++) {
        m.at(v[i]).ff--;
        if(not m.at(v[i]).ff) m.erase(v[i]);
    }
    s=t+1;
}

int main() { _
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto &i:v) cin >> i;

    map<int,pair<int,int>> m;
    int ans=0,act=0, ap = 0;

    for(int i=0;i<n;i++) {
        if(i!=(n-1) and v[i]==v[i+1]) {
            if(m.count(v[i])) {
                ans = max(ans,act);
                act = i-m.at(v[i]).ss + 1;
                clear(m,v,ap,m.at(v[i]).ss);
                m.insert({v[i],{2,i+1}});
            } else {
                act+=2;
                m.insert({v[i],{2,i+1}});
            }
            i++;
        } else if(i and v[i]==v[i-1]) {
            ans = max(ans,act);
            act=2;
            m.clear();
            ap = i-1;
            m.insert({v[i],{2,i}});
        } else {
            ans = max(ans,act);
            act = 0;
            m.clear();
            ap = i+1;
        }
    }

    ans = max(ans,act);

    cout << ans << '\n';

    return 0;
}
