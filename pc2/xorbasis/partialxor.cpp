#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct base {
    vector<ull> s;

    int getdim() {
        return s.size();
    }

    void add(ull mask) {
        for(auto it = s.rbegin();mask and it!=s.rend();it++) {
            mask = min(mask,mask^*it);
        }

        if(mask) {
            auto it = lower_bound(s.begin(), s.end(), mask);
            for(auto it2 = s.rbegin();it2!=s.rend();it2++) {
                if(*it2<mask) break;
                *it2 = min(*it2,mask^*it2);
            }

            s.insert(it, mask);
        }
    }

    ull get(ull k) {
        
        ull ans=0;

        for(ull i=0;i<s.size();i++) {
            ull pos = s.size()-i-1;
            if((1ULL<<pos)<k) {
                ans^=s[pos];
                k-=1ULL<<pos;
            }
        }

        return ans;
    }
};

int main() { _
    ll n,l,r;
    cin >> n >> l >> r;
    base b;

    vector<ull> ans(n);
    for(ull &i:ans) cin >> i;
    sort(ans.begin(),ans.end());
    
    for(ull x:ans) {
        b.add(x);
    }

    for(ull i=l;i<=r;i++) cout << b.get(i) << ' ';
    cout << '\n';

    return 0;
}
