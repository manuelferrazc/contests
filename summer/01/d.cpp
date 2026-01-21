#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10;
const int SQ = sqrt(MAX);
int ans;
vector<int> mp(1e6+10); 
vector<int> arr;

inline void insert(int p) { 
    if(mp[arr[p]] == 0) ans ++; 
    mp[arr[p]] += 1;
}

inline void erase(int p){
    if(mp[arr[p]] == 1) ans --;
    mp[arr[p]] -= 1;
}

vector<int> MO(vector<pair<int, int>> &q) {
    ans = 0;
    vector<int> ord(q.size());
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int l, int r) {
        if(q[l].first / SQ != q[r].first /SQ) return q[l].first < q[r].first;
        if((q[l].first/SQ)%2) return q[l].second > q[r].second;
        return q[l].second < q[r].second;
    });


    vector<int> ret(q.size());
    int l = 0, r = -1;
    for(int i : ord) { 
        int ql, qr;
        tie(ql, qr) = q[i];
        while(r < qr) insert(++r);
        while(l > ql) insert(--l);
        while(l < ql) erase(l++);
        while(r > qr) erase(r--);
        ret[i] = ans;
    }
    return ret;
}


int main() {

    int n; cin >> n;
    arr.resize(n);
    for(int& el: arr) cin >> el;
    int q; cin >> q;
    vector<pair<int, int>> queries(q);
    for(auto &[l, r] : queries) cin >> l >> r, l --, r--;

    auto ret = MO(queries);
    for(auto el : ret) cout << el << endl;
}