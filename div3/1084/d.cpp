#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,x,y;
    cin >> n >> x >> y;

    int v[n+1];
    for(int i=1;i<=n;i++) cin >> v[i];

    deque<int> out,bet;
    for(int i=1;i<=x;i++) out.push_back(v[i]);
    for(int i=y+1;i<=n;i++) out.push_back(v[i]);
    for(int i=x+1;i<=y;i++) bet.push_back(v[i]);

    int mi2 = INT_MAX;
    for(int i=0;i<bet.size();i++) {
        if(bet[i]<mi2) 
            mi2 = bet[i];
    }

    
    while(bet.size() and bet.front()!=mi2) {
        bet.push_back(bet.front());
        bet.pop_front();
    }
    
    while(out.size() and (bet.empty() or out.front()<bet.front())) {
        cout << out.front() << ' ';
        out.pop_front();
    }

    while(bet.size()) {
        cout << bet.front() << ' ';
        bet.pop_front();
    }

    while(out.size()) {
        cout << out.front() << ' ';
        out.pop_front();
    }

    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
