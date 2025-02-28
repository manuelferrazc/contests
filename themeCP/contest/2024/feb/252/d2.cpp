#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    list<int> l;
    while(n--) {
        int x;
        cin >> x;
        l.push_back(x);
    }
    
    long long ans=0;
    while(l.size()>1ULL) {
        if(*next(l.rbegin())>*l.rbegin()) {
            auto i = *prev(prev(l.end())),j = *prev(l.end());
            l.pop_back();
            l.pop_back();
            l.push_back(i>>1);
            l.push_back((i>>1)+(i&1));
            l.push_back(j);
            ans++;
        }
        else l.pop_back();
    }
    cout << ans << '\n';

}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    while(n--) solve();
}