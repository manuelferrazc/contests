#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void remove(list<int> &l, int x) {
    for(list<int>::iterator it = l.begin();it!=l.end();it++) if(*it==x) {
        l.erase(it);
        return;
    }
}

list<int> menor(list<int> &l1, list<int> &l2) {
    for(auto it1 = l1.begin(), it2 = l2.begin();
        it1!=l1.end() and it2!=l2.end();
        it1++,it2++) {
            if(*it1<*it2) return l1;
            if(*it2<*it1) return l2;
    }
    return l1;
}

void solve() {
    int n;
    cin >> n;

    vector<int> v[n];
    for(int i=0;i<n;i++) {
        int l;
        cin >> l;
        while(l--) {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }

    list<int> ans;
    ans.push_back(INT_MAX);

    vector<int> p(n);
    for(int i=0;i<n;i++) p[i] = i;

    do {
        list<int> act;
        for(int i=0;i<n;i++) {
            for(ull j=0;j<v[p[i]].size();j++) {
                remove(act,v[p[i]][j]);
                act.push_front(v[p[i]][j]);
            }
        }

        ans = menor(ans,act);
    } while(next_permutation(p.begin(),p.end()));

    while(ans.size()) {
        cout << ans.front() << ' ';
        ans.pop_front();
    }

    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
