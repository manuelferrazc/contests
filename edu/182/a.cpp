#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int get(vector<int> &sp, int l, int r) {
    if(l==0) return sp[r];
    return sp[r]-sp[l-1];
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    vector<int> sp(n);
    sp[0] = v[0];
    for(int i=1;i<n;i++) sp[i] = sp[i-1]+v[i];

    for(int l=0;l<n-1;l++) {
        for(int r=l+1;r<n-1;r++) {
            int s[3];
            s[0] = get(sp,0,l)%3;
            s[1] = get(sp,l+1,r)%3;
            s[2] = get(sp,r+1,n-1)%3;

            sort(s,s+3);
            
            if((s[0]==s[2]) or (s[0]==0 and s[1]==1 and s[2]==2)) {
                cout << l+1 << ' ' << r+1 << '\n';
                return;
            }
        }
    }

    cout << 0 << ' ' << 0 << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
