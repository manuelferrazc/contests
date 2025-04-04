#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m), sla(32,0);
    for(int &i:a) cin >> i;
    for(int &i:b) cin >> i;
    if(n&1) {
        int x=0;
        for(int i:a) x^=i;
        int o=0;
        for(int i:b) o|=i;
        cout << x << ' ' << (x|o) << '\n';
    } else {
        int x=0;
        for(int i:a) x^=i;
        int mm=0;
        for(int i=0;i<32;i++) if((1<<i)&x) mm=i;
        sort(b.begin(),b.end());
        int o=x;
        for(int i:b) {
            if(i==0) continue;
            
            if(i<=o) o&=(~i);
            else {
                int krl=0;
                for(int i=0;i<32;i++) if((1<<i)&x) krl=i;
                if(krl==mm) {
                    o=o&(~i);
                } else break;
            }
        }
        cout << o << ' ' << x << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
