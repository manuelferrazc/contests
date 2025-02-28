#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    ll n,c;
    string s;
    cin >> n >> c >> s;

    ll ans=0,l=0,r=-1,a=0,b=0,rud=0;

    while(r<n and l<n) {
        if(l>r) {
            if(s[++r]=='a') a++;
            else if(s[r]=='b') {
                b++;
                rud+=a;
            }
        } else if(rud<=c) {
            ans = max(ans,r-l+1LL);
            r++;
            if(r==n) break;
            if(s[r]=='a') a++;
            else if(s[r]=='b') {
                b++;
                rud+=a;
            }
        } else {
            if(s[l]=='a') {
                rud-=b;
                a--;
            } else if(s[l]=='b') b--;
            l++;
        }
    }

    cout << ans << '\n';

    return 0;
}
