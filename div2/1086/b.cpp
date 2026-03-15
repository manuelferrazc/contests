#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,k,p,m;
    cin >> n >> k >> p >> m;
    
    list<int> l;
    int c;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        l.push_back(x);
        if(i==p-1) c = x;
    }

    int ans = 0;

    while(m>=0) {
        if(p<=k) {
            if(c>m) break;
            ans++;
            l.push_back(c);
            m-=c;
            auto it = l.begin();
            for(int i=1;i<p;i++) it++;
            p = n;

            l.erase(it);
        } else {
            int mi = l.front();
            auto it = l.begin();
            auto rem = it;
            for(int i=1;i<k;i++) {
                it++;
                if(*it<mi) {
                    mi = *it;
                    rem = it;
                }
            }

            if(m<mi) break;
            m-=mi;
            l.push_back(*rem);
            l.erase(rem);
            p--;
        }
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
