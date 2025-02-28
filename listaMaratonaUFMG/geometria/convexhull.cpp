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

int orientacao(pii &p1, pii &p2, pii &p3) {
    return ((p2.x-p1.x)*(p3.y-p1.y) - (p2.y-p1.y)*(p3.x-p1.x));
}

void unique(vector<pii> &v) {
    set<pii> s;
    vector<pii> aux;
    for(auto i:v) {
        if(s.count(i)) continue;
        s.insert(i);
        aux.push_back(i);
    }
    v.clear();
    v = aux;
}

void solve(int n) {
    vector<pii> v(n);
    for(int i=0;i<n;i++) cin >> v[i].x >> v[i].y;

    sort(v.begin(),v.end());
    unique(v);

    vector<pii> ans, st;

    for(int i=0;i<n;i++) {
        while(st.size()>1 and orientacao(st[st.size()-2], st.back(), v[i])<=0) st.pop_back();
        st.push_back(v[i]);
    }

    for(auto i:st) ans.push_back(i);

    reverse(v.begin(),v.end());
    st.clear();

    for(int i=0;i<n;i++) {
        while(st.size()>1 and orientacao(st[st.size()-2], st.back(), v[i])<=0) st.pop_back();
        st.push_back(v[i]);
    }

    for(auto i:st) ans.push_back(i);

    unique(ans);

    cout << ans.size() << '\n';
    for(auto i : ans) cout << i.x << ' ' << i.y << '\n';
}

int main() { _
    int n;
    cin >> n;

    while(n) {solve(n);cin>>n;}

    return 0;
}
